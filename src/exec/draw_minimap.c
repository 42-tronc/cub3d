/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:56:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 10:38:17 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_structs(t_data *data, t_vector_int *start, t_vector_int *limits);
static void	launcher_minimap(t_data *data, t_vector_int *start, t_vector_int *limits);
static void	draw_squares(t_mlx_data *minimap, int color, int x, int y);

void	draw_minimap(t_data *data)
{
	t_vector_int	start;
	t_vector_int	limits;
	
	init_structs(data, &start, &limits);
	launcher_minimap(data, &start, &limits);

}

static void init_structs(t_data *data, t_vector_int *start, t_vector_int *limits)
{
	start->x = data->player_pos.x - (PRINT_MAP / 2);
	start->y = data->player_pos.y - (PRINT_MAP / 2);
	if (start->x < 0)
		start->x = 0;
	if (start->y < 0)
		start->y = 0;
	limits->x = data->player_pos.x + (PRINT_MAP / 2);
	limits->y = data->player_pos.y + (PRINT_MAP / 2);
	if (limits->x >= (int)data->map->height)
		limits->x = data->map->height;
	if (limits->y >= (int)data->map->width)
		limits->y =  data->map->width;
}

static void	launcher_minimap(t_data *data, t_vector_int *start, t_vector_int *limits)
{
	int 			tmp;
	t_vector_int	count;

	tmp = start->y;
	count.x = 0;
	count.y = 0;
	while (start->x < limits->x)
	{
		start->y = tmp;
		count.y = 0;
		while (start->y < limits->y)
		{
			if (data->map->array[start->x][start->y] == '1')
				draw_squares(&data->minimap, MAP_WALL, count.x, count.y);
			else if (ft_strchr("NSWE0", data->map->array[start->x][start->y]))
				draw_squares(&data->minimap, MAP_SPACE, count.x, count.y);
			start->y++;
			count.y++;
		}
		start->x++;
		count.x++;
	}
}

static void	draw_squares(t_mlx_data *minimap, int color, int x, int y)
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

// void	draw_minimap(t_data *data)
// {
// 	launcher_minimap(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->window, \
// 			data->minimap.img, 0, 0);
// }

// static void	launcher_minimap(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (data->map->array[x])
// 	{
// 		y = 0;
// 		while (data->map->array[x][y])
// 		{
// 			if (data->map->array[x][y] == '1')
// 				draw_squares(&data->minimap, MAP_WALL, x, y);
// 			else if (ft_strchr("NSWE0", data->map->array[x][y]))
// 				draw_squares(&data->minimap, MAP_SPACE, x, y);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// static void	draw_squares(t_mlx_data *minimap, int color, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = x * SIZE_MAP;
// 	j = y * SIZE_MAP;
// 	while (i < (x * SIZE_MAP) + SIZE_MAP)
// 	{
// 		j = y * SIZE_MAP;
// 		while (j < (y * SIZE_MAP) + SIZE_MAP)
// 		{
// 			put_pixel(minimap, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }
