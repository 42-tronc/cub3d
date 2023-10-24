/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:37:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 14:30:35 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exec_manager(t_data *data)
{
	if (init_mlx(data) != SUCCESS)
		return (FAILURE);
	mlx_loop_hook(data->mlx_ptr, refresh_window, data);
	mlx_hook(data->window, 2, 1L << 0, moves, data);
	mlx_hook(data->window, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}
