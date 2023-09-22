/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:45:07 by croy              #+#    #+#             */
/*   Updated: 2023/09/22 14:46:07 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void	free_if_alloc(char *string)
{
	if (string)
	{
		free(string);
		string = NULL;
	}
}

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}

void	free_data(t_data *data)
{
	free_if_alloc(data->file);
	free_tab(data->split_file);
	free_if_alloc(data->north.path);
	close_fd(data->north.fd);
	free_if_alloc(data->south.path);
	close_fd(data->south.fd);
	free_if_alloc(data->west.path);
	close_fd(data->east.fd);
	free_if_alloc(data->east.path);
	close_fd(data->west.fd);
	free(data);
}
