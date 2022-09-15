/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:01:21 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/04 14:01:21 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define PL_FR "./src/images/player_front.xpm"
# define PL_LEFT "./src/images/player_left.xpm"
# define PL_RIGHT "./src/images/player_right.xpm"
# define PL_BACK "./src/images/player_back.xpm"
# define EXIT "./src/images/exit.xpm"
# define COLLECTIBLE "./src/images/collectible.xpm"
# define WALL "./src/images/wall.xpm"
# define GROUND "./src/images/ground.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*ground;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player_fr;
	void	*player_r;
	void	*player_l;
	void	*player_b;
	char	curr_pos;
	char	*map;
	char	**valid_map;
	char	*move_count_on_screen;
	int		imgx;
	int		imgy;
	int		map_is_true;
	int		map_x;
	int		map_y;
	int		gold_number;
	int		tmp_number;
	int		move_count;
	int		point;
	int		player_x;
	int		player_y;
	int		player_x_64;
	int		player_y_64;
}	t_data;

void	make_map(t_data *data, char *file);
void	get_map_x_y(t_data *data);

void	check_map_rectangular(t_data *data);
void	check_map_wall(t_data *data);
void	check_map_wall_2(t_data *data);
void	check_ber_extension(char *str, t_data *data);
void	check_components(t_data *data);
void	check_element(char *str, int *pl, int *end, t_data *data);
void	check_atleast(t_data *data, int *player, int *end, int *collectible);
void	check_is_valid_map(t_data *data, int x, int y);
void	copy_maze(t_data *data);
void	check_can_all_collectible(t_data *data);
void	check_can_reach_to_exit(t_data *data, int x, int y);

void	init_image(t_data *data);
void	init_x_y(int *x, int *y);
void	x_y_operation(int *x, int *y, t_data *data);
char	*join(char *s1, char const *s2);
void	put_image(t_data *data);
void	put_image_player(t_data *data, int x, int y);
int		key_event(int keycode, t_data *data);
void	check_up(int keycode, t_data *data);
void	check_down(int keycode, t_data *data);
void	check_right(int keycode, t_data *data);
void	check_left(int keycode, t_data *data);
int		is_valid_movement(t_data *data, int x, int y);
void	render_after_move(t_data *data);
void	score(t_data *data);
int		close_window(t_data *data);
void	end_game(t_data *data);
void	free_all(t_data *data);
void	free_all_2(t_data *data);

void	error(char *str, t_data *data);

#endif