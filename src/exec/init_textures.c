/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:06 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 10:25:47 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_textures_is_init(t_data *data);

int	init_textures(t_data *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->north.path, &data->north.height, &data->north.width);
	data->south.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->south.path, &data->south.height, &data->south.width);
	data->west.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->west.path, &data->west.height, &data->west.width);
	data->east.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->east.path, &data->east.height, &data->east.width);
	if (check_textures_is_init(data) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int	check_textures_is_init(t_data *data)
{
	if (!data->north.img || !data->south.img || \
		!data->west.img || !data->east.img)
	{
		print_exec_err(E_TEXTURES, "check_textures_is_init");
		close_window(data, FAILURE);
		return (FAILURE);
	}
	return (SUCCESS);
}