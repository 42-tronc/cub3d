/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hypotenuse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:44:38 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/21 12:53:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float get_hypotenuse2(t_ray *ray)
{
    float       hyp;
    float       x;
    float       y;

    x = ray->length.x * ray->length.x;
    y = ray->length.y * ray->length.y;
    hyp = sqrtf(x + y);
    return (hyp);
}

float get_hypotenuse(t_data *data, t_vector_float rotation)
{
    t_vector_float  ray;
    t_vector_float  tmp;
    float           hyp;

    hyp = 0;
    ray.x = data->player_pos.x * SIZE_WALL;
    ray.y = data->player_pos.y * SIZE_WALL;
    tmp.x = fabsf(ray.x - rotation.x);
    tmp.y = fabsf(ray.y - rotation.y);
    hyp = sqrtf(powf(tmp.x, 2) + powf(tmp.y, 2));
    return (hyp);
}
