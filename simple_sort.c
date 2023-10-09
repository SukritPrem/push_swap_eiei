/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:06 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 19:12:07 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_top_and_send_pb(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	size_t	size;
	int		*array;

	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	size = 0;
	while (size_array(stack_a->head) != 2)
	{
		stack_a->current = stack_a->head;
		size = size_array(stack_a->head);
		array = create_arr_in_list(&stack_a, size);
		bubblesort(array, size);
		if (stack_a->current->data < array[size / 2])
			pb(&stack_a, &(*stack_b_main));
		else
		{
			free(array);
			break ;
		}
		free(array);
	}
	if (size_array(stack_a->head) == 2)
		check_sort_for_sa(&stack_a);
}

void	find_bottom_and_send_pb(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	size_t	size;
	int		*array;
	int		mid_value;

	stack_a = *stack_a_main;
	stack_a->current = stack_a->end;
	size = 0;
	while (size_array(stack_a->head) != 2)
	{
		size = size_array(stack_a->head);
		array = create_arr_in_list(&stack_a, size);
		bubblesort(array, size);
		mid_value = array[size / 2];
		if (stack_a->current->data < mid_value)
			command_rra_and_pb(&stack_a, &(*stack_b_main));
		else
		{
			free(array);
			break ;
		}
		free(array);
	}
	if (size_array(stack_a->head) == 2)
		check_sort_for_sa(&stack_a);
}

void	find_rb_and_send_pb(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	size_t	size;
	int		*array;
	int		mid_value;

	stack_a = *stack_a_main;
	stack_a->current = stack_a->head;
	size = 0;
	while (size_array(stack_a->head) != 2)
	{
		size = size_array(stack_a->head);
		array = create_arr_in_list(&stack_a, size);
		bubblesort(array, size);
		mid_value = array[size / 2];
		if (stack_a->current->data < mid_value)
			pb(&stack_a, &(*stack_b_main));
		else
			ra(&stack_a);
		free(array);
		if (size_array(stack_a->head) == 2)
			break ;
	}
	if (size_array(stack_a->head) == 2)
		check_sort_for_sa(&stack_a);
}

void	find_top_rb_and_send_pa(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_b;
	size_t	size;
	int		*array;
	int		mid_value;

	stack_b = *stack_b_main;
	stack_b->current = stack_b->head;
	size = 0;
	while (size != 2)
	{
		stack_b->current = stack_b->head;
		size = size_array(stack_b->head);
		if (size == 2)
			break ;
		array = create_arr_in_list(&stack_b, size);
		bubblesort(array, size);
		mid_value = array[size / 2];
		if (stack_b->current->data > mid_value)
			pa(&(*stack_a_main), &stack_b);
		else
			rb(&stack_b);
		check_sort_for_sa(&(*stack_a_main));
		free(array);
	}
	check_sort_for_sb_and_papa(&(*stack_a_main), &stack_b);
}

void	simple_sort(t_main **stack_a_main, t_main **stack_b_main)
{
	t_main	*stack_a;
	t_main	*stack_b;

	stack_a = *stack_a_main;
	stack_b = *stack_b_main;
	find_top_and_send_pb(&stack_a, &stack_b);
	if (check_sort(&stack_a))
		find_bottom_and_send_pb(&stack_a, &stack_b);
	if (check_sort(&stack_a))
		find_rb_and_send_pb(&stack_a, &stack_b);
	if (stack_b->head)
		find_top_rb_and_send_pa(&stack_a, &stack_b);
}
