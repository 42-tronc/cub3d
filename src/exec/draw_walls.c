/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 09:17:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	get_textures(t_data *data, t_ray *ray, int count, int i);
// static void init_textures(t_data *data);

void    draw_walls(t_data *data, t_ray *ray, int width)
{
	int			i;
	float		wall_height;
	
	i = 0;
	if (ray->length <= 0)
		ray->length = 0.0886f;
	wall_height = WALL_H / ray->length;
	while (i < (HEIGHT / 2) - (wall_height / 2))
	{
		put_pixel(&data->minimap, abs(width), i, BLUE_HEX);
		i++;
	}
	while (i < (HEIGHT / 2) + (wall_height / 2))
	{
		if (ray->cardinal == NORTH)
			put_pixel(&data->minimap, abs(width), i, W_WHITE);
		if (ray->cardinal == SOUTH)
			put_pixel(&data->minimap, abs(width), i, E_GREEN);
		if (ray->cardinal == WEST)
			put_pixel(&data->minimap, abs(width), i, S_BROWN);
		if (ray->cardinal == EAST)
			put_pixel(&data->minimap, abs(width), i, N_RED);
		// get_textures(data, &ray, abs(width), i);
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, abs(width), i, GREY_HEX);
		i++;
	}
}

// static void	get_textures(t_data *data, t_ray *ray, int count, int i)
// {
// 	init_textures(data);
	
// 	if (ray->cardinal == NORTH)
// 		put_pixel(&data->minimap, abs(count), i, W_WHITE);
// 	if (ray->cardinal == SOUTH)
// 		put_pixel(&data->minimap, abs(count), i, E_GREEN);
// 	if (ray->cardinal == WEST)
// 		put_pixel(&data->minimap, abs(count), i, S_BROWN);
// 	if (ray->cardinal == EAST)
// 		put_pixel(&data->minimap, abs(count), i, N_RED);
// }

// static void init_textures(t_data *data)
// {
// 	(void)data;
// 	printf("data->north.path = %s\n", data->north.path);
// 	data->north.img = mlx_xpm_file_to_image(data->mlx_ptr, \
// 		"./textures/checker_north.xpm", &data->north.width, &data->north.height);
// 	if (!data->north.img)
// 		return ;
// }