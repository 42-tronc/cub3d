/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:37:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 11:15:07 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_manager(char *map)
{
	int			i;
	t_exec		exec;

	i = 0;
	exec.map = ft_split(map, '\n');
	if (!exec.map)
	{
		display_error(MALLOC_ERR);
		return (FAILURE);
	}
	if (init_mlx(&exec) != SUCCESS)
		return (FAILURE);
	if (minimap(&exec) != SUCCESS)
		return (FAILURE);
	mlx_hook(exec.window, 2, 1L << 0, moves, &exec);
	mlx_hook(exec.window, 17, 1L << 17, close_window, &exec);
	mlx_loop_hook(exec.mlx_ptr, refresh_window, &exec);
	mlx_loop(exec.mlx_ptr);
	return (SUCCESS);
}
