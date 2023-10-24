/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:31:48 by croy              #+#    #+#             */
/*   Updated: 2023/10/24 08:46:10 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_perr(int code, char *src)
{
	char	*error[13];

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
	error[E_TXT_MISS] = "a texture is missing";
	if (src && ft_strlen(src))
		printf(RED BOLD"Error\n%s%s in %s%s\n", NO_BOLD, error[code], src, RESET);
	else
		printf(RED BOLD"Error\n%s%s%s\n", NO_BOLD, error[code], RESET);
}

void	print_exec_err(int code, char *src)
{
	char	*error[5];

	error[E_MLX_INIT] = "error during mlx init";
	error[E_WIN_INIT] = "error during window init";
	error[E_MINIMAP] = "error during minimap init";
	error[E_IMG] = "error during new image creation";
	error[E_ADDR] = "error during new data address creation";
	if (src && ft_strlen(src))
		printf(RED BOLD"Error\n%s%s in %s%s\n", NO_BOLD, error[code], src, RESET);
	else
		printf(RED BOLD"Error\n%s%s%s\n", NO_BOLD, error[code], RESET);
}
