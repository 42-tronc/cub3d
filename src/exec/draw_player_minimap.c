/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:58:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 12:17:37 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *minimap, float x, float y)
{
	float				cut;
	t_vector_float		pos;

	pos.x = x * SIZE_MAP;
	pos.y = y * SIZE_MAP;
	cut = SIZE_MAP / SIZE_PLAYER;
	while ((pos.x + cut) < (x * SIZE_MAP) + SIZE_MAP)
	{
		pos.y = y * SIZE_MAP;
		while ((pos.y + cut) < (y * SIZE_MAP) + SIZE_MAP)
		{
			put_pixel(minimap, pos.y, pos.x, MAP_PLAYER);
			pos.y++;
		}
		pos.x++;
	}
}
