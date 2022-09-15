/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:31:28 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/13 18:32:12 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber_extension(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str);
	if (i < 9 || str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
		error("Error! The map file must have .ber extension\n", data);
}

void	check_components(t_data *data)
{
	char		*tmp;
	static int	player = 0;
	static int	end = 0;
	static int	x = 0;
	static int	y = 0;

	tmp = data->map;
	while (*tmp)
	{
		if (*tmp == '\n')
		{
			y++;
			x = -1;
		}
		else if (*tmp == 'P')
		{
			data->player_x = x;
			data->player_y = y;
		}
		check_element(tmp, &player, &end, data);
		x++;
		tmp++;
	}
	check_atleast(data, &player, &end, &data->gold_number);
}

void	check_element(char *str, int *pl, int *end, t_data *data)
{
	if (*str == 'P')
		(*pl)++;
	else if (*str == 'E')
		(*end)++;
	else if (*str == 'C')
		data->gold_number++;
	else if (*str != '\n' && *str != '0' && *str != '1')
		error("Error! The map must include only /'P'/'E'/'C'/'1'/'0'/\n", data);
}

void	check_atleast(t_data *data, int *player, int *end, int *collectible)
{
	if (*player != 1 || *end != 1 || *collectible < 1)
		error("Error! The map must contain 1 exit, 1 starting position \
and at least 1 collectible!\n", data);
	else
	{
		data->player_x_64 = data->player_x * 64;
		data->player_y_64 = data->player_y * 64;
	}
}
