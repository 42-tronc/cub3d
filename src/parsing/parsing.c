/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:55:57 by croy              #+#    #+#             */
/*   Updated: 2023/09/18 12:59:30 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check if the file has the right extension
 *
 * @param data	pointer to the main structure
 * @param file	absolute or relative path to the file
 * @param ext	extension to check
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
static int	check_extension(char *path, char *ext)
{
	int		file_len;
	int		ext_len;
	char	*file;

	file = ft_strrchr(path, '/');
	if (!file)
		file = path;
	else
		file++;
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (file_len <= ext_len
		|| ft_strncmp(file + file_len - ext_len, ext, ext_len))
	{
		print_error(E_EXT, file);
		return (EXIT_FAILURE);
	}
	else // REMOVE
		printf("\e[92;1mExtension OK: %s\e[0m\n", file); // REMOVE
	return (EXIT_SUCCESS);
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
	if (check_extension(map, ".cub") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
