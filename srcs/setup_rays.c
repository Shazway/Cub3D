/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:13:23 by tmoragli          #+#    #+#             */
/*   Updated: 2022/08/27 19:21:06 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_h_ray_data(t_ray *ray, t_pos start, int facing)
{
	double	atang;

	atang = -1 / tan(ray->angle);
	if (facing)
	{
		ray->y = (((int)start.y / SIZE_3D) * SIZE_3D) - 0.0001;
		ray->x = (start.y - ray->y) * atang + start.x;
		ray->y_dir = -SIZE_3D;
		ray->x_dir = (ray->y_dir * -1) * atang;
	}
	else
	{
		ray->y = (((int)start.y / SIZE_3D) * SIZE_3D) + SIZE_3D;
		ray->x = (start.y - ray->y) * atang + start.x;
		ray->y_dir = SIZE_3D;
		ray->x_dir = (ray->y_dir * -1) * atang;
	}
}

void	setup_v_ray_data(t_ray *ray, t_pos start, int facing)
{
	double	atang;

	atang = tan(ray->angle) * -1;
	if (facing)
	{
		ray->x = (((int)start.x / SIZE_3D) * SIZE_3D) - 0.0001;
		ray->y = (start.x - ray->x) * atang + start.y;
		ray->x_dir = -SIZE_3D;
		ray->y_dir = (ray->x_dir * -1) * atang;
	}
	else
	{
		ray->x = (((int)start.x / SIZE_3D) * SIZE_3D) + SIZE_3D;
		ray->y = (start.x - ray->x) * atang + start.y;
		ray->x_dir = SIZE_3D;
		ray->y_dir = (ray->x_dir * -1) * atang;
	}
}

void	reset_ray_data(t_ray *ray, t_pos start, int *dof)
{
	ray->x = start.x;
	ray->y = start.y;
	*dof = 2000;
}
