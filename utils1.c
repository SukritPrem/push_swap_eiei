/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:20:25 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/08 19:43:01 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_b_to_a(t_main **stack_B_main, t_main **stack_A_main)
{
	t_main	*stack_a;
	t_main	*stack_b;

	stack_a = *stack_A_main;
	stack_b = *stack_B_main;
	stack_a->current = stack_a->head;
	stack_b->current = stack_b->head;
	while (stack_b->current)
		pa(&stack_a, &stack_b);
}

int	check_sort(t_main **stack_A_main)
{
	t_main		*stack_a;
	t_list_p	*tmp;

	stack_a = *stack_A_main;
	tmp = stack_a->head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

size_t	size_array(t_list_p *head)
{
	size_t		i;
	t_list_p	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

size_t	size_list_num(t_list_int *head)
{
	size_t		i;
	t_list_int	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	*create_arr_in_list(t_main **stack_A_main, size_t num)
{
	t_main		*stack_a;
	t_list_p	*tmp;
	int			*mid_value;

	stack_a = *stack_A_main;
	tmp = stack_a->head;
	mid_value = malloc(sizeof(int) * num);
	num = 0;
	while (tmp)
	{
		mid_value[num++] = tmp->data;
		tmp = tmp->next;
	}
	return (mid_value);
}
