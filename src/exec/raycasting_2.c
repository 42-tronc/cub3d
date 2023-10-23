/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/21 14:43:57 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_rays(t_data *data, t_vector_float *rot, float angle);
static float	center_player(float fl);

void	raycasting_2(t_data *data, float x, float y)
{
	int 				count = N_RAYS;
	float				total_angle = ((2 * PI / N_RAYS) * N_RAYS) / FOV;
	float				angle = -total_angle;
	t_vector_float		rot;

	while (angle < total_angle)
	{
		angle = ((2 * PI / N_RAYS) * -count) / FOV;
		rot.x = (x * SIZE_WALL) + center_player(x);
		rot.y = (y * SIZE_WALL) + center_player(y);
		while (data->map->array[(int)(rot.x / SIZE_WALL)][(int)(rot.y / SIZE_WALL)] != '1')
			draw_rays(data, &rot, angle);
		count--;
		//draw_walls(data, rot, count);
	}
}

static void		draw_rays(t_data *data, t_vector_float *rot, float angle)
{
	rot->x += data->player_pos.dx * cos(angle) - data->player_pos.dy * sin(angle);
	rot->y += data->player_pos.dx * sin(angle) + data->player_pos.dy * cos(angle);

	//put_pixel(&data->minimap, rot->y, rot->x, RED_HEX);
}

static float	center_player(float fl)
{
	float	player_center;

	player_center = fl + (SIZE_WALL / (SIZE_CUT * 3));
	return (player_center);
}
