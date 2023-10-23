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

static void		draw_rays(t_exec *exec, t_vector_float *rot, float angle);
static float	center_player(float fl);

void	raycasting_2(t_exec *exec, float x, float y)
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
		while (exec->map[(int)(rot.x / SIZE_WALL)][(int)(rot.y / SIZE_WALL)] != '1')
			draw_rays(exec, &rot, angle);
		count--;
		//draw_walls(exec, rot, count);
	}
}

static void		draw_rays(t_exec *exec, t_vector_float *rot, float angle)
{
	rot->x += exec->player_pos.dx * cos(angle) - exec->player_pos.dy * sin(angle);
	rot->y += exec->player_pos.dx * sin(angle) + exec->player_pos.dy * cos(angle);

	//put_pixel(&exec->minimap, rot->y, rot->x, RED_HEX);
}

static float	center_player(float fl)
{
	float	player_center;

	player_center = fl + (SIZE_WALL / (SIZE_CUT * 3));
	return (player_center);
}