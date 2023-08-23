/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:49:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/23 13:13:26 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    left_rotation(t_exec *exec)
{
    exec->player_pos_fl.angle -= 0.025;
    if (exec->player_pos_fl.angle < 0)
        exec->player_pos_fl.angle += 2 * PI;
    exec->player_pos_fl.dx = cos(exec->player_pos_fl.angle) * 5;
    exec->player_pos_fl.dy = sin(exec->player_pos_fl.angle) * 5;
}

void    right_rotation(t_exec *exec)
{
    exec->player_pos_fl.angle += 0.025;
    if (exec->player_pos_fl.angle > 2 * PI)
        exec->player_pos_fl.angle -= 2 * PI;
    exec->player_pos_fl.dx = cos(exec->player_pos_fl.angle) * 5;
    exec->player_pos_fl.dy = sin(exec->player_pos_fl.angle) * 5;
}