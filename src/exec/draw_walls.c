/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/26 14:00:34 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_textures(t_data *data, t_ray *ray, int y, int x, int tex_y);

void	draw_walls(t_data *data, t_ray *ray, int width)
{
	int			i;
	int			tex_y;
	float		wall_height;

	i = 0;
	tex_y = 0;
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
		get_textures(data, ray, abs(width), i, tex_y);
		tex_y++;
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, abs(width), i, data->floor);
		i++;
	}
}

static void	get_textures(t_data *data, t_ray *ray, int y, int x, int tex_y)
{
	char *dst;

	dst = NULL;
	if (ray->cardinal == NORTH)
	{
		dst = draw_textures(data, ray, tex_y);
		put_pixel(&data->minimap, abs(y), x, *(unsigned int *)dst);
	}
	if (ray->cardinal == SOUTH)
	{
		dst = draw_textures(data, ray, tex_y);
		put_pixel(&data->minimap, abs(y), x, *(unsigned int *)dst);
	}
	if (ray->cardinal == WEST)
	{
		dst = draw_textures(data, ray, tex_y);
		put_pixel(&data->minimap, abs(y), x, *(unsigned int *)dst);
	}
	if (ray->cardinal == EAST)
	{
		dst = draw_textures(data, ray, tex_y);
		put_pixel(&data->minimap, abs(y), x, *(unsigned int *)dst);
	}
}
