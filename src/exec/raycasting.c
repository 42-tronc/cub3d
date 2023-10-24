/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:28:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 15:34:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int					i;
	float				angle;
	t_ray				ray;
	t_vector_float		direction;

	i = WIDTH;
	angle = data->player_pos.angle - (20.0 * RAD);
	while (i >= 0)
	{
		direction.x = cos(angle);
		direction.y = sin(angle);
		init_ray_struct(data, &ray, direction.x, direction.y);
		ft_dda(data, &ray);
		draw_walls(data, i, ray);
		angle += (RAD * (40.00 / (WIDTH)));
		i--;
	}
}
