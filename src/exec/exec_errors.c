/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:42:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 11:00:26 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	display_error(char *str)
{
	ft_putstr_fd("\033[41m", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
}

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
