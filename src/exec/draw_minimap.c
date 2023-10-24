/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:56:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 12:31:58 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	launcher_minimap(t_data *data);
static void	draw_squares(t_mlx_data *minimap, int color, int x, int y);

void	draw_minimap(t_data *data)
{
	launcher_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, \
			data->minimap.img, 0, 0);
}

static void	launcher_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->array[x])
	{
		y = 0;
		while (data->map->array[x][y])
		{
			if (data->map->array[x][y] == '1')
				draw_squares(&data->minimap, MAP_WALL, x, y);
			else if (ft_strchr("NSWE0", data->map->array[x][y]))
				draw_squares(&data->minimap, MAP_SPACE, x, y);
			y++;
		}
		x++;
	}
}

static void	draw_squares(t_mlx_data *minimap, int color, int x, int y)
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
