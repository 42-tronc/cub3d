/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:54:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/22 11:31:27 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	minimap(t_exec *exec)
{
	draw_minimap(exec);
	draw_player_pos(&exec->minimap, exec->map);
	mlx_put_image_to_window(exec->mlx_ptr, exec->window, \
			exec->minimap.img, 0, 0);
	return (SUCCESS);
}

void	draw_minimap(t_exec *exec)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (exec->map[x])
	{
		y = 0;
		while (exec->map[x][y])
		{
			if (exec->map[x][y] == '1')
				draw_squares(&exec->minimap, MAP_WALL, x, y);
			else if (ft_strchr("NSWE0", exec->map[x][y]))
				draw_squares(&exec->minimap, MAP_SPACE, x, y);
			y++;
		}
		x++;
	}
}

void	draw_squares(t_data *minimap, int color, int x, int y)
{
	int	i;
	int	j;

	i = x * SIZE_MAP;
	j = y * SIZE_MAP;
	while (i < (x * SIZE_MAP) + SIZE_MAP)
	{
		j = y * SIZE_MAP;
		while (j < (y * SIZE_MAP) + SIZE_MAP)
		{
			put_pixel(minimap, j, i, color);
			j++;
		}
		i++;
	}
}

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

void	draw_player(t_data *minimap, int x, int y)
{
	int	i;
	int	j;
	int	cut;

	i = x * SIZE_MAP;
	j = y * SIZE_MAP;
	cut = SIZE_MAP / 4;
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
