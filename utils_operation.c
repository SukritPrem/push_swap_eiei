/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:44:26 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 18:45:23 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	utils_pb(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	t_main	*stack_b;

	stack_a = *stack_a_main;
	stack_b = *stack_b_main;
	if (stack_b->head && stack_a->head)
	{
		stack_b->current = stack_b->head;
		stack_a->current = stack_a->head;
		stack_a->head = stack_a->head->next;
		stack_b->head = stack_a->current;
		stack_b->head->next = stack_b->current;
	}
}
