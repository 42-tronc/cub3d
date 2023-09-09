/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:56:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 12:43:02 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_squares(t_data *minimap, int color, int x, int y);

int	minimap(t_exec *exec)
{
	draw_minimap(exec);
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

static void	draw_squares(t_data *minimap, int color, int x, int y)
{
	int	i;
	int	j;

	i = x * SIZE_MAP;
	j = y * SIZE_MAP;
	while (i < (x * SIZE_MAP) + SIZE_MAP - 1)
	{
		j = y * SIZE_MAP;
		while (j < (y * SIZE_MAP) + SIZE_MAP - 1)
		{
			put_pixel(minimap, j, i, color);
			j++;
		}
		i++;
	}
}
