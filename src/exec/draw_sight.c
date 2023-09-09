/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:28:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 09:31:25 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    center_player(float fl);

void draw_sight(t_exec *exec, float x, float y) 
{
    t_vector_float		rot;
    
    // printf("d x: %f\n", exec->player_pos.dx);
    // printf("d y: %f\n", exec->player_pos.dy);
    //printf("angle y: %f\n", exec->player_pos.angle);

    rot.x = (x * SIZE_MAP) + center_player(x);
    rot.y = (y * SIZE_MAP) + center_player(y);
    while (exec->map[(int)(rot.x / SIZE_MAP)][(int)(rot.y / SIZE_MAP)] != '1')
    {
        rot.x += exec->player_pos.dx / 10;
        rot.y += exec->player_pos.dy / 10;
        put_pixel(&exec->minimap, rot.y, rot.x, RED_HEX);
    }
}

static float	center_player(float fl)
{
	float	player_center;
	
	player_center = fl + (SIZE_MAP / 7);
	return (player_center);
}