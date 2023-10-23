/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:37:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/20 10:30:17 by lboulatr         ###   ########.fr       */
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

void	display_error(char *str)
{
	ft_putstr_fd("\033[41m", STDERR_FILENO);
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
}
