/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:39:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/08 15:41:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	init_minimap(t_exec *exec);
static void	get_player_pos(t_exec *exec, char **map);

int	init_mlx(t_exec *exec)
{
	exec->mlx_ptr = mlx_init();
	if (!exec->mlx_ptr)
	{
		display_error("Error during Minilib init.\n");
		return (FAILURE);
	}
	exec->window = mlx_new_window(exec->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!exec->window)
	{
		free_mlx(exec);
		display_error("Error during window init.\n");
		return (FAILURE);
	}
	if (init_minimap(exec) != SUCCESS)
		return (FAILURE);
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
		return (FAILURE);
	return (SUCCESS);
}

static void	get_player_pos(t_exec *exec, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				exec->player_pos.x = (float)i;
				exec->player_pos.y = (float)j;
				exec->player_pos.dx = (float)i;
				exec->player_pos.dy = (float)j;
				exec->player_pos.angle = PI;
				return ;
			}
			j++;
		}
		i++;
	}
}
