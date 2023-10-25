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

int	check_map_hori_island(t_data *data, char *path)
{
	(void) data;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(RED "Error" RESET);
		return (EXIT_FAILURE);
	}

	printf("\n\e[92;1mMap horizontal islands:\e[0m\n"); // REMOVE
	printf("\e[93;1mFile fd: \e[0m%d\n", fd); // REMOVE
	line = get_next_line(fd);
	if (!line)
	{
		printf("\e[93;1mNo line found\e[0m\n"); // REMOVE
		return (FAILURE);
	}
	// 	// return (print_perr(E_MAP_ISLAND, data->map->array[data->map->height - 1]), EXIT_FAILURE);
	// while (line && ft_strncmp(line, data->map->array[0], ft_strlen(data->map->array[0])))
	while (line)
	{
		printf("Line: `%s`\n", line); // REMOVE
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		printf("\e[94;1mFound first line of map\e[0m\n"); // REMOVE
		// line = get_next_line(fd);
	}
	printf("\e[93;1mNo more lines found\e[0m\n"); // REMOVE
	free(line);
	close(fd);
	return (FAILURE);
}
