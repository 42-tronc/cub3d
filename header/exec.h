/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:34:12 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 14:05:22 by lboulatr         ###   ########.fr       */
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
int				exec_manager(t_data *data);
void            ft_dda(t_data *data, t_ray *ray, t_vector_float direction);
int				close_window(t_data *data, int status);

// ========== Init ==========
int				init_mlx(t_data *data);
void			init_player(t_data *data, char **map);
void            init_ray_struct(t_data *data, t_ray *ray, float dir_x, float dir_y);


// ========== Draw ==========
void			draw_minimap(t_data *data);
void			draw_player_minimap(t_mlx_data *minimap, float x, float y);
void            draw_walls(t_data *data, int count, t_ray ray);
int				refresh_window(t_data *data);

// ========== Moves ==========
int				moves(int key_code, t_data *data);
void			rotation(t_data *data, int key);


// ========== Raycasting ==========
void			raycasting(t_data *data);
void			raycasting_2(t_data *data, float x, float y);

// ========== Utils ===========
void			put_pixel(t_mlx_data *data, int x, int y, int color);

// ========== Errors ==========
void			free_mlx(t_data *data);
void			free_window(t_data *data);

#endif
