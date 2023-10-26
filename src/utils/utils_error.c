/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:31:48 by croy              #+#    #+#             */
/*   Updated: 2023/10/26 12:47:02 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_perr(int code, char *src)
{
	char	*error[13];

	error[E_MALLOC] = "malloc failed to allocate a memory space";
	error[E_READ] = "read failed to read the file";
	error[E_MISSING] = "file is missing";
	error[E_EXT] = "file doesn't have the right extension";
	error[E_PROP_FMT] = "a property has the wrong format";
	error[E_PROP_DUP] = "a property is defined twice";
	error[E_PROP_VAR] = "a property type is unrecognized";
	error[E_MAP_MISS] = "map is missing";
	error[E_MAP_FMT] = "map's format is wrong";
	error[E_MAP_PLYR] = "game is single player";
	error[E_MAP_WALLS] = "map is not surrounded by walls";
	error[E_MAP_ISLAND] = "map has an island";
	error[E_TXT_MISS] = "a texture is missing";
	if (src && ft_strlen(src))
		printf(RED BOLD"Error\n%s%s in %s%s\n", NO_BOLD, error[code], src, RESET);
	else
		printf(RED BOLD"Error\n%s%s%s\n", NO_BOLD, error[code], RESET);
}

void	print_exec_err(int code, char *src)
{
	char	*error[6];

	error[E_MLX_INIT] = "error during mlx init";
	error[E_WIN_INIT] = "error during window init";
	error[E_MINIMAP] = "error during minimap init";
	error[E_IMG] = "error during new image creation";
	error[E_ADDR] = "error during new data address creation";
	error[E_TEXTURES] = "error during init of the textures";
	if (src && ft_strlen(src))
		printf(RED BOLD"Error\n%s%s in %s%s\n", NO_BOLD, error[code], src, RESET);
	else
		printf(RED BOLD"Error\n%s%s%s\n", NO_BOLD, error[code], RESET);
}
