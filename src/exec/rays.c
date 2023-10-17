/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:28:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/17 16:33:47 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	center_player(float fl);

void	rays(t_exec *exec, float x, float y)
{
	int 				count = 0;
	float				angle = 0;
	float				tmp = 0;
	t_vector_float		rot;

	while (count < N_RAYS)
	{
		angle = ((2 * PI / N_RAYS) * count) / 15;
		rot.x = (x * SIZE_MAP) + center_player(x);
		rot.y = (y * SIZE_MAP) + center_player(y);
		while (exec->map[(int)(rot.x / SIZE_MAP)][(int)(rot.y / SIZE_MAP)] != '1')
		{
			if (count % 2)
			{
				rot.x += exec->player_pos.dx * cos(angle) - exec->player_pos.dy * sin(angle);
				rot.y += exec->player_pos.dx * sin(angle) + exec->player_pos.dy * cos(angle);
				tmp = angle;
			}
			else
			{
				rot.x += exec->player_pos.dx * cos(-tmp) - exec->player_pos.dy * sin(-tmp);
				rot.y += exec->player_pos.dx * sin(-tmp) + exec->player_pos.dy * cos(-tmp);
			}
			put_pixel(&exec->minimap, rot.y, rot.x, RED_HEX);
		}
		count++;
	}
	//dda(exec);
}

static float	center_player(float fl)
{
	float	player_center;

	player_center = fl + (SIZE_MAP / (SIZE_CUT * 3));
	return (player_center);
}





