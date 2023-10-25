/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:29:21 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 16:22:37 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_side(t_ray *ray);
static void	get_ray_length(t_ray *ray);
static int	is_wall(t_data *data, t_ray *ray);

void	ft_dda(t_data *data, t_ray *ray)
{
	while (is_wall(data, ray) == SUCCESS)
	{
		get_side(ray);
		get_ray_length(ray);
	}
}

static void	get_side(t_ray *ray)
{
	if (ray->dist_to_wall.x < ray->dist_to_wall.y)
	{
		ray->dist_to_wall.x += ray->delta.x;
		ray->map_pos.x += ray->step.x;
		if (ray->step.x == 1)
			ray->cardinal = WEST;
		else
			ray->cardinal = EAST;
	}
	else
	{
		ray->dist_to_wall.y += ray->delta.y;
		ray->map_pos.y += ray->step.y;
		if (ray->step.y == 1)
			ray->cardinal = SOUTH;
		else
			ray->cardinal = NORTH;
	}
}

static void	get_ray_length(t_ray *ray)
{
	if (ray->cardinal == EAST || ray->cardinal == WEST)
		ray->length = ray->dist_to_wall.x - ray->delta.x;
	else
		ray->length = ray->dist_to_wall.y - ray->delta.y;
}

static int	is_wall(t_data *data, t_ray *ray)
{
	if (data->map->array[ray->map_pos.x][ray->map_pos.y] && \
			data->map->array[ray->map_pos.x][ray->map_pos.y] != '1')
		return (SUCCESS);
	return (FAILURE);
}
