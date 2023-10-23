/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:45:07 by croy              #+#    #+#             */
/*   Updated: 2023/09/25 15:42:15 by croy             ###   ########lyon.fr   */
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
	close_fd(data->east.fd);
	free_if_alloc(data->east.path);
	close_fd(data->west.fd);
	if (data->map)
	{
		free_array(data->map->array);
		free(data->map);
	}
	// if (data->player) // FIXME
	// 	free(data->player); // FIXME
	free(data);
}
