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

void	init_player(t_exec *exec, char **map)
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
				exec->nswe = map[i][j];
				exec->player_pos.x = (float)i;
				exec->player_pos.y = (float)j;
				exec->player_pos.angle = get_angle(map[i][j]);
				exec->player_pos.dx = cos(exec->player_pos.angle);
				exec->player_pos.dy = sin(exec->player_pos.angle);
				// exec->player_pos.x = (exec->player_pos.x * BLOCK) + (BLOCK / 2);
				// exec->player_pos.y = (exec->player_pos.y * BLOCK) + (BLOCK / 2);
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
		return (PI / 2);
	else if (orientation == 'S')
		return ((3 * PI) / 2);
	else if (orientation == 'E')
		return (PI * 2);
	else if (orientation == 'W')
		return (PI);
	return (0);
}