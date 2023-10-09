/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:01:19 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 19:14:37 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_main **stack_a_main)
{
	t_main	*stack_a;
	int		y;
	int		z;

	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	y = stack_a->current->next->data;
	z = stack_a->current->next->next->data;
	if (stack_a->current->data > y && stack_a->current->data < z && y < z)
		sa(&stack_a);
	else if (stack_a->current->data > y && stack_a->current->data > z && y > z)
	{
		sa(&stack_a);
		rra(&stack_a);
	}
	else if (stack_a->current->data > y && stack_a->current->data > z && y < z)
		ra(&stack_a);
	else if (stack_a->current->data < y && stack_a->current->data < z && y > z)
	{
		sa(&stack_a);
		ra(&stack_a);
	}
	else if (stack_a->current->data < y && stack_a->current->data > z && y > z)
		rra(&stack_a);
}
