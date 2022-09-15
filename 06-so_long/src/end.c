/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:03:40 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/13 18:26:37 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
		free(data->map);
	if (data->valid_map)
	{
		while (i < data->map_y)
		{
			free(data->valid_map[i]);
			i++;
		}
		free(data->valid_map);
	}
	if (data->mlx)
		free_all_2(data);
	free(data);
}

void	free_all_2(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player_fr);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_b);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_window(data->mlx, data->window);
}

int	close_window(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	score(t_data *data)
{
	data->move_count_on_screen = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->window, 5, 30, 0xFFFFFF, \
	"Moves: ");
	mlx_string_put(data->mlx, data->window, 50, 30, 0xbe00ff, \
		data->move_count_on_screen);
	free(data->move_count_on_screen);
}
