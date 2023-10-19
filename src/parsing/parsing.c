/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:55:57 by croy              #+#    #+#             */
/*   Updated: 2023/09/27 11:43:01 by croy             ###   ########lyon.fr   */
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

/**
 * @brief Read the file and store it in a string
 *
 * @param fd		file descriptor
 * @return char*	pointer to the string containing the file
 */
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

/**
 * @brief Check if the file exists and store it in the t_data structure
 *
 * @param data	pointer to the main structure
 * @param path	absolute or relative path to the map file
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
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

/**
 * @brief Split the file into lines and store them in the t_data structure
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
static int	cleanup_file(t_data *data)
{
	data->split_file = ft_split(data->file, '\n');
	if (!data->split_file)
		return (print_error(E_MALLOC, "cleanup_file"), EXIT_FAILURE);
	printf("\e[92;1mFile split:\n\e[0m"); // REMOVE
	for (int i = 0; data->split_file[i]; i++) // REMOVE
		printf("%s\n", data->split_file[i]); // REMOVE
	return (EXIT_SUCCESS);
}

/**
 * @brief Store the texture's path and file descriptor in the t_texture structure
 *
 * @param texture	pointer to the t_texture structure to store the data in
 * @param path		absolute or relative path to the texture file
 * @return int		EXIT_SUCCESS or EXIT_FAILURE
 */
static int	set_texture(t_texture *texture, char *path)
{
	if (texture->fd > 0)
		return (print_error(E_PROP_DUP, path), EXIT_FAILURE);
	texture->path = ft_strdup(path);
	texture->fd = open(path, O_RDONLY);
	if (texture->fd == -1)
		return (print_error(E_TXT_MISS, path), EXIT_FAILURE);
	// printf("\e[92;1mTexture: \e[0m%s\n", texture->path); // REMOVE
	// printf("\e[92;1mTexture fd: \e[0m%d\n", texture->fd); // REMOVE
	return (EXIT_SUCCESS);
}

/**
 * @brief Check if the string only contains digits
 *
 * @param str	string to check
 * @return int	1 if the string only contains digits, 0 otherwise
 */
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

/**
 * @brief Convert the RGB floor and ceiling colors to hexadecimal
 *
 * @param color	pointer to the color converted to hexadecimal
 * @param input	string containing the RGB values separated by commas
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
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

/**
 * @brief Parse the map's properties and store them in the t_data structure
 *
 * @param data	pointer to the main structure
 * @param lines	array containing the property's name and value
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
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

/**
 * @brief Initialize the t_texture structures to 0 and NULL
 *
 * @param data	pointer to the main structure
 */
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

/**
 * @brief Dispatch the map's properties to the right functions to be stored,
 * also check if the properties are valid
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
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

/**
 * @brief Find the map's width and height and store them in the t_map structure
 *
 * @param data	pointer to the main structure
 */
static void	get_map_size(t_data *data)
{
	size_t	i;

	i = 6;
	data->map->height = ft_arrlen(data->split_file + 6);
	while (data->split_file[i])
	{
		printf("Checking line: `%s`\n", data->split_file[i]); // REMOVE
		if (ft_strlen(data->split_file[i]) > data->map->width)
			data->map->width = ft_strlen(data->split_file[i]);
		i++;
	}
}

/**
 * @brief Check if the map has a valid size and store it in the t_map structure
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
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
 * @brief Check if the map has only valid characters and only one player
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
static int	check_map(t_data *data)
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
				return (print_error(E_MAP_FMT, data->map->array[i]), EXIT_FAILURE);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (print_error(E_MAP_PLYR, NULL), EXIT_FAILURE);
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

static int	check_map_walls(t_data *data)
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
					return (print_error(E_MAP_WALLS, data->map->array[i]), EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	printf("\n\e[92;1mMap walls:\e[0m\n"); // REMOVE
	printf("\e[93;1mMap is surrounded by walls\e[0m\n"); // REMOVE
	return (EXIT_SUCCESS);
}

static void translate_pos_to_deg(t_data *data, char pos)
{
	if (pos == 'N')
		data->player->rotation = NORTH;
	else if (pos == 'E')
		data->player->rotation = EAST;
	else if (pos == 'S')
		data->player->rotation = SOUTH;
	else if (pos == 'W')
		data->player->rotation = WEST;
}

static int get_player_pos(t_data *data)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (print_error(E_MALLOC, "get_player_pos"), EXIT_FAILURE);
	while (data->map->array[i])
	{
		j = 0;
		while (data->map->array[i][j])
		{
			c = data->map->array[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				translate_pos_to_deg(data, c);
				data->player->x = j;
				data->player->y = i;
				printf("\n\e[92;1mPlayer position:\e[0m\n"); // REMOVE
				printf("\e[93;1mx: \e[22m%.2f\e[0m\n", data->player->x); // REMOVE
				printf("\e[93;1my: \e[22m%.2f\e[0m\n", data->player->y); // REMOVE
				printf("\e[93;1mrotation: \e[22m%.2f\e[0m\n", data->player->rotation); // REMOVE
				return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
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
	if (check_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_walls(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_player_pos(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("\n\t\e[92;1m✅ Passed\e[0m\n"); // REMOVE
	return (EXIT_SUCCESS);
}
