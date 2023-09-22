/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:55:57 by croy              #+#    #+#             */
/*   Updated: 2023/09/22 17:39:55 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

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
	if (texture->fd > 0)
		return (print_error(E_PROP_DUP, path), EXIT_FAILURE);
	texture->path = ft_strdup(path);
	texture->fd = open(path, O_RDONLY);
	if (texture->fd == -1)
		return (perror(RED "Error" RESET), EXIT_FAILURE);
	// printf("\e[92;1mTexture: \e[0m%s\n", texture->path); // REMOVE
	// printf("\e[92;1mTexture fd: \e[0m%d\n", texture->fd); // REMOVE
	return (EXIT_SUCCESS);
}

static int ft_isonlydigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	set_color(unsigned *color, char *input)
{
	int		i;
	int		rgb[3];
	char	**colors;

	i = 0;
	colors = ft_split(input, ',');
	if (!colors)
		return (print_error(E_MALLOC, "get_color"), EXIT_FAILURE);
	if (ft_arrlen(colors) != 3)
		return (print_error(E_PROP_FMT, input), free_tab(colors), EXIT_FAILURE);
	while (colors[i])
	{
		if (!ft_isonlydigit(colors[i]))
			return (print_error(E_PROP_FMT, input), free_tab(colors), EXIT_FAILURE);
		rgb[i] = ft_atoi(colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (print_error(E_PROP_FMT, input), free_tab(colors), EXIT_FAILURE);
		i++;
	}
	free_tab(colors);
	printf("\n\e[92;1mRGB: \e[0m%d, %d, %d\n", rgb[0], rgb[1], rgb[2]); // REMOVE
	*color = rgb[0] << 16 | rgb[1] << 8 | rgb[2]; // THIS NEEDS TO BE CONVERTED TO REAL HEX
	printf("\e[92;1mHEX: \e[0m%d\n", *color); // REMOVE
	// print_nbr(*color, "0123456789abcdef"); // REMOVE
	// printf("\n"); // REMOVE
	return (EXIT_SUCCESS);
}

static	int	get_texture(t_data *data, char **lines)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (!ft_strcmp(lines[0], "NO"))
		exit_code = set_texture(&data->north, lines[1]);
	else if (!ft_strcmp(lines[0], "SO"))
		exit_code = set_texture(&data->south, lines[1]);
	else if (!ft_strcmp(lines[0], "WE"))
		exit_code = set_texture(&data->west, lines[1]);
	else if (!ft_strcmp(lines[0], "EA"))
		exit_code = set_texture(&data->east, lines[1]);
	else if (!ft_strcmp(lines[0], "F"))
		exit_code = set_color(&data->floor, lines[1]); // IMPLEMENT
	else if (!ft_strcmp(lines[0], "C"))
		exit_code = set_color(&data->ceiling, lines[1]); // IMPLEMENT
	else
	{
		exit_code = EXIT_FAILURE;
		print_error(E_PROP_VAR, lines[0]);
	}
	return (exit_code);
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
		if (!lines)
			return (print_error(E_MALLOC, "get_map_properties"), EXIT_FAILURE);
		// printf("\e[93;1m`%s`\t`%s`\e[0m\n", lines[0], lines[1]); // REMOVE
		if (ft_arrlen(lines) != 2 || ft_isdigit(lines[0][0]))
			return (print_error(E_PROP_FMT, lines[0]), free_tab(lines), EXIT_FAILURE);
		if (get_texture(data, lines) == EXIT_FAILURE)
			return (free_tab(lines), EXIT_FAILURE);
		free_tab(lines);
		i++;
	}
	printf("\n\e[92;1mTextures:\e[0m\n"); // REMOVE
	printf("\e[93;1mnorth: \e[22m%s\e[0m\n", data->north.path); // REMOVE
	printf("\e[93;1msouth: \e[22m%s\e[0m\n", data->south.path); // REMOVE
	printf("\e[93;1mwest: \e[22m%s\e[0m\n", data->west.path); // REMOVE
	printf("\e[93;1meast: \e[22m%s\e[0m\n", data->east.path); // REMOVE
	printf("\n\e[92;1mColors:\e[0m\n"); // REMOVE
	printf("\e[93;1mfloor: \e[22m%d\e[0m\n", data->floor); // REMOVE
	printf("\e[93;1mceiling: \e[22m%d\e[0m\n", data->ceiling); // REMOVE
	return (EXIT_SUCCESS);
}

static void	get_map_size(t_data *data)
{
	size_t	i;
	size_t	map_width;

	i = 6;
	map_width = 0;
	data->map->height = ft_arrlen(data->split_file + 6);
	while (data->split_file[i])
	{
		printf("Checking line: `%s`\n", data->split_file[i]); // REMOVE
		if (ft_strlen(data->split_file[i]) > data->map->width)
			data->map->width = ft_strlen(data->split_file[i]);
		i++;
	}
}

static int	get_map(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data->split_file[6])
		return (print_error(E_MAP_MISS, NULL), EXIT_FAILURE);
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (print_error(E_MALLOC, "get_map 1"), EXIT_FAILURE);
	get_map_size(data);
	if (data->map->width < 3 || data->map->height < 3)
		return (print_error(E_MAP_FMT, NULL), EXIT_FAILURE);
	data->map->array = ft_calloc(data->map->height + 1, sizeof(char *));
	if (!data->map->array)
		return (print_error(E_MALLOC, "get_map 2"), EXIT_FAILURE);
	while (i < data->map->height)
	{
		data->map->array[i] = ft_strdup(data->split_file[i + 6]);
		if (!data->map->array[i])
			return (print_error(E_MALLOC, "get_map 3"), EXIT_FAILURE);
		i++;
	}

	printf("\n\e[92;1mMap:\e[0m\n"); // REMOVE
	for (int i = 0; data->map->array[i]; i++) // REMOVE
		printf("%s\n", data->map->array[i]); // REMOVE
	printf("\n\e[92;1mMap size:\e[0m\n"); // REMOVE
	printf("\e[93;1mheight: \e[22m%ld\e[0m\n", data->map->height); // REMOVE
	printf("\e[93;1mwidth: \e[22m%ld\e[0m\n", data->map->width); // REMOVE
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
	if (get_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (check_map(data) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
