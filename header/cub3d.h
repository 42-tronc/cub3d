/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:34 by croy              #+#    #+#             */
/*   Updated: 2023/08/22 08:55:52 by lboulatr         ###   ########.fr       */
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
# include "exec.h"

// ========= @defines =========
# define RED		"\e[31m"
# define WHITE		"\e[37m"
# define RESET		"\e[0m"
# define BOLD		"\e[1m"
# define NO_BOLD	"\e[22m"

typedef enum e_error_code {
	E_MALLOC,
}	t_error_code;

//	===== @functions =====
// utils_error.c
void	print_error(int code, char *src);
void	close_fd(void);

#endif
