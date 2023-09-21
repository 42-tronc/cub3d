/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:57:54 by croy              #+#    #+#             */
/*   Updated: 2023/09/21 12:29:57 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_data(t_data *data)
{
	free(data->file);
	free(data);
}

int	main(int ac, char **av)
{
	int		exit_code;
	t_data	*data;

	exit_code = EXIT_SUCCESS;
	if (ac != 2)
		return (print_error(E_MISSING, NULL), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (print_error(E_MALLOC, "main"), EXIT_FAILURE);
	if (map_parsing(data, av[1]))
		exit_code = EXIT_FAILURE;
	free_data(data);
	return (exit_code);
}
