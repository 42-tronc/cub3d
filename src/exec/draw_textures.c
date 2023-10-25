/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:55:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 16:15:36 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_pixel_in_texture(t_texture *texture, int x, int y);

void	draw_textures(t_data *data, int count, int i)
{
	char *s;

	s = get_pixel_in_texture(&data->north, count, i);
	
	put_pixel(&data->minimap, abs(count), i, *(unsigned int *)s);
	
}

static char	*get_pixel_in_texture(t_texture *texture, int x, int y)
{
	char	*dst;
	int		bit;

	bit = texture->bits_per_pixel / 8;
	dst = texture->addr + (y * texture->line_length + x * (bit));
	return (dst);
}