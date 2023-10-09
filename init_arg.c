/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:18 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 16:24:22 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_double_char	*init_char(char **argv, int i)
{
	t_list_double_char	*list;

	list = malloc(sizeof(t_list_double_char));
	if (!list)
		return (NULL);
	list->content = ft_split(argv[i], ' ');
	list->next = NULL;
	return (list);
}

int	create_list_char(char **argv, int i, t_list_double_char **list_main)
{
	t_list_double_char	*list;
	t_list_double_char	*tmp;
	t_list_double_char	*tmp_list;

	list = *list_main;
	tmp_list = list;
	if (!list)
	{
		list = init_char(argv, i);
		if (!list)
			return (1);
		tmp_list = list;
		*list_main = list;
	}
	else
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp = init_char(argv, i);
		if (!tmp)
			return (free_list_double_char(&list), 1);
		tmp_list->next = tmp;
		tmp_list = tmp;
	}
	return (0);
}

t_list_double_char	*create_list_from_input(char *argv[])
{
	t_list_double_char	*list;
	int					i;

	list = NULL;
	i = 1;
	while (argv[i])
	{
		if (create_list_char(argv, i, &list))
			return (NULL);
		i++;
	}
	return (list);
}

t_list_int	*init_list_num(char *content)
{
	t_list_int	*list_num;
	int			number;
	int			check_error;

	list_num = malloc(sizeof(t_list_int));
	if (!list_num)
		return (NULL);
	number = ft_atoi_pushswap(content, &(check_error));
	if (!check_error)
	{
		free(list_num);
		return (NULL);
	}
	list_num->num = number;
	list_num->next = NULL;
	return (list_num);
}

int	create_list(char *content, t_list_int **list_num_main)
{
	t_list_int	*tmp_num;
	t_list_int	*tmp_list_num;
	t_list_int	*list_num;

	list_num = *list_num_main;
	tmp_list_num = list_num;
	if (!list_num)
	{
		list_num = init_list_num(content);
		if (!list_num)
			return (1);
		*list_num_main = list_num;
	}
	else
	{
		while (tmp_list_num->next)
			tmp_list_num = tmp_list_num->next;
		tmp_num = init_list_num(content);
		if (!tmp_num)
			return (free_list_num(&list_num), 1);
		tmp_list_num->next = tmp_num;
	}
	return (0);
}
