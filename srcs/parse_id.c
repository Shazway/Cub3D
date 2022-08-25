/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:42:03 by nargouse          #+#    #+#             */
/*   Updated: 2022/08/25 03:08:11 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_id(char *str)
{
	if (str && (ft_strncmp(str, "NO ", 3) && ft_strncmp(str, "WE ", 3)
			&& ft_strncmp(str, "EA ", 3) && ft_strncmp(str, "SO ", 3)
			&& ft_strncmp(str, "C ", 2) && ft_strncmp(str, "F ", 2)))
		return (ft_printf("Error\nNot a valid identifier: %s\n", str));
	return (0);
}

t_list	*is_valid_id(t_list *file_line, t_data *data)
{
	int		elems;
	char	*line;
	int		i;

	i = 0;
	elems = 0;
	while (file_line && elems < 6)
	{
		line = file_line->content;
		if (line && line[0] == ' ')
		{
			i = 1;
			line = ft_strtrim(line, " \t\r\v\f\n");
		}
		if (check_id(line))
			return (NULL);
		else
			stock_element(data, &elems, line);
		if (i)
		{
			free(line);
			i = 0;
			line = NULL;
		}
		file_line = file_line->next;
	}
	if (elems != 6)
	{
		ft_printf("Error\nNot all elements were disposed, missing %d\n",
			6 - elems);
		return (NULL);
	}
	return (file_line);
}
