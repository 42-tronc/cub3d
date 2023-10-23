/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:37:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 09:27:14 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_mlx(t_exec *exec)
{
	mlx_destroy_display(exec->mlx_ptr);
	free(exec->mlx_ptr);
}

void	free_window(t_exec *exec)
{
	mlx_clear_window(exec->mlx_ptr, exec->window);
	mlx_destroy_window(exec->mlx_ptr, exec->window);
}

void	close_fds(void)
{
	int		i;

	i = 0;
	while (i <= 1023)
	{
		close(i);
		i++;
	}
}
