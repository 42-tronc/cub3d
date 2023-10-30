/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:55:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 10:59:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*choose_pixel_textures(t_data *data, t_ray *ray, int y);
static char	*get_pixel_in_texture(t_texture *texture, int x, int y);

char	*draw_textures(t_data *data, t_ray *ray, int y)
{
	char	*dst;

	dst = choose_pixel_textures(data, ray, y);
	return (dst);
}

static char	*choose_pixel_textures(t_data *data, t_ray *ray, int y)
{
	char			*dst;
	float			height;
	float			t_x;
	t_texture		texture;

	height = (WALL_H / ray->length);
	texture.addr = NULL;
	texture.height = 0;
	texture.width = 0;
	texture.bits_per_pixel = 0;
	texture.line_length = 0;
	texture.endian = 0;
	if (ray->cardinal == NORTH)
		texture = data->west;
	else if (ray->cardinal == SOUTH)
		texture = data->east;
	else if (ray->cardinal == WEST)
		texture = data->south;
	else if (ray->cardinal == EAST)
		texture = data->north;
	// t_x = fabs((ray->collision - (int)ray->collision) * texture.height);
	// t_x = texture.width - 1 - fabs((ray->collision - (int)ray->collision) * texture.width); // flips the problem (left is good here)
	if (ray->cardinal == EAST || ray->cardinal == SOUTH)
		t_x = ray->collision - floor(ray->collision);
	else

	t_x *= texture.width;
	if (EYE_SIGHT - height / 2 < 0)
		y = y - (EYE_SIGHT - height / 2);
	y = y * (texture.height / height);
	// y = texture.height - (y * (texture.height / height));
	// y = texture.height - 1 - (y * (texture.height / height));
	dst = get_pixel_in_texture(&texture, t_x, y);
	return (dst);
}

static char	*get_pixel_in_texture(t_texture *texture, int x, int y)
{
	char	*dst;
	int		bit;

	bit = texture->bits_per_pixel / 8;
	dst = texture->addr + (y * texture->line_length + x * (bit));
	return (dst);
}