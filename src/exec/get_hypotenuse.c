/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hypotenuse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:44:38 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/17 15:45:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float getHypotenuse(t_exec *exec, t_vector_float rotation)
{
    t_vector_float  ray;
    t_vector_float  tmp;
    float           hyp;
    
    hyp = 0;
    ray.x = exec->player_pos.x * SIZE_MAP;
    ray.y = exec->player_pos.y * SIZE_MAP;
    tmp.x = fabsf(ray.x - rotation.x);
    tmp.y = fabsf(ray.y - rotation.y);
    hyp = sqrtf(powf(tmp.x, 2) + powf(tmp.y, 2));
    return (hyp);    
}