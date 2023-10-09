/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:57:10 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 17:00:31 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_arg(char **argv, int i, int j, t_check_error *check)
{
	if (!argv[i][j])
		exit_error();
	while (argv[i][j])
	{
		if ((ft_isdigit(argv[i][j]) || argv[i][j] == '+' || argv[i][j] == '-'
				|| argv[i][j] == ' '))
		{
			if (ft_isdigit(argv[i][j]))
				check->count_number = 1;
		}
		else
			exit_error();
		j++;
	}
	if (!check->count_number)
		exit_error();
}

void	check_error_char(char **argv, int argc)
{
	int				i;
	int				j;
	t_check_error	check;

	i = 0;
	j = 0;
	check.count_number = 0;
	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 1;
	while (argv[i])
	{
		j = 0;
		check.count_number = 0;
		check_arg(argv, i, j, &check);
		i++;
	}
}

int	check_it_seem(t_list_int *list_num)
{
	int			check_value;
	t_list_int	*tmp;
	t_list_int	*start;
	int			member;

	member = 0;
	check_value = 0;
	tmp = list_num;
	start = list_num;
	while (list_num)
	{
		check_value = list_num->num;
		member = 0;
		while (tmp)
		{
			if (check_value == tmp->num)
				member++;
			tmp = tmp->next;
		}
		if (member > 1)
			return (1);
		tmp = start;
		list_num = list_num->next;
	}
	return (0);
}

int	check_sort_num(t_list_int *list_num)
{
	t_list_int	*tmp;

	tmp = list_num;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
