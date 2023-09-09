/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:58:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 15:34:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_minimap(t_data *minimap, float x, float y)
{
	t_vector_float		pos;
	float				cut;

	cut = SIZE_MAP / SIZE_CUT;
	pos.x = (x * SIZE_MAP);
	pos.y = (y * SIZE_MAP);
	while ((pos.x) < (x * SIZE_MAP) + cut)
	{
		pos.y = y * SIZE_MAP;
		while ((pos.y) < (y * SIZE_MAP) + cut)
		{
			put_pixel(minimap, pos.y, pos.x, MAP_PLAYER);
			pos.y++;
		}
		pos.x++;
	}
}

// void	draw_player_minimap(t_data *minimap, float x, float y)
// {
// 	t_vector_float		pos;
// 	t_vector_float		tmp;
// 	float				cut;

// 	cut = SIZE_MAP / SIZE_CUT;
	
// 	pos.x = (x * SIZE_MAP);
// 	pos.y = (y * SIZE_MAP);

// 	tmp.x = pos.x + (SIZE_MAP / 2);
// 	tmp.y = pos.y + (SIZE_MAP / 2);
	
// 	while ((tmp.x) < tmp.x + cut)
// 	{
// 		tmp.y = pos.y + (SIZE_MAP / 2);
// 		while ((tmp.y) < tmp.y + cut)
// 		{
// 			printf("tmp.x = %f\n", tmp.x);
// 			printf("tmp.y = %f\n", tmp.y);
// 			put_pixel(minimap, tmp.y, tmp.x, MAP_PLAYER);
// 			tmp.y++;
// 		}
// 		tmp.x++;
// 	}
// }


