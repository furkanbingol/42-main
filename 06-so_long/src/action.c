/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:12:59 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/13 18:21:28 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keycode, t_data *data)
{
	check_up(keycode, data);
	check_down(keycode, data);
	check_right(keycode, data);
	check_left(keycode, data);
	if (keycode == 53)
	{
		close_window(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	check_up(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		if (is_valid_movement(data, data->player_x_64 / 64, \
			(data->player_y_64 - 64) / 64))
		{
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = '0';
			data->player_y_64 -= 64;
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = 'P';
			data->curr_pos = 'B';
			mlx_put_image_to_window(data->mlx, data->window, data->player_b, \
				data->player_x_64 / 64, data->player_y_64 / 64);
			render_after_move(data);
		}
	}
}

void	check_down(int keycode, t_data *data)
{
	if (keycode == 1)
	{
		if (is_valid_movement(data, data->player_x_64 / 64, \
			(data->player_y_64 + 64) / 64))
		{
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = '0';
			data->player_y_64 += 64;
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = 'P';
			data->curr_pos = 'F';
			mlx_put_image_to_window(data->mlx, data->window, data->player_fr, \
				data->player_x_64 / 64, data->player_y_64 / 64);
			render_after_move(data);
		}
	}
}

void	check_right(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		if (is_valid_movement(data, (data->player_x_64 + 64) / 64, \
			data->player_y_64 / 64))
		{
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = '0';
			data->player_x_64 += 64;
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = 'P';
			data->curr_pos = 'R';
			mlx_put_image_to_window(data->mlx, data->window, data->player_r, \
				data->player_x_64 / 64, data->player_y_64 / 64);
			render_after_move(data);
		}
	}
}

void	check_left(int keycode, t_data *data)
{
	if (keycode == 0)
	{
		if (is_valid_movement(data, (data->player_x_64 - 64) / 64, \
			data->player_y_64 / 64))
		{
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = '0';
			data->player_x_64 -= 64;
			data->valid_map[data->player_y_64 / 64]
			[data->player_x_64 / 64] = 'P';
			data->curr_pos = 'L';
			mlx_put_image_to_window(data->mlx, data->window, data->player_l, \
				data->player_x_64 / 64, data->player_y_64 / 64);
			render_after_move(data);
		}
	}
}
