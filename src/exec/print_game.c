/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:17:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/22 12:20:25 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	draw_minimap(t_data *img, char **map);
static void	draw_squares(t_data *minimap, int color, int x, int y);

int	print_game(t_mlx *mlx, char **map)
{
	t_data	minimap;

	if (SIZE_MAP > 100)
		return (FAILURE);
	minimap.img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!minimap.img)
		return (FAILURE);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel, \
			&minimap.line_length, &minimap.endian);
	if (!minimap.addr)
		return (FAILURE);
	draw_minimap(&minimap, map);
	draw_player_pos(&minimap, map);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, minimap.img, 0, 0);
	return (SUCCESS);
}

static void	draw_minimap(t_data *minimap, char **map)
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
			if (map[x][y] == '1')
				draw_squares(minimap, MAP_WALL, x, y);
			else if (ft_strchr("NSWE0", map[x][y]))
				draw_squares(minimap, MAP_SPACE, x, y);
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
