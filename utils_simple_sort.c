/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simple_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:19:22 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 18:53:31 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_rra_and_pb(t_main **stack_A_main, t_main **stack_B_main)
{
	t_main	*stack_a;

	stack_a = *stack_A_main;
	rra(&stack_a);
	pb(&stack_a, &(*stack_B_main));
	stack_a->current = stack_a->end;
}

void	check_sort_for_sa(t_main **stack_A_main)
{
	t_main	*stack_a;

	stack_a = *stack_A_main;
	stack_a->current = stack_a->head;
	if (stack_a->current->data > stack_a->current->next->data)
		sa(&stack_a);
}

void	check_sort_for_sb_and_papa(t_main **stack_A_main, t_main **stack_B_main)
{
	t_main	*stack_b;

	stack_b = *stack_B_main;
	stack_b->current = stack_b->head;
	if (size_array(stack_b->head) != 1)
	{
		if (stack_b->current->data < stack_b->current->next->data)
			sb(&stack_b);
	}
	check_sort_for_sa(&(*stack_A_main));
	pa(&(*stack_A_main), &stack_b);
	check_sort_for_sa(&(*stack_A_main));
	pa(&(*stack_A_main), &stack_b);
}
