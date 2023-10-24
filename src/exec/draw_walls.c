/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 13:51:09 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_walls(t_data *data, int count, t_ray ray)
{
	int			i;
	float		wall_height;
	
	i = 0;
	wall_height = WALL_H / ray.length;
	if (wall_height < -200000)
		return ;
	while (i < (HEIGHT / 2) - (wall_height / 2))
	{
		put_pixel(&data->minimap, abs(count), i, BLUE_HEX);
		i++;
	}
	while (i < (HEIGHT / 2) + (wall_height / 2))
	{
		if (ray.cardinal == NORTH)
			put_pixel(&data->minimap, abs(count), i, W_WHITE);
		if (ray.cardinal == SOUTH)
			put_pixel(&data->minimap, abs(count), i, E_GREEN);
		if (ray.cardinal == WEST)
			put_pixel(&data->minimap, abs(count), i, S_BROWN);
		if (ray.cardinal == EAST)
			put_pixel(&data->minimap, abs(count), i, N_RED);

		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, abs(count), i, GREY_HEX);
		i++;
	}
}