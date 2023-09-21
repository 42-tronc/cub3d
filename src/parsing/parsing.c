/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:55:57 by croy              #+#    #+#             */
/*   Updated: 2023/09/21 19:58:27 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #pragma GCC diagnostic ignored "-Wunused-function"
// #pragma GCC diagnostic ignored "-Wunused-variable"
// #pragma GCC diagnostic ignored "-Wunused-but-set-variable"

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
		printf("\e[92;1mExtension: \e[0m%s\n", file); // REMOVE
	return (EXIT_SUCCESS);
}

static char	*read_file(int fd)
{
	int		char_read;
	char	buffer[BUFFER_SIZE];
	char	*file;

	char_read = 1;
	file = NULL;
	while (char_read)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		// maybe protect if char_read < 0
		buffer[char_read] = '\0';
		if (!file)
			file = ft_strdup(buffer);
		else
			file = ft_strjoin(file, buffer);
		if (!file && char_read)
			return (print_error(E_MALLOC, "read_file"), NULL);
	}
	return (file);
}

static int	check_file(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(RED "Error" RESET);
		return (EXIT_FAILURE);
	}
	else // REMOVE
	{
		printf("\e[92;1mFile: \e[0m%s\n", path); // REMOVE
		data->file = read_file(fd);
		if (!data->file)
			return (close(fd), EXIT_FAILURE);
		else // REMOVE
			printf("\e[92;1mFile content:\n\e[0m%s\n", data->file); // REMOVE
	}
	close(fd);
	return (EXIT_SUCCESS);
}

static int	cleanup_file(t_data *data)
{
	data->split_file = ft_split(data->file, '\n');
	if (!data->split_file)
		return (print_error(E_MALLOC, "cleanup_file"), EXIT_FAILURE);
	printf("\e[92;1mFile split:\n\e[0m"); // REMOVE
	for (int i = 0; data->split_file[i]; i++) // REMOVE
		printf("%s\n", data->split_file[i]); // REMOVE
	printf("--------------------\n");
	return (EXIT_SUCCESS);
}

static int	set_texture(t_texture *texture, char *path)
{
	texture->path = path;
	texture->fd = open(path, O_RDONLY);
	if (texture->fd == -1)
		return (perror(RED "Error" RESET), EXIT_FAILURE);
	printf("\e[92;1mTexture: \e[0m%s\n", path); // REMOVE
	return (EXIT_SUCCESS);
}

static	int	get_texture(t_data *data, char **lines)
{
	if (!ft_strncmp(lines[0], "NO", 3))
		return (set_texture(&data->north, lines[1]));
	else if (!ft_strncmp(lines[0], "SO", 3))
		return (set_texture(&data->south, lines[1]));
	else if (!ft_strncmp(lines[0], "WE", 3))
		return (set_texture(&data->west, lines[1]));
	else if (!ft_strncmp(lines[0], "EA", 3))
		return (set_texture(&data->east, lines[1]));
	else if (!ft_strncmp(lines[0], "F", 2))
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(lines[0], "C", 2))
		return (EXIT_SUCCESS);
	else
		return (print_error(E_PROPERTY, "get_texture"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	init_texture(t_data *data)
{
	data->north.fd = 0;
	data->north.path = NULL;
	data->south.fd = 0;
	data->south.path = NULL;
	data->west.fd = 0;
	data->west.path = NULL;
	data->east.fd = 0;
	data->east.path = NULL;
}

static int	get_map_properties(t_data *data)
{
	int		i;
	char	**lines;

	i = 0;
	init_texture(data);
	while (data->split_file && i < 6)
	{
		lines = ft_split(data->split_file[i], ' ');
		printf("\e[93;1m`%s`\t`%s`\e[0m\n", lines[0], lines[1]); // REMOVE
		if (ft_arrlen(lines) != 2 || ft_isdigit(lines[0][0]))
			return (print_error(E_PROPERTY, lines[0]), free_tab(lines), EXIT_FAILURE);
		if (get_texture(data, lines) == EXIT_FAILURE)
			return (free_tab(lines), EXIT_FAILURE);
		free_tab(lines);
		i++;
	}
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
	if (check_file(data, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cleanup_file(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map_properties(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
