/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 10:03:04 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_textures(t_data *data, t_ray *ray, int count, int i);

void    draw_walls(t_data *data, t_ray *ray, int width)
{
	int			i;
	float		wall_height;
	
	i = 0;
	if (ray->length <= 0)
		ray->length = MIN_LEN_RAY;
	wall_height = WALL_H / ray->length;
	while (i < (HEIGHT / 2) - (wall_height / 2))
	{
		put_pixel(&data->minimap, abs(width), i, BLUE_HEX);
		i++;
	}
	while (i < (HEIGHT / 2) + (wall_height / 2))
	{
		get_textures(data, ray, abs(width), i);
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, abs(width), i, GREY_HEX);
		i++;
	}
}

static void	get_textures(t_data *data, t_ray *ray, int count, int i)
{
	if (ray->cardinal == NORTH)
		put_pixel(&data->minimap, abs(count), i, W_WHITE);
	if (ray->cardinal == SOUTH)
		put_pixel(&data->minimap, abs(count), i, E_GREEN);
	if (ray->cardinal == WEST)
		put_pixel(&data->minimap, abs(count), i, S_BROWN);
	if (ray->cardinal == EAST)
		put_pixel(&data->minimap, abs(count), i, N_RED);
}