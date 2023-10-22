/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:34 by croy              #+#    #+#             */
/*   Updated: 2023/10/22 18:59:21 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========= @includes =========
# include "../minilibx/mlx.h"
# include "libft.h"

# include <errno.h>  // for perror
# include <fcntl.h>  // for open
# include <stdio.h>  // for printf
# include <stdlib.h> // for malloc, free, exit
# include <string.h> // for strerror
# include <unistd.h> // for close, read, write

// ========= @defines =========
# define RED		"\e[31m"
# define WHITE		"\e[37m"
# define RESET		"\e[0m"
# define BOLD		"\e[1m"
# define NO_BOLD	"\e[22m"

typedef struct s_texture
{
	int		fd;
	char	*path;
}	t_texture;

typedef struct s_map
{
	char	**array;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	rotation;
}	t_player;

typedef struct s_data
{
	char			*file;
	char			**split_file;
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;
	unsigned int	floor;
	unsigned int	ceiling;
	t_map			*map;
	t_player		*player;
}	t_data;

typedef enum e_error_code {
	E_MALLOC,
	E_READ,
	E_MISSING,
	E_EXT,
	E_PROP_FMT,
	E_PROP_DUP,
	E_PROP_VAR,
	E_MAP_MISS,
	E_MAP_FMT,
	E_MAP_PLYR,
	E_MAP_WALLS,
	E_MAP_ISLAND
	E_TXT_MISS,
}	t_error_code;

# define NORTH	0
# define EAST	90
# define SOUTH	180
# define WEST	270

//	===== @functions =====
// parsing.c
int	map_parsing(t_data *data, char *map);

// utils_error.c
void	print_error(int code, char *src);

// utils_free.c
void	free_tab(char **tab);
void	free_if_alloc(char *string);
void	free_data(t_data *data);

#endif
