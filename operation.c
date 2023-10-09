/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:48:10 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 17:54:43 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	t_main	*stack_b;

	stack_a = *stack_a_main;
	stack_b = *stack_b_main;
	stack_a->current = stack_a->head;
	write(1, "pb\n", 3);
	if (!stack_b->head)
	{
		stack_b->head = stack_a->head;
		stack_a->head = stack_a->head->next;
		stack_b->head->next = NULL;
		stack_b->end = stack_b->head;
		*stack_b_main = stack_b;
	}
	else
		utils_pb(&stack_a, &stack_b);
	stack_b->current = stack_b->head;
	stack_a->current = stack_a->head;
	*stack_b_main = stack_b;
}

void	ra(t_main **stack_a_main)
{
	t_main	*stack_a;

	write(1, "ra\n", 3);
	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->end->next = stack_a->current;
	stack_a->current->next = NULL;
	stack_a->end = stack_a->current;
	stack_a->current = stack_a->head;
	*stack_a_main = stack_a;
}

void	pa(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	t_main	*stack_b;

	stack_a = *stack_a_main;
	stack_b = *stack_b_main;
	if (stack_b->head)
	{
		write(1, "pa\n", 3);
		stack_a->current = stack_a->head;
		stack_b->current = stack_b->head;
		stack_b->head = stack_b->head->next;
		stack_b->current->next = stack_a->head;
		stack_a->head = stack_b->current;
		stack_b->current = stack_b->head;
	}
}

void	sa(t_main **stack_a_main)
{
	t_main		*stack_a;
	t_list_p	*tmp;

	write(1, "sa\n", 3);
	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	if (stack_a->current->next->next == NULL)
		tmp = NULL;
	else
		tmp = stack_a->current->next->next;
	stack_a->head = stack_a->head->next;
	stack_a->head->next = stack_a->current;
	stack_a->current->next = tmp;
}

void	rra(t_main **stack_a_main)
{
	t_main		*stack_a;
	t_list_p	*tmp;

	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	tmp = stack_a->end;
	write(1, "rra\n", 4);
	while (stack_a->current)
	{
		if (stack_a->current->next->next == NULL)
		{
			stack_a->current->next = NULL;
			stack_a->end = stack_a->current;
			break ;
		}
		stack_a->current = stack_a->current->next;
	}
	tmp->next = stack_a->head;
	stack_a->head = tmp;
	stack_a->current = stack_a->end;
}
