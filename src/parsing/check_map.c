/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:13:31 by croy              #+#    #+#             */
/*   Updated: 2023/10/24 14:17:24 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check if the map has only valid characters and only one player
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	check_map(t_data *data)
{
	int		player;
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	player = 0;
	while (data->map->array[i])
	{
		j = 0;
		while (data->map->array[i][j])
		{
			c = data->map->array[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				player++;
			else if (c != ' ' && c != '0' && c != '1')
				return (print_perr(E_MAP_FMT, data->map->array[i]), EXIT_FAILURE);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (print_perr(E_MAP_PLYR, NULL), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int is_bordered_by_walls(t_data *data, size_t x, size_t y)
{
	int	x_offset;
	int	y_offset;

	if (x == 0 || x == data->map->width - 1
		|| y == 0 || y == data->map->height - 1)
		return (0);
	x_offset = -1;
	while (x_offset <= 1)
	{
		y_offset = -1;
		while (y_offset <= 1)
		{
			// printf("Checking walls %ld, %ld: `%c`\n", x + x_offset, y + y_offset, data->map->array[y + y_offset][x + x_offset]); // REMOVE
			if (!data->map->array[y + y_offset][x + x_offset]
				|| data->map->array[y + y_offset][x + x_offset] == ' ')
				return (0);
			y_offset++;
		}
		x_offset++;
	}
	return (1);
}

int	check_map_walls(t_data *data)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 4;
	while (data->map->array[i])
	{
		j = 0;
		// printf("\nChecking line %ld: `%s`\n", i, data->map->array[i]); // REMOVE
		while (data->map->array[i][j])
		{
			c = data->map->array[i][j];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				// printf("\nChecking around char %ld: `%c`\n", j, c); // REMOVE
				if (!is_bordered_by_walls(data, j, i))
					return (print_perr(E_MAP_WALLS, data->map->array[i]), EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	printf("\n\e[92;1mMap walls:\e[0m\n"); // REMOVE
	printf("\e[93;1mMap is surrounded by walls\e[0m\n"); // REMOVE
	return (EXIT_SUCCESS);
}
