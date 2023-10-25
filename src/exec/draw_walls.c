/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 16:25:03 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_textures(t_data *data, t_ray *ray, int count, int i);

void	draw_walls(t_data *data, t_ray *ray, int width)
{
	int			i;
	float		wall_height;

	i = 0;
	if (ray->length < MIN_LEN_RAY)
		ray->length = MIN_LEN_RAY;
	wall_height = WALL_H / ray->length;
	while (i < (HEIGHT / 2) - (wall_height / 2))
	{
		put_pixel(&data->minimap, abs(width), i, data->ceiling);
		i++;
	}
	while (i < (HEIGHT / 2) + (wall_height / 2))
	{
		get_textures(data, ray, abs(width), i);
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, abs(width), i, data->floor);
		i++;
	}
}

static void	get_textures(t_data *data, t_ray *ray, int count, int i)
{
	if (ray->cardinal == NORTH)
	{
		put_pixel(&data->minimap, abs(count), i, W_WHITE);
		// draw_textures(data, count, i);
	}
	if (ray->cardinal == SOUTH)
	{
		put_pixel(&data->minimap, abs(count), i, 0xEE82EE);
		// draw_textures(data, count, i);
	}
	if (ray->cardinal == WEST)
	{
		put_pixel(&data->minimap, abs(count), i, S_BROWN);
		// draw_textures(data, count, i);
	}
	if (ray->cardinal == EAST)
		put_pixel(&data->minimap, abs(count), i, N_RED);
	{
		// draw_textures(data, count, i);
	}
}
