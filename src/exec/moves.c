/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:43:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/20 17:59:01 by lboulatr         ###   ########.fr       */
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
		rotation(exec, key_code);
	else if (key_code == RIGHT_ARROW)
		rotation(exec, key_code);
	return (SUCCESS);
}

static void	move_w(t_exec *exec)
{
	exec->player_pos.x += exec->player_pos.dx / (SIZE_WALL / 10);
	exec->player_pos.y += exec->player_pos.dy / (SIZE_WALL / 10);
}

static void	move_s(t_exec *exec)
{	
	exec->player_pos.x -= exec->player_pos.dx / (SIZE_WALL / 10);
	exec->player_pos.y -= exec->player_pos.dy / (SIZE_WALL / 10);
}

static void	move_a(t_exec *exec)
{
	exec->player_pos.x -= cos(exec->player_pos.angle + (PI / 2));
	exec->player_pos.y -= sin(exec->player_pos.angle + (PI / 2));
}

static void	move_d(t_exec *exec)
{
	exec->player_pos.x += cos(exec->player_pos.angle + (PI / 2));
	exec->player_pos.y += sin(exec->player_pos.angle + (PI / 2));
}

