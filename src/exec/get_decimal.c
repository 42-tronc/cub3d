/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:02:15 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/05 14:04:34 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float   get_decimal(float fl)
{
    float   decimal;

    decimal = fl - (int)fl;
    return (decimal);
}