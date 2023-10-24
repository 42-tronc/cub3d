/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:04:52 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/20 11:14:36 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float get_angle(char orientation);

void	init_player(t_data *data, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				data->nswe = map[i][j];
				data->player_pos.x = (float)i;
				data->player_pos.y = (float)j;
				data->player_pos.angle = get_angle(map[i][j]);
				data->player_pos.dx = cos(data->player_pos.angle);
				data->player_pos.dy = sin(data->player_pos.angle);
				// data->player_pos.x = (data->player_pos.x * BLOCK) + (BLOCK / 2);
				// data->player_pos.y = (data->player_pos.y * BLOCK) + (BLOCK / 2);
				return ;
			}
			j++;
		}
		i++;
	}
}

static float get_angle(char orientation)
{
	if (orientation == 'N')
		return ((3 * PI) / 2);
	else if (orientation == 'S')
		return (PI / 2);
	else if (orientation == 'E')
		return (PI);
	else if (orientation == 'W')
		return (PI * 2);
	return (0);
}
