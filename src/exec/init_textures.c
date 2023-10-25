/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:06 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 11:20:14 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int init_texture(t_data *data, t_texture *texture);

int	init_all_textures(t_data *data)
{
	int		status;

	status = SUCCESS;
	if (init_texture(data, &data->north) != SUCCESS)
		status = FAILURE;
	if (init_texture(data, &data->south) != SUCCESS)
		status = FAILURE;
	if (init_texture(data, &data->west) != SUCCESS)
		status = FAILURE;
	if (init_texture(data, &data->east) != SUCCESS)
		status = FAILURE;
	if (check_textures_is_init(data, status) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int init_texture(t_data *data, t_texture *texture)
{
	texture->img = mlx_new_image(data->mlx_ptr, texture->width, texture->height);
	if (!texture)
		return (SUCCESS);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
		&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		mlx_destroy_image(data->mlx_ptr, texture->img);
		texture->img = NULL;
		return (FAILURE);
	}
	return (SUCCESS);
}
