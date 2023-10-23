/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:34:12 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 09:11:47 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "cub3d.h"
# include "struct.h"

# define SUCCESS	    EXIT_SUCCESS
# define FAILURE	    EXIT_FAILURE
# define MALLOC_ERR     "Error during a malloc.\n"
# define IMG_ERR        1

// ===== Define Keys =====
# define KEY_ESC 	    65307
# define LEFT_ARROW     65361
# define RIGHT_ARROW    65363
# define KEY_W 	        119
# define KEY_A	        97
# define KEY_S	        115
# define KEY_D	        100

// ===== Game define =====
# define BLOCK          20
# define SIZE_MAP       25
# define SIZE_WALL		125
# define SIZE_CUT		4
# define FOV			30
# define HEIGHT         1080
# define WIDTH          1920
# define FOCAL			0.50
# define WALL_H			500
# define N_RAYS			1920

// ===== Maths define =====
# define PI				3.1415926535
# define RAD			0.0174533

// ===== Colors =====
# define MAP_WALL		0x0f056b
# define MAP_SPACE		0x919191
# define MAP_PLAYER		0x00ff7f
# define RED_HEX        0xff0000
# define GREEN_HEX      0x7CFC00
# define BLUE_HEX       0x87CEEB
# define YELLOW_HEX     0xffff00
# define GREY_HEX		0x7f7f7f


// ========== Exec ==========
int				exec_manager(char *map);
int				close_window(t_exec *exec, int status);
float 			get_hypotenuse(t_exec *exec, t_vector_float rotation);
float           get_hypotenuse2(t_ray *ray);


// ========== Init ==========
int				init_mlx(t_exec *exec);
void			init_player(t_exec *exec, char **map);
void            init_ray_struct(t_exec *exec, t_ray *ray, float dir_x, float dir_y);


// ========== Draw ==========
void			draw_minimap(t_exec *exec);
void			draw_player_minimap(t_data *minimap, float x, float y);
void            draw_walls(t_exec *exec, int count, t_ray ray);
int				refresh_window(t_exec *exec);

// ========== Moves ==========
int				moves(int key_code, t_exec *exec);
void			rotation(t_exec *exec, int key);


// ========== Raycasting ==========
void			raycasting(t_exec *exec);
void			raycasting_2(t_exec *exec, float x, float y);

// ========== Utils ===========
void			put_pixel(t_data *data, int x, int y, int color);
void			free_map(char **map);

// ========== Errors ==========
void			display_error(char *str);
void			free_mlx(t_exec *exec);
void			free_window(t_exec *exec);

#endif
