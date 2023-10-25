/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:45:07 by croy              #+#    #+#             */
/*   Updated: 2023/10/25 10:25:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_if_alloc(char *string)
{
	if (string)
	{
		free(string);
		string = NULL;
	}
}

void	free_array(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free_if_alloc(tab[i++]);
	free(tab);
	tab = NULL;
}

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}

void	free_data(t_data *data)
{
	free_if_alloc(data->file);
	free_array(data->split_file);
	free_if_alloc(data->north.path);
	close_fd(data->north.fd);
	free_if_alloc(data->south.path);
	close_fd(data->south.fd);
	free_if_alloc(data->west.path);
	close_fd(data->west.fd);
	free_if_alloc(data->east.path);
	close_fd(data->east.fd);
	close_fds();
	if (data->map)
	{
		free_array(data->map->array);
		free(data->map);
	}
}

void	clear_textures(t_data *data)
{
	if (data->north.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->north.img);
		data->north.img = NULL;
	}
	if (data->south.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->south.img);
		data->south.img = NULL;
	}
	if (data->west.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->west.img);
		data->west.img = NULL;
	}
	if (data->east.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->east.img);
		data->east.img = NULL;
	}
}
