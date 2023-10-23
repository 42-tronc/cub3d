/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:41:53 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 08:58:05 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	close_window(t_data *data, int status)
{
	free_array(data->map->array);
	mlx_clear_window(data->mlx_ptr, data->window);
	mlx_destroy_window(data->mlx_ptr, data->window);
	mlx_destroy_image(data->mlx_ptr, data->minimap.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	close_fds();
	if (status == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
