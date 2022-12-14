/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:23:04 by tmoragli          #+#    #+#             */
/*   Updated: 2022/08/25 03:35:31 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures_data(t_data *data)
{
	assign_text(data, 0, data->m_info->no_path);
	assign_text(data, 1, data->m_info->so_path);
	assign_text(data, 2, data->m_info->we_path);
	assign_text(data, 3, data->m_info->ea_path);
}

void	init_mlx_data(t_data *data, int trash)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game(data, "No screen link couldn't operate MLX", 0);
	init_textures_data(data);
	data->screen->size.y = HEIGHT_3D;
	data->screen->size.x = WIDTH_3D;
	data->win = mlx_new_window(data->mlx, data->screen->size.x,
			data->screen->size.y, "cub3D");
	if (!data->win)
		exit_game(data, "Could not create window", 0);
	data->screen->img = mlx_new_image(data->mlx,
			data->screen->size.x, data->screen->size.y);
	data->screen->addr = mlx_get_data_addr(data->screen->img,
			&trash, &trash, &trash);
	if (!data->screen->img || !data->screen->addr)
		exit_game(data, "Could not create a new image or get address", 0);
	data->screen->draw = (t_rgb *)data->screen->addr;
}

void	init_game_data(t_data *data, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	if (allocate_game_data(data, av) == 1)
		exit_game(data, "Failed malloc allocation, exiting", 1);
	init_subdata(data);
}
