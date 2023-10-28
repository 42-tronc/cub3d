/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:58:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/28 10:07:48 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_minimap(t_mlx_data *minimap, float x, float y)
{
	t_vector_float		p_position;
	float				cut;

	cut = SIZE_MAP / SIZE_CUT;
	p_position.x = (x * SIZE_MAP);
	p_position.y = (y * SIZE_MAP);
	while ((p_position.x) < (x * SIZE_MAP) + cut)
	{
		p_position.y = y * SIZE_MAP;
		while ((p_position.y) < (y * SIZE_MAP) + cut)
		{
			put_pixel(minimap, p_position.y, p_position.x, MAP_PLAYER);
			p_position.y++;
		}
		p_position.x++;
	}
}