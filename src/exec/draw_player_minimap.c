/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_minimap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:58:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/23 12:29:36 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_pos(t_data *minimap, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchr("NSWE", map[x][y]))
				draw_player(minimap, x, y);
			y++;
		}
		x++;
	}
}

void	draw_player(t_data *minimap, float x, float y)
{
	float	i;
	float	j;
	float	cut;

	i = x * SIZE_MAP;
	j = y * SIZE_MAP;
	cut = SIZE_MAP / SIZE_PLAYER;
	while ((i + cut) < (x * SIZE_MAP) + SIZE_MAP)
	{
		j = y * SIZE_MAP;
		while ((j + cut) < (y * SIZE_MAP) + SIZE_MAP)
		{
			put_pixel(minimap, j, i, MAP_PLAYER);
			j++;
		}
		i++;
	}
}
