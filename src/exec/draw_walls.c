/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/21 14:54:31 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    draw_walls(t_exec *exec, t_vector_float rot, int count)
// {
// 	(void)exec;
// 	(void)rot;
// 	(void)count;
// }

void    draw_walls(t_exec *exec, int count, t_ray ray)
{
	ray.wall_height = WALL_H / ray.wall_dist;

	int i = 0;
	
	if (ray.wall_height < -200000)
		return ;
	while (i < 500 - (ray.wall_height / 2))
	{
		put_pixel(&exec->minimap, abs(count), i, BLUE_HEX);
		i++;
	}
	while (i < 500 + (ray.wall_height / 2))
	{
		put_pixel(&exec->minimap, abs(count), i, GREEN_HEX);
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&exec->minimap, abs(count), i, GREY_HEX);
		i++;
	}
}