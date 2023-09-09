/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:41:53 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 11:19:30 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	close_window(t_exec *exec, int status)
{
	free_map(exec->map);
	mlx_clear_window(exec->mlx_ptr, exec->window);
	mlx_destroy_window(exec->mlx_ptr, exec->window);
	mlx_destroy_image(exec->mlx_ptr, exec->minimap.img);
	mlx_destroy_display(exec->mlx_ptr);
	free(exec->mlx_ptr);
	close_fd();
	if (status == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
