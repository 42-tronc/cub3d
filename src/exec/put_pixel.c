/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:53:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 09:00:14 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	put_pixel(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x <= 0 || x >= WIDTH) || (y <= 0 || y >= HEIGHT))
		return ;
	dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
