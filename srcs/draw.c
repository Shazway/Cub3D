/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:21:03 by tmoragli          #+#    #+#             */
/*   Updated: 2022/08/23 20:53:36 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall(t_data *data, int i)
{
	data->ray->wall = i;
	data->text[i].size = point(data->text[i].size.x, data->text[i].size.y, 0);
}

void	draw_pixel(t_data *d, int x, int y, t_rgb color)
{
	if (x >= 0 && x < d->screen->size.x && y >= 0 && y < d->screen->size.y)
		d->screen->draw[y * (int)d->screen->size.x + x] = color;
}

void	draw_texture(t_data *data, t_pos pos, t_rgb color, int size)
{
	double	x;
	double	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (x == 0 || x == size - 1 || y == 0 || y == size - 1)
				draw_pixel(data, x + pos.x, y + pos.y, data->c_palette->black);
			else
				draw_pixel(data, x + pos.x, y + pos.y, color);
			x++;
		}
		y++;
	}
}

void	draw_ray(t_data *data, t_pos start, t_ray *ray, double ray_angle)
{
	double	t;
	double	length;

	t = ray_angle;
	ray->x_dir = cos(t);
	ray->y_dir = sin(t);
	ray->x = start.x;
	ray->y = start.y;
	length = 0;
	while (length < 8000
		&& get_dist(start, point(ray->x, ray->y, 0)) < ray->length)
	{
		draw_pixel(data, ray->x, ray->y, data->ray->wall_color);
		ray->y += ray->y_dir;
		ray->x += ray->x_dir;
		length++;
	}
}

void	map_fill(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->m_info->size.y)
	{
		x = 0;
		while (data->map[y].line[x])
		{	
			if (data->map[y].line[x] == '1')
				draw_texture(data, point(x * SIZE, y * SIZE, 0),
					data->m_info->floor_color, SIZE);
			if (data->map[y].line[x] == '0' || !is_player(data->map[y].line[x]))
				draw_texture(data, point(x * SIZE, y * SIZE, 0),
					data->m_info->ceiling_color, SIZE);
			x++;
		}
		y++;
	}
	draw_texture(data, point((data->convert.x - 8),
			(data->convert.y - 8), 0), data->c_palette->red, 16);
	raycasting(data, point(data->convert.x, data->convert.y, 0), NB_RAYS);
}
