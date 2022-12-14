/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:42:18 by nargouse          #+#    #+#             */
/*   Updated: 2022/08/27 20:42:29 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_player_pos(double t, t_data *d, t_pos dir, int speed)
{
	double	v_x;
	double	v_y;

	v_x = cos(t);
	v_y = sin(t);
	d->player.x = (int)d->convert.x / SIZE;
	d->player.y = (int)d->convert.y / SIZE;
	increment_pos(d, (v_x * speed) * (dir.x),
		(v_y * speed) * (dir.y));
}
