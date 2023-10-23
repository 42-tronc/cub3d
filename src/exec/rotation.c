/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:49:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/20 13:26:07 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	left_rotation(t_exec *exec);
static void	right_rotation(t_exec *exec);

void	rotation(t_exec *exec, int key)
{
	if (key == LEFT_ARROW)
		left_rotation(exec);
	else if (key == RIGHT_ARROW)
		right_rotation(exec);
	exec->player_pos.dx = cos(exec->player_pos.angle);
	exec->player_pos.dy = sin(exec->player_pos.angle);
}

static void	left_rotation(t_exec *exec)
{
	exec->player_pos.angle += 0.1;
	if (exec->player_pos.angle <= 0)
		exec->player_pos.angle += 2 * PI;
}

static void	right_rotation(t_exec *exec)
{
	exec->player_pos.angle -= 0.1;
	if (exec->player_pos.angle > 2 * PI)
		exec->player_pos.angle -= 2 * PI;
}