/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:16:23 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/13 13:41:25 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_maze(t_data *data)
{
	data->valid_map = ft_split(data->map, '\n');
	data->tmp_number = data->gold_number;
}

void	check_is_valid_map(t_data *data, int x, int y)
{
	char	*point;

	point = &data->valid_map[y][x];
	if (*point == 'E')
		data->map_is_true = 1;
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			data->tmp_number--;
		*point = '.';
		if (data->valid_map[y][x + 1] != '1'
		&& data->valid_map[y][x + 1] != '.')
			check_is_valid_map(data, x + 1, y);
		if (data->valid_map[y][x - 1] != '1'
		&& data->valid_map[y][x - 1] != '.')
			check_is_valid_map(data, x - 1, y);
		if (data->valid_map[y + 1][x] != '1'
		&& data->valid_map[y + 1][x] != '.')
			check_is_valid_map(data, x, y + 1);
		if (data->valid_map[y - 1][x] != '1'
		&& data->valid_map[y - 1][x] != '.')
			check_is_valid_map(data, x, y - 1);
	}
}

void	check_can_all_collectible(t_data *data)
{
	int	i;

	i = 0;
	if (data->tmp_number != 0)
		error("Error! The map is invalid! \
All collectibles must be collectible!\n", data);
	else
	{
		while (i < data->map_y)
		{
			free(data->valid_map[i]);
			i++;
		}
		free(data->valid_map);
		data->valid_map = ft_split(data->map, '\n');
	}
}

void	check_can_reach_to_exit(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	if (data->map_is_true == 0)
		error("Error! The map is invalid! \
Player cannot reach to the exit in valid way!\n", data);
	else
	{
		while (i < data->map_y)
		{
			free(data->valid_map[i]);
			i++;
		}
		free(data->valid_map);
		data->valid_map = ft_split(data->map, '\n');
	}
}
