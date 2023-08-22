/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:43:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/22 14:36:10 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	move_w(t_exec *exec);
static void	move_a(t_exec *exec);
static void	move_s(t_exec *exec);
static void	move_d(t_exec *exec);

int	keys(int key_code, t_exec *exec)
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
		printf("LEFT\n");
	else if (key_code == RIGHT_ARROW)
		printf("RIGHT\n");
	return (SUCCESS);
}

static void	move_w(t_exec *exec)
{
	if (exec->player_pos.x > 0)
		exec->player_pos.x--;
	draw_player(&exec->minimap, exec->player_pos.x, exec->player_pos.y);
}

static void	move_a(t_exec *exec)
{
	if (exec->player_pos.y > 0)
		exec->player_pos.y--;
	draw_player(&exec->minimap, exec->player_pos.x, exec->player_pos.y);
}

static void	move_s(t_exec *exec)
{
	exec->player_pos.x++;
	draw_player(&exec->minimap, exec->player_pos.x, exec->player_pos.y);
}

static void	move_d(t_exec *exec)
{
	exec->player_pos.y++;
	draw_player(&exec->minimap, exec->player_pos.x, exec->player_pos.y);
}
