/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:59:44 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 08:59:48 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

// ========== Vectors ==========
typedef struct s_vector_int
{
    int				x;
    int				y;
}				t_vector_int;

typedef struct s_vector_float
{
    float			x;
    float			y;
}				t_vector_float;

typedef struct s_player
{
	float				x;
	float				y;
	float				dx;
	float				dy;
	float				angle;
}				t_player;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

typedef enum s_cardinal_pts
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_cardinal_pts;

typedef struct s_draw
{
    int				start;
    int				end;
    int             height;
}				t_draw;

typedef struct s_ray
{
    t_vector_float      delta;
    t_vector_float      dist_to_wall;

    t_vector_int        step;
    t_vector_int        map_pos;

    t_cardinal_pts      cardinal;
}				t_ray;

typedef struct s_exec
{
    char                nswe;
	char				**map;
	void				*mlx_ptr;
	void				*window;
	
	t_data				minimap;
	t_player    		player_pos;
}				t_exec;

#endif