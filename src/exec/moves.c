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

static void	move_w(t_data *data);
static void	move_a(t_data *data);
static void	move_s(t_data *data);
static void	move_d(t_data *data);

int	moves(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		close_window(data, SUCCESS);
	else if (key_code == KEY_W)
		move_w(data);
	else if (key_code == KEY_A)
		move_a(data);
	else if (key_code == KEY_S)
		move_s(data);
	else if (key_code == KEY_D)
		move_d(data);
	else if (key_code == LEFT_ARROW)
		rotation(data, key_code);
	else if (key_code == RIGHT_ARROW)
		rotation(data, key_code);
	return (SUCCESS);
}

static void	move_w(t_data *data)
{
	data->player_pos.x += data->player_pos.dx / (SIZE_WALL / 10);
	data->player_pos.y += data->player_pos.dy / (SIZE_WALL / 10);
}

static void	move_s(t_data *data)
{
	data->player_pos.x -= data->player_pos.dx / (SIZE_WALL / 10);
	data->player_pos.y -= data->player_pos.dy / (SIZE_WALL / 10);
}

static void	move_a(t_data *data)
{
	data->player_pos.x -= cos(data->player_pos.angle + (PI / 2));
	data->player_pos.y -= sin(data->player_pos.angle + (PI / 2));
}

static void	move_d(t_data *data)
{
	data->player_pos.x += cos(data->player_pos.angle + (PI / 2));
	data->player_pos.y += sin(data->player_pos.angle + (PI / 2));
}
