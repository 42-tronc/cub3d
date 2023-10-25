/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:17:46 by croy              #+#    #+#             */
/*   Updated: 2023/10/25 18:26:13 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_column_empty(t_data *data, size_t x)
{
	size_t	y;

	y = 0;
	while (data->map->array[y] && ft_strlen(data->map->array[y]) >= x)
	{
		if (data->map->array[y][x] && data->map->array[y][x] != ' ')
		{ // REMOVE
			// printf("Found `%c` at (%ld, %ld), column %ld\n\n", data->map->array[y][x], x, y, x); // REMOVE
			return (0);
		} // REMOVE
		y++;
	}
	return (1);
}

int	check_map_vert_island(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	printf("\n\e[92;1mMap vertical islands:\e[0m\n"); // REMOVE
	while (data->map->array[y])
	{
		x = 0;
		while (data->map->array[y][x])
		{
			// printf("checking `%c` at (%ld, %ld), column %ld checking under\n", data->map->array[y][x], x, y, x); // REMOVE
			if (data->map->array[y][x] == ' ' && is_column_empty(data, x))
				return (print_perr(E_MAP_ISLAND, data->map->array[y]), EXIT_FAILURE);
			x++;
		}
		y++;
	}
	printf("\e[93;1mNo vertical islands found\e[0m\n"); // REMOVE
	return (EXIT_SUCCESS);
}
