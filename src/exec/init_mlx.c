/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:39:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 14:36:31 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_minimap(t_data *data);

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		print_exec_err(E_MLX_INIT, "in init_mlx");
		return (FAILURE);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		free_mlx(data);
		print_exec_err(E_MLX_INIT, "in init_mlx");
		return (FAILURE);
	}
	if (init_minimap(data) != SUCCESS)
	{
		free_window(data);
		free_mlx(data);
		print_exec_err(E_MLX_INIT, "in init_mlx");
		return (FAILURE);
	}
	init_player(data, data->map->array);
	return (SUCCESS);
}

static int	init_minimap(t_data *data)
{
	data->minimap.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->minimap.img)
		return (FAILURE);
	data->minimap.addr = mlx_get_data_addr(data->minimap.img, \
			&data->minimap.bits_per_pixel, &data->minimap.line_length, \
				&data->minimap.endian);
	if (!data->minimap.addr)
	{
		mlx_destroy_image(data->mlx_ptr, data->minimap.img);
		return (FAILURE);
	}
	return (SUCCESS);
}
