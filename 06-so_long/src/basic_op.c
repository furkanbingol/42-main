/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:28:19 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/12 20:03:39 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_x_y(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

void	x_y_operation(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*y += 64;
		*x = -64;
	}
	*x += 64;
}

int	is_valid_movement(t_data *data, int x, int y)
{
	if (data->valid_map[y][x] != '1')
	{
		if (data->valid_map[y][x] == 'C')
		{
			data->gold_number--;
			data->valid_map[y][x] = '0';
		}
		if (!data->gold_number && data->valid_map[y][x] == 'E')
		{
			ft_printf("Moves: %d\nCongrats!\n", ++data->move_count);
			end_game(data);
			return (1);
		}
		if (data->valid_map[y][x] == 'E')
			return (0);
		ft_printf("Moves: %d\n", ++data->move_count);
		return (1);
	}
	return (0);
}

void	render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	put_image(data);
}

char	*join(char *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (ft_strdup(""));
		if (!s1)
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	i = -1;
	j = -1;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		if (s2[j] != 13)
			newstr[i++] = s2[j];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
