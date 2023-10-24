/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:55:57 by croy              #+#    #+#             */
/*   Updated: 2023/10/24 14:37:32 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #pragma GCC diagnostic ignored "-Wunused-function"
// #pragma GCC diagnostic ignored "-Wunused-variable"
//#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

// static void translate_pos_to_deg(t_data *data, char pos)
// {
// 	if (pos == 'N')
// 		data->player->angle = NORTH;
// 	else if (pos == 'E')
// 		data->player->angle = EAST;
// 	else if (pos == 'S')
// 		data->player->angle = SOUTH;
// 	else if (pos == 'W')
// 		data->player->angle = WEST;
// }

// static int get_player_pos(t_data *data)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	c;

// 	i = 0;
// 	data->player_pos = ft_calloc(1, sizeof(t_player));
// 	if (!data->player)
// 		return (print_perr(E_MALLOC, "get_player_pos"), EXIT_FAILURE);
// 	while (data->map->array[i])
// 	{
// 		j = 0;
// 		while (data->map->array[i][j])
// 		{
// 			c = data->map->array[i][j];
// 			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 			{
// 				// translate_pos_to_deg(data, c);
// 				data->player->x = j;
// 				data->player->y = i;
// 				printf("\n\e[92;1mPlayer position:\e[0m\n"); // REMOVE
// 				printf("\e[93;1mx: \e[22m%.2f\e[0m\n", data->player->x); // REMOVE
// 				printf("\e[93;1my: \e[22m%.2f\e[0m\n", data->player->y); // REMOVE
// 				printf("\e[93;1mrotation: \e[22m%.2f\e[0m\n", data->player->angle); // REMOVE
// 				return (EXIT_SUCCESS);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (EXIT_FAILURE);
// }

static void	init_vars(t_data *data)
{
	data->file = NULL;
	data->split_file = NULL;
	data->north.path = NULL;
	data->north.fd = 0;
	data->south.path = NULL;
	data->south.fd = 0;
	data->west.path = NULL;
	data->west.fd = 0;
	data->east.path = NULL;
	data->east.fd = 0;
	data->map = NULL;
	// data->floor = 0;
	// data->ceiling = 0;
}

/**
 * @brief Parse and check the map file
 *
 * @param data	pointer to the main structure
 * @param map	absolute or relative path to the map
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	map_parsing(t_data *data, char *map)
{
	(void) data;
	// printf("map: %s\n", map);
	init_vars(data);
	if (check_extension(map, ".cub") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_file(data, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cleanup_file(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map_properties(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_vert_island(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_walls(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (get_player_pos(data) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	printf("\n\t\e[92;1m✅ Passed\e[0m\n"); // REMOVE
	return (EXIT_SUCCESS);
}
