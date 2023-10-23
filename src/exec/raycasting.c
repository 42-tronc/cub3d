/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:28:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/23 09:34:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void check_wall(t_exec *exec, t_ray *ray);
static void draw_lines(t_exec *exec, t_ray *ray, int i);

void	raycasting(t_exec *exec)
{
	int					i;
	float				angle;
	t_ray				ray;
	t_vector_float		direction;

	i = 0;
	angle = exec->player_pos.angle - (20.0 * RAD);
	init_ray_struct(exec, &ray);
	while (i < WIDTH)
	{
		direction.x = cos(angle);
		direction.y = sin(angle);
		ft_dda(exec, ray, direction);
		check_wall(exec, &ray);
		draw_lines(exec, &ray, line);
		draw_walls(exec, line, ray);
		i++;
		angle += (RAD * (40.00 / (WIDTH)));
	}
}


static void check_wall(t_exec *exec, t_ray *ray)
{
	while (ray->hit_wall != SUCCESS)
	{
		if (ray->length.x < ray->length.y)
		{
			ray->map_check.x += ray->step.x;
			ray->length.x += ray->delta.x;
			//printf("ray->length.x : %f\n", ray->length.x);
			ray->side = 0;
		}
		else
		{
			ray->map_check.y += ray->step.y;
			ray->length.y += ray->delta.y;
			//printf("ray->length.y : %f\n", ray->length.y);
			ray->side = 1;
		}
		printf("\nray->map_check.x = %d\n", ray->map_check.x);
		printf("ray->map_check.y = %d\n\n", ray->map_check.y);
		if (exec->map[ray->map_check.x][ray->map_check.y] && exec->map[ray->map_check.x][ray->map_check.y] == '1')
			ray->hit_wall = SUCCESS;
	}
}

static void draw_lines(t_exec *exec, t_ray *ray, int i)
{
	(void) exec;
	(void) i;
	if (ray->side == 0)
		ray->wall_dist = fabs(ray->length.x - ray->delta.x);
	else
		ray->wall_dist = fabs(ray->length.y - ray->delta.y);
	//printf("ray->wall_dist = %f\n", ray->wall_dist);
}