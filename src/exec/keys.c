/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:43:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/22 12:33:33 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	keys(int key_code, t_exec *exec)
{
	if (key_code == KEY_ESC)
		close_window(exec, SUCCESS);
	else if (key_code == KEY_W)
		draw_player(&exec->minimap, 2 - 1, 2);
	else if (key_code == KEY_A)
		draw_player(&exec->minimap, 2, 2 - 1);
	else if (key_code == KEY_S)
		draw_player(&exec->minimap, 2 + 1, 2);
	else if (key_code == KEY_D)
		draw_player(&exec->minimap, 2, 2 + 1);
	else if (key_code == LEFT_ARROW)
		printf("LEFT\n");
	else if (key_code == RIGHT_ARROW)
		printf("RIGHT\n");
	return (SUCCESS);
}

// loop hook ( ft refresh)
