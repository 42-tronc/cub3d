/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:37:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 12:42:46 by lboulatr         ###   ########.fr       */
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
