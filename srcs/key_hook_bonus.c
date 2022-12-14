/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:48:28 by nargouse          #+#    #+#             */
/*   Updated: 2022/08/27 21:14:48 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	act_keypress(t_data *data)
{
	if (data->keys.l_arr)
		move_player(XK_Left, data);
	if (data->keys.r_arr)
		move_player(XK_Right, data);
	if (data->keys.w)
		move_player(XK_W, data);
	if (data->keys.s)
		move_player(XK_S, data);
	if (data->keys.a)
		move_player(XK_A, data);
	if (data->keys.d)
		move_player(XK_D, data);
	raycasting(data, point(data->p_3d.x, data->p_3d.y, 0), NB_RAYS);
	minimap(data, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->screen->img, 0, 0);
	return (0);
}

int	hook_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		printf("Game closed\n");
		mlx_loop_end(data->mlx);
		return (0);
	}
	if (keycode == XK_M || keycode == XK_m)
		data->keys.map = !data->keys.map;
	if (keycode == XK_W || keycode == XK_w
		|| keycode == XK_Z || keycode == XK_z)
		data->keys.w = !data->keys.w;
	if (keycode == XK_S || keycode == XK_s)
		data->keys.s = !data->keys.s;
	if (keycode == XK_A || keycode == XK_a
		|| keycode == XK_q || keycode == XK_Q)
		data->keys.a = !data->keys.a;
	if (keycode == XK_D || keycode == XK_d)
		data->keys.d = !data->keys.d;
	if (keycode == XK_Left)
		data->keys.l_arr = !data->keys.l_arr;
	if (keycode == XK_Right)
		data->keys.r_arr = !data->keys.r_arr;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys.shift = !data->keys.shift;
	return (0);
}
