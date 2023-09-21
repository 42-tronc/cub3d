/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:31:48 by croy              #+#    #+#             */
/*   Updated: 2023/09/21 12:29:31 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int code, char *src)
{
	char	*error[3];

	error[E_MALLOC] = "malloc failed to allocate a memory space";
	error[E_MISSING] = "one map is required";
	error[E_EXT] = "file doesn't have the right extension";
	if (src && ft_strlen(src))
		printf(RED BOLD"Error: %s%s in %s%s\n", NO_BOLD, error[code], src, RESET);
	else
		printf(RED BOLD"Error: %s%s%s\n", NO_BOLD, error[code], RESET);
}
