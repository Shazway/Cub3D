/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:35:46 by tmoragli          #+#    #+#             */
/*   Updated: 2022/08/26 23:11:23 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c != 'N' && c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

int	check_elem(t_line *map, int x, int y, int map_size)
{
	if (map[y].line[x] != '1' && map[y].line[x] != '0'
		&& map[y].line[x] != ' ' && is_player(map[y].line[x]))
		return (printf("Error\nNot a valid map element: %c\n",
				map[y].line[x]));
	if (((map[y].line[x] == '0' || !is_player(map[y].line[x]))
			&& is_border(map, x, y, map_size)) || (((map[y].line[x] == '0'
					|| !is_player(map[y].line[x]))
				&& is_opened(map, x, y, map_size))))
		return (printf("Error\nMap is not closed at line: %d column: %d\n",
				y, x));
	return (0);
}

int	scan_map(t_line *map, t_data *data, int x, int y)
{
	while (y < data->m_info->size.y)
	{
		x = 0;
		while (map && map[y].line[x])
		{
			if (!is_player(map[y].line[x]))
			{
				data->player = point(x, y, map[y].line[x]);
				data->convert = point(data->player.x * SIZE + (SIZE / 2),
						data->player.y * SIZE + (SIZE / 2), 0);
				data->p_3d = point_3d(data->convert.x, data->convert.y);
				data->m_info->nb_player++;
			}
			if (data->m_info->nb_player > 1)
				return (printf("Error\nToo many player elements\n"));
			if (check_elem(map, x, y, data->m_info->size.y))
				return (1);
			x++;
		}
		y++;
	}
	if (data->m_info->nb_player < 1)
		return (printf("Error\nNo player on map, (N, S, W, E)\n"));
	return (0);
}

int	get_file(t_data *data, int fd)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	while (ret == 1)
	{
		ft_lstadd_back(&(data->m_info->map), ft_lstnew(line));
		ret = get_next_line(fd, &line);
	}
	ft_lstadd_back(&(data->m_info->map), ft_lstnew(line));
	if (ret == -1)
	{
		if (line)
			ft_lstclear(&data->m_info->map, &free);
		return (printf("Error\nMap file could not be opened\n"));
	}
	return (0);
}

int	parse_map(t_data *data, int fd)
{
	int		ret;

	ret = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("No map given, couldn't open file"));
	if (get_file(data, fd))
		return (1);
	if (is_valid_file(data))
		ret++;
	ft_lstclear(&data->m_info->map, &free);
	return (ret);
}
