/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:10:18 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 11:11:27 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_double_char(t_list_double_char **list_main)
{
	t_list_double_char	*list;
	t_list_double_char	*tmp;
	int					i;

	i = 0;
	list = *list_main;
	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		i = 0;
		while (list->content[i])
			free(list->content[i++]);
		free(list->content);
		free(list);
		list = tmp;
	}
}

void	free_list_num(t_list_int **list_num_main)
{
	t_list_int	*list_num;
	t_list_int	*tmp_num;

	list_num = *list_num_main;
	tmp_num = NULL;
	while (list_num)
	{
		tmp_num = list_num->next;
		free(list_num);
		list_num = tmp_num;
	}
}

void	free_stack(t_main **stack_A_main, t_main **stack_B_main)
{
	t_main		*stack_a;
	t_main		*stack_b;
	t_list_p	*tmp;

	stack_a = *stack_A_main;
	stack_b = *stack_B_main;
	stack_a->current = stack_a->head;
	stack_b->current = stack_b->head;
	while (stack_a->current)
	{
		tmp = stack_a->current->next;
		free(stack_a->current);
		stack_a->current = tmp;
	}
	free(stack_a);
	free(stack_b);
}
