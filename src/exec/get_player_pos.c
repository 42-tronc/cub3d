/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:04:52 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 14:34:42 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_orientation(t_exec *exec, char orientation);

void	get_player_pos(t_exec *exec, char **map)
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
				exec->player_pos.x = (float)i;
				exec->player_pos.y = (float)j;
				exec->player_pos.angle = PI;
				get_player_orientation(exec, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	get_player_orientation(t_exec *exec, char orientation)
{
	if (orientation == 'N')
	{
		exec->player_pos.dx = -2;
		exec->player_pos.dy = -0;
	}
	else if (orientation == 'S')
	{
		exec->player_pos.dx = 2;
		exec->player_pos.dy = 0;
	}
	else if (orientation == 'E')
	{
		exec->player_pos.dx = 0;
		exec->player_pos.dy = 2;
	}
	else if (orientation == 'W')
	{
		exec->player_pos.dx = 0;
		exec->player_pos.dy = -2;
	}
}
