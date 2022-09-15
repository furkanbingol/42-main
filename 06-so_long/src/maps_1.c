/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:01:17 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/12 20:10:12 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_data *data, char *file)
{
	int		fd;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error! File not found!\n", data);
	while (1)
	{	
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		data->map = join(data->map, tmp);
		free(tmp);
	}
	get_map_x_y(data);
	close(fd);
}

void	get_map_x_y(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != '\n')
		i++;
	data->map_x = i;
	data->map += data->map_x;
	i = 1;
	while ((*data->map) == '\n')
	{
		data->map += (data->map_x + 1);
		i++;
	}
	data->map_y = i;
	data->map -= (data->map_y * data->map_x + data->map_y - 1);
}

void	check_map_rectangular(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = data->map + data->map_x + 1;
	while (*tmp != '\0')
	{
		if (*tmp == '\n')
		{
			if (i != data->map_x)
				error("Error! The map must be rectangular!\n", data);
			i = 0;
		}
		else
			i++;
		tmp++;
	}
	if (i != data->map_x)
		error("Error! The map must be rectangular!\n", data);
}

void	check_map_wall(t_data *data)
{
	char	*tmp;
	int		j;

	tmp = data->map;
	j = 0;
	while (j < 2)
	{
		while (*tmp == '1')
			tmp++;
		if (*tmp == '\n' || *tmp == '\0')
		{
			if (*tmp == '\n')
				tmp += 1 + ((data->map_y - 2) * (data->map_x + 1));
		}
		else
			error("Error! The map must be surrounded by walls!\n", data);
		j++;
	}
	check_map_wall_2(data);
}

void	check_map_wall_2(t_data *data)
{
	char	*tmp;
	int		j;

	tmp = data->map;
	j = 0;
	while (j < data->map_y)
	{
		if (*tmp != '1' || (*(tmp + data->map_x - 1)) != '1')
			error("Error! The map must be surrounded by walls!\n", data);
		else
			tmp += data->map_x + 1;
		j++;
	}
}
