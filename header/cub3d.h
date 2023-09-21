/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:34 by croy              #+#    #+#             */
/*   Updated: 2023/09/21 12:48:07 by croy             ###   ########lyon.fr   */
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

typedef struct s_data
{
	char	*file;
}	t_data;

typedef enum e_error_code {
	E_MALLOC,
	E_MISSING,
	E_EXT,
}	t_error_code;

//	===== @functions =====
// parsing.c
int	map_parsing(t_data *data, char *map);

// utils_error.c
void	print_error(int code, char *src);

// utils_free.c
void	free_data(t_data *data);

#endif
