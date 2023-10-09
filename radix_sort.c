/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:37:19 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 18:55:30 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	t_main	*stack_b;
	int		loop;
	int		i;

	stack_a = *stack_a_main;
	stack_b = *stack_b_main;
	stack_a->current = stack_a->head;
	stack_b->current = stack_b->head;
	i = 0;
	while (check_sort(&stack_a))
	{
		loop = len_list(stack_a->head);
		while (loop--)
		{
			stack_a->current = stack_a->head;
			if (((stack_a->current->index >> i) & 1))
				ra(&stack_a);
			else
				pb(&stack_a, &stack_b);
		}
		i++;
		send_b_to_a(&stack_b, &stack_a);
	}
}
