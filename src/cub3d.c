/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:57:54 by croy              #+#    #+#             */
/*   Updated: 2023/09/18 12:49:54 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac > 2 || ac < 2)
	{
		printf("We need one map\n");
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (print_error(E_MALLOC, "main"), EXIT_FAILURE);
	if (map_parsing(data, av[1]))
		return (1);
	return (0);
}
