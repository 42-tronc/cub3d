/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:39:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 14:04:40 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	init_minimap(t_exec *exec);

int	init_mlx(t_exec *exec)
{
	exec->mlx_ptr = mlx_init();
	if (!exec->mlx_ptr)
	{
		free_map(exec->map);
		display_error("during Minilib init.\n");
		return (FAILURE);
	}
	exec->window = mlx_new_window(exec->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!exec->window)
	{
		free_map(exec->map);
		free_mlx(exec);
		display_error("during window init.\n");
		return (FAILURE);
	}
	if (init_minimap(exec) != SUCCESS)
	{
		free_map(exec->map);
		free_window(exec);
		free_mlx(exec);
		display_error("during minimap init.\n");
		return (FAILURE);
	}
	get_player_pos(exec, exec->map);
	return (SUCCESS);
}

static int	init_minimap(t_exec *exec)
{
	exec->minimap.img = mlx_new_image(exec->mlx_ptr, WIDTH, HEIGHT);
	if (!exec->minimap.img)
		return (FAILURE);
	exec->minimap.addr = mlx_get_data_addr(exec->minimap.img, \
			&exec->minimap.bits_per_pixel, &exec->minimap.line_length, \
				&exec->minimap.endian);
	if (!exec->minimap.addr)
	{
		mlx_destroy_image(exec->mlx_ptr, exec->minimap.img);
		return (FAILURE);
	}
	return (SUCCESS);
}
