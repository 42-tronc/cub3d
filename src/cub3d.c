/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:57:54 by croy              #+#    #+#             */
/*   Updated: 2023/10/23 16:59:40 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int			exit_code;
	t_data		data;

	exit_code = EXIT_SUCCESS;
	if (ac != 2)
		return (print_perr(E_MISSING, NULL), EXIT_FAILURE);
	if (map_parsing(&data, av[1]))
		exit_code = EXIT_FAILURE;
	if (!exit_code && exec_manager(&data) != SUCCESS)
		exit_code = EXIT_FAILURE;
	free_data(&data);
	return (exit_code);
}
