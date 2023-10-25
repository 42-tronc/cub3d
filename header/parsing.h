/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:53 by croy              #+#    #+#             */
/*   Updated: 2023/10/25 14:18:31 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

//	===== @functions =====
// check_islands.c
int		check_map_vert_island(t_data *data);

// check_map.c
int		check_map(t_data *data);
int		check_map_walls(t_data *data);

// parse_file.c
int		check_extension(char *path, char *ext);
char	*read_file(int fd);
int		check_file(t_data *data, char *path);
int		cleanup_file(t_data *data);

// parse_map.c
int		get_map(t_data *data);

// parse_properties.c
int		get_map_properties(t_data *data);

#endif
