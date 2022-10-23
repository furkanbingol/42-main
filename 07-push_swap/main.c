/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:19:07 by fbingol           #+#    #+#             */
/*   Updated: 2022/10/17 11:19:07 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_control(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (str[i])
	{
		if (!ft_strlen(str[i]) || !space_null_control(str[i]))
			exit(EXIT_FAILURE);
		j = 0;
		count = 0;
		while (str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
				count++;
			j++;
		}
		if (count == 0)
			error_without_free();
		i++;
	}
}

int	space_null_control(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	helper(t_stack *data)
{
	data->numbers = ft_split(data->str, ' ');
	check_numbers(data);
	edit_stacks(data);
	repeat_numbers(data);
	sort_control(data);
	selection_sort(data);
	distribute_arg(data);
	ft_free(data);
}

void	ft_argv_together(t_stack *data, char *str)
{
	char		*temp;
	static int	j = 0;

	temp = ft_strjoin(data->str, str);
	while (temp[j])
	{
		data->str[j] = temp[j];
		j++;
	}
	free(temp);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*data;

	if (argc < 2)
		exit(EXIT_FAILURE);
	argv_control(argv);
	i = 1;
	data = malloc(sizeof(t_stack));
	data->ac = argc - 1;
	data->str = argv[1];
	while (data->ac >= ++i)
		ft_argv_together(data, argv[i]);
	helper(data);
	return (0);
}
