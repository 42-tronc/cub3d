/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:43:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 13:03:20 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	move_w(t_exec *exec);
static void	move_a(t_exec *exec);
static void	move_s(t_exec *exec);
static void	move_d(t_exec *exec);

int	moves(int key_code, t_exec *exec)
{
	if (key_code == KEY_ESC)
		close_window(exec, SUCCESS);
	else if (key_code == KEY_W)
		move_w(exec);
	else if (key_code == KEY_A)
		move_a(exec);
	else if (key_code == KEY_S)
		move_s(exec);
	else if (key_code == KEY_D)
		move_d(exec);
	else if (key_code == LEFT_ARROW)
		left_rotation(exec);
	else if (key_code == RIGHT_ARROW)
		right_rotation(exec);
	return (SUCCESS);
}

static void	move_w(t_exec *exec)
{
	exec->player_pos.x += exec->player_pos.dx / (SIZE_MAP / 15);
	exec->player_pos.y += exec->player_pos.dy / (SIZE_MAP / 15);
}

static void	move_s(t_exec *exec)
{
	exec->player_pos.x -= exec->player_pos.dx / (SIZE_MAP / 15);
	exec->player_pos.y -= exec->player_pos.dy / (SIZE_MAP / 15);
}

static void	move_a(t_exec *exec)
{
	double		angle;
	double		side_angle;
	double		move_x;
	double		move_y;

	angle = atan2(exec->player_pos.dy, exec->player_pos.dx);
	side_angle = angle + (PI / 2);
	move_x = SIZE_FLOAT * cos(side_angle);
	move_y = SIZE_FLOAT * sin(side_angle);
	exec->player_pos.x += move_x / (SIZE_MAP / 30);
	exec->player_pos.y += move_y / (SIZE_MAP / 30);
}

static void	move_d(t_exec *exec)
{
	double		angle;
	double		side_angle;
	double		move_x;
	double		move_y;

	angle = atan2(exec->player_pos.dy, exec->player_pos.dx);
	side_angle = angle + (PI / 2);
	move_x = SIZE_FLOAT * cos(side_angle);
	move_y = SIZE_FLOAT * sin(side_angle);
	exec->player_pos.x -= move_x / (SIZE_MAP / 30);
	exec->player_pos.y -= move_y / (SIZE_MAP / 30);
}
