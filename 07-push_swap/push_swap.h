/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:19:39 by fbingol           #+#    #+#             */
/*   Updated: 2022/10/17 11:19:39 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		*a_s;
	int		*b_s;
	int		*sorted;
	int		ac;
	int		a_len;
	int		b_len;
	int		len;
	int		max_bit;
	char	*str;
	char	**numbers;
}	t_stack;

void	repeat_numbers(t_stack *data);
void	edit_stacks(t_stack *data);
void	check_numbers(t_stack *data);
void	error(t_stack *data);
void	error_without_free(void);
void	selection_sort(t_stack *data);
int		find_index(t_stack *data, int nbr);
int		space_null_control(char *str);
void	find_index2(t_stack *data);
void	sort_control(t_stack *data);
void	distribute_arg(t_stack *data);
void	argv_control(char **str);
void	ft_argv_together(t_stack *data, char *str);
void	helper(t_stack *data);
void	three(t_stack *data);
void	five(t_stack *data);
void	swap_a(t_stack *data);
void	swap_b(t_stack *data);
void	push_a(t_stack *data);
void	push_b(t_stack *data);
void	rotate_a(t_stack *data);
void	rotate_b(t_stack *data);
void	rev_rotate_a(t_stack *data);
void	find_maxbit(t_stack *data);
void	radix(t_stack *data);
void	ft_free(t_stack *data);
int		*push_up(int *arr, int len);
int		*push_down(int *arr, int len);
int		my_atoi(const char *str, t_stack *data);

#endif