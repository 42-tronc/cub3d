/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:05:16 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/21 13:23:02 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void error_refresh_window(t_exec *exec, int status);

int	refresh_window(t_exec *exec)
{
	mlx_destroy_image(exec->mlx_ptr, exec->minimap.img);
	exec->minimap.img = mlx_new_image(exec->mlx_ptr, WIDTH, HEIGHT);
	if (!exec->minimap.img)
		error_refresh_window(exec, IMG_ERR);
	exec->minimap.addr = mlx_get_data_addr(exec->minimap.img, \
			&exec->minimap.bits_per_pixel, &exec->minimap.line_length, \
				&exec->minimap.endian);
	if (!exec->minimap.addr)
		error_refresh_window(exec, 0);
	//raycasting_2(exec, exec->player_pos.x, exec->player_pos.y);
	raycasting(exec);
	draw_minimap(exec);
	draw_player_minimap(&exec->minimap, exec->player_pos.x, exec->player_pos.y);
	mlx_put_image_to_window(exec->mlx_ptr, exec->window, \
			exec->minimap.img, 0, 0);
	return (SUCCESS);
}

static void error_refresh_window(t_exec *exec, int status)
{
	free_map(exec->map);
	mlx_clear_window(exec->mlx_ptr, exec->window);
	mlx_destroy_window(exec->mlx_ptr, exec->window);
	if (status != IMG_ERR)
		mlx_destroy_image(exec->mlx_ptr, exec->minimap.img);
	mlx_destroy_display(exec->mlx_ptr);
	free(exec->mlx_ptr);
	close_fd();
	exit(FAILURE);
}
