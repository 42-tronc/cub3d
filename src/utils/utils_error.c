/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:31:48 by croy              #+#    #+#             */
/*   Updated: 2023/10/22 18:51:52 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int code, char *src)
{
	char	*error[12];

	error[E_MALLOC] = "malloc failed to allocate a memory space";
	error[E_READ] = "read failed to read the file";
	error[E_MISSING] = "one map is required";
	error[E_EXT] = "file doesn't have the right extension";
	error[E_PROP_FMT] = "a property has the wrong format";
	error[E_PROP_DUP] = "a property is defined twice";
	error[E_PROP_VAR] = "a property type is unrecognized";
	error[E_MAP_MISS] = "map is missing";
	error[E_MAP_FMT] = "map's format is wrong";
	error[E_MAP_PLYR] = "game is single player";
	error[E_MAP_WALLS] = "map is not surrounded by walls";
	error[E_MAP_ISLAND] = "map has an island";
	if (src && ft_strlen(src))
		printf(RED BOLD"Error: %s%s in %s%s\n", NO_BOLD, error[code], src, RESET);
	else
		printf(RED BOLD"Error: %s%s%s\n", NO_BOLD, error[code], RESET);
}
