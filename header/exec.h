/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:34:12 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 13:46:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "cub3d.h"

# define SUCCESS	    EXIT_SUCCESS
# define FAILURE	    EXIT_FAILURE

# define KEY_ESC 	    65307
# define LEFT_ARROW     65361
# define RIGHT_ARROW    65363
# define KEY_W 	        119
# define KEY_A	        97
# define KEY_S	        115
# define KEY_D	        100

# define SIZE_MAP       125
# define SIZE_PLAYER	1.5
# define SIZE_FLOAT		0.15
# define HEIGHT         1080
# define WIDTH          1920
# define MAP_WALL		0x0f056b
# define MAP_SPACE		0x919191
# define MAP_PLAYER		0x00ff7f
# define RED_HEX        0xff0000
# define MALLOC_ERR     "Error during a malloc.\n"
# define PI				3.1415926535
# define RAD			0.0174533

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

typedef struct s_vector_int
{
	int				x;
	int				y;
}				t_vector_int;

typedef struct s_vector_float
{
	float				x;
	float				y;
	float				dx;
	float				dy;
	float				angle;
}				t_vector_float;

typedef struct s_exec
{
	void			*mlx_ptr;
	void			*window;
	char			**map;
	t_data			minimap;
	t_vector_float	player_pos;
}				t_exec;

// ========== Exec ==========
int				exec_manager(char *map);
int				init_mlx(t_exec *exec);
int				close_window(t_exec *exec, int status);
int				moves(int key_code, t_exec *exec);
void			get_player_pos(t_exec *exec, char **map);

// ========== Draw ==========
void			draw_minimap(t_exec *exec);
void			draw_player_minimap(t_data *minimap, float x, float y);
void			draw_sight(t_exec *exec, float x, float y);
int				refresh_window(t_exec *exec);

// ========== Rotation ==========
void			left_rotation(t_exec *exec);
void			right_rotation(t_exec *exec);

// ========== Utils ===========
void			put_pixel(t_data *data, int x, int y, int color);
void			free_map(char **map);

// ========== Errors ==========
void			display_error(char *str);
void			free_mlx(t_exec *exec);
void			free_window(t_exec *exec);

#endif
