/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:49:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 10:55:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    left_rotation(t_exec *exec)
{
    exec->player_pos.angle += 0.05;
    if (exec->player_pos.angle > 2 * PI)
        exec->player_pos.angle -= 2 * PI;
    exec->player_pos.dx = cos(exec->player_pos.angle);
    exec->player_pos.dy = sin(exec->player_pos.angle);
}

void    right_rotation(t_exec *exec)
{
    exec->player_pos.angle -= 0.05;
    if (exec->player_pos.angle < 0)
        exec->player_pos.angle += 2 * PI;
    exec->player_pos.dx = cos(exec->player_pos.angle);
    exec->player_pos.dy = sin(exec->player_pos.angle);
}