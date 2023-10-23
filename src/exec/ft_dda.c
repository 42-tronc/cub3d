/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:29:21 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 09:54:35 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_wall(t_data *data, t_ray *ray);
static void get_side(t_ray *ray);

void    ft_dda(t_data *data, t_ray *ray, t_vector_float direction)
{
    while (is_wall(data, ray) == FAILURE)
    {
        get_side(ray);
        get_ray_length(data, ray);
    }
}

static int is_wall(t_data *data, t_ray *ray)
{
    if (data->map->array[ray->map_pos.x][ray->map_pos.y] && \
            data->map->array[ray->map_pos.x][ray->map_pos.y] != '1')
        return (SUCCESS);
    return (FAILURE);
}

static void get_side(t_ray *ray)
{
    if (ray->dist_to_wall.x < ray->dist_to_wall.y)
    {
        ray->dist_to_wall.x += ray->delta.x;
        ray->map_pos.x += ray->step.x;
        if (ray->step.x == 1)
            ray->cardinal = EAST;
        else
            ray->cardinal = WEST;
    }
    else
    {
        ray->dist_to_wall.y += ray->delta.y;
        ray->map_pos.y += ray->step.y;
        if (ray->step.y == 1)
            ray->cardinal = NORTH;
        else
            ray->cardinal = SOUTH;
    }
}

static void get_ray_length(t_data *data, t_ray *ray)
{


}

	if (ray->side == EAST || ray->side == WEST)
	{
		ray->length = ray->side_dist.x - ray->delta_dist.x;
		ray->collision.x = (((data.p_pos_y / TILE_SIZE) \
			- ((int)data.p_pos_y / TILE_SIZE)) + ray->length * d_y);
	}
