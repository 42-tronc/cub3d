/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:06 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 10:48:56 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	north_texture(t_data *data);
static int	south_texture(t_data *data);
static int	west_texture(t_data *data);
static int	east_texture(t_data *data);

int	init_textures(t_data *data)
{
	if (north_texture(data) != SUCCESS)
		return (FAILURE);
	if (south_texture(data) != SUCCESS)
		return (FAILURE);
	if (west_texture(data) != SUCCESS)
		return (FAILURE);
	if (east_texture(data) != SUCCESS)
		return (FAILURE);
	if (check_textures_is_init(data) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int	north_texture(t_data *data)
{
	data->north.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->north.img)
		return (FAILURE);
	data->north.addr = mlx_get_data_addr(data->north.img, \
			&data->north.bits_per_pixel, &data->north.line_length, \
				&data->north.endian);
	if (!data->north.addr)
	{
		mlx_destroy_image(data->mlx_ptr, data->north.img);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	south_texture(t_data *data)
{
	data->south.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->south.img)
		return (FAILURE);
	data->south.addr = mlx_get_data_addr(data->south.img, \
			&data->south.bits_per_pixel, &data->south.line_length, \
				&data->south.endian);
	if (!data->south.addr)
	{
		mlx_destroy_image(data->mlx_ptr, data->south.img);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	west_texture(t_data *data)
{
	data->west.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->west.img)
		return (FAILURE);
	data->west.addr = mlx_get_data_addr(data->west.img, \
			&data->west.bits_per_pixel, &data->west.line_length, \
				&data->west.endian);
	if (!data->west.addr)
	{
		mlx_destroy_image(data->mlx_ptr, data->west.img);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	east_texture(t_data *data)
{
	data->east.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->east.img)
		return (FAILURE);
	data->east.addr = mlx_get_data_addr(data->east.img, \
			&data->east.bits_per_pixel, &data->east.line_length, \
				&data->east.endian);
	if (!data->east.addr)
	{
		mlx_destroy_image(data->mlx_ptr, data->east.img);
		return (FAILURE);
	}
	return (SUCCESS);
}