/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:24:32 by tmoragli          #+#    #+#             */
/*   Updated: 2022/08/23 20:54:28 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos(double pos)
{
	return ((pos - SIZE / 2) / SIZE);
}

double	get_rad(double angle)
{
	return (angle * PI / 180);
}

double	get_dist(t_pos start, t_pos end)
{
	return (sqrt((start.x - end.x) * (start.x - end.x)
			+ (start.y - end.y) * (start.y - end.y)));
}

double	change_rad_angle(double angle, double iterate, char iterator)
{
	if (iterator == '+')
	{
		if (angle + iterate < PI * 2)
			return (angle + iterate);
		else if (angle + iterate >= PI * 2)
			return (angle + iterate - PI * 2);
	}
	if (iterator == '-')
	{
		if (angle - iterate > 0)
			return (angle - iterate);
		else if (angle - iterate <= 0)
			return ((PI * 2) + angle - iterate);
	}
	return (angle);
}

double	change_angle(double angle, double iterate, char iterator)
{
	if (iterator == '+')
	{
		if (angle + iterate < 360)
			return (angle + iterate);
		else if (angle + iterate >= 360)
			return (angle + iterate - 360);
	}
	if (iterator == '-')
	{
		if (angle - iterate > 0)
			return (angle - iterate);
		else if (angle - iterate <= 0)
			return (360 + angle - iterate);
	}
	return (angle);
}
