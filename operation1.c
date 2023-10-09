/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:51 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 18:40:20 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_main **stack_b_main)
{
	t_main	*stack_b;

	write(1, "rb\n", 3);
	stack_b = *stack_b_main;
	if (stack_b->head)
	{
		stack_b->current = stack_b->head;
		stack_b->end->next = stack_b->current;
		stack_b->head = stack_b->head->next;
		stack_b->end = stack_b->end->next;
		stack_b->end->next = NULL;
	}
}

void	sb(t_main **stack_a_main)
{
	t_main		*stack_a;
	t_list_p	*tmp;

	write(1, "sb\n", 3);
	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	if (stack_a->current->next == NULL)
		tmp = NULL;
	else
		tmp = stack_a->current->next;
	stack_a->head = stack_a->head->next;
	stack_a->head->next = stack_a->current;
	stack_a->current->next = tmp;
}
