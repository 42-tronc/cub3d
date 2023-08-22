/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:53:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/22 12:19:16 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x <= 0 && x > WIDTH) && !(y <= 0 && y > HEIGHT))
	{
		dst = data->addr + (y * data->line_length + x * \
				(data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}
