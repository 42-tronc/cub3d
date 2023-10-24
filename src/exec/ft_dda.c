/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:29:21 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 10:21:29 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void get_side(t_ray *ray);
static void get_ray_length(t_ray *ray);
static int is_wall(t_data *data, t_ray *ray);

void    ft_dda(t_data *data, t_ray *ray, t_vector_float direction)
{
	(void)direction;
	while (is_wall(data, ray) == SUCCESS)
	{
		// printf("data->player_pos.x = %f\n", data->player_pos.x);
		// printf("data->player_pos.y = %f\n", data->player_pos.y);
		get_side(ray);
		get_ray_length(ray);
	}
}

static void get_side(t_ray *ray)
{
	if (ray->dist_to_wall.x < ray->dist_to_wall.y)
	{
		ray->dist_to_wall.x += ray->delta.x;
		ray->map_pos.x += ray->step.x;
		// if (ray->map_pos.x <= 0)
		// 	ray->map_pos.x = 1;
		if (ray->step.x == 1)
			ray->cardinal = EAST;
		else
			ray->cardinal = WEST;
	}
	else
	{
		ray->dist_to_wall.y += ray->delta.y;
		ray->map_pos.y += ray->step.y;
		// if (ray->map_pos.x <= 0)
		// 	ray->map_pos.x = 1;
		if (ray->step.y == 1)
			ray->cardinal = NORTH;
		else
			ray->cardinal = SOUTH;
	}
}

static void get_ray_length(t_ray *ray)
{
	if (ray->cardinal == EAST || ray->cardinal == WEST)
		ray->length = ray->dist_to_wall.x - ray->delta.x;
	else
		ray->length = ray->dist_to_wall.y - ray->delta.y;
}

static int is_wall(t_data *data, t_ray *ray)
{
	if (data->map->array[ray->map_pos.x][ray->map_pos.y] && \
			data->map->array[ray->map_pos.x][ray->map_pos.y] != '1')
		return (SUCCESS);
	return (FAILURE);
}