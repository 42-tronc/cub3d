/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 09:04:16 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    draw_walls(t_data *data, t_vector_float rot, int count)
// {
// 	(void)exec;
// 	(void)rot;
// 	(void)count;
// }

/* void    draw_walls(t_data *data, int count, t_ray ray)
{
	ray.wall_height = WALL_H / ray.wall_dist;

	int i = 0;

	if (ray.wall_height < -200000)
		return ;
	while (i < 500 - (ray.wall_height / 2))
	{
		put_pixel(&data->minimap, abs(count), i, BLUE_HEX);
		i++;
	}
	while (i < 500 + (ray.wall_height / 2))
	{
		put_pixel(&data->minimap, abs(count), i, GREEN_HEX);
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, abs(count), i, GREY_HEX);
		i++;
	}
} */
