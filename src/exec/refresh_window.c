/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:05:16 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/17 15:17:47 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	refresh_window(t_exec *exec)
{
	mlx_destroy_image(exec->mlx_ptr, exec->minimap.img);
	exec->minimap.img = mlx_new_image(exec->mlx_ptr, WIDTH, HEIGHT);
	if (!exec->minimap.img)
		return (FAILURE);
	exec->minimap.addr = mlx_get_data_addr(exec->minimap.img, \
			&exec->minimap.bits_per_pixel, &exec->minimap.line_length, \
				&exec->minimap.endian);
	if (!exec->minimap.addr)
		return (FAILURE);
	draw_minimap(exec);
	draw_player_minimap(&exec->minimap, exec->player_pos.x, exec->player_pos.y);
	rays(exec, exec->player_pos.x, exec->player_pos.y);
	mlx_put_image_to_window(exec->mlx_ptr, exec->window, \
			exec->minimap.img, 0, 0);
	return (SUCCESS);
}
