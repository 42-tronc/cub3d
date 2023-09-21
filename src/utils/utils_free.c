/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:45:07 by croy              #+#    #+#             */
/*   Updated: 2023/09/21 15:30:10 by croy             ###   ########lyon.fr   */
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

void	free_data(t_data *data)
{
	free_if_alloc(data->file);
	free_tab(data->split_file);
	free(data);
}
