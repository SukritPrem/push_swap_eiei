/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:52:35 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/08 19:17:16 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_main	*ft_init(t_list_int *tmp_int)
{
	t_main		*stack_a;
	t_list_p	*stack;
	t_list_p	*tmp;
	t_list_p	*tmp_clone;

	stack_a = malloc(sizeof(t_main));
	stack = NULL;
	while (tmp_int)
	{
		tmp = stack;
		if (!stack)
			stack = init(tmp_int->num);
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp_clone = init(tmp_int->num);
			tmp->next = tmp_clone;
		}
		tmp_int = tmp_int->next;
	}
	stack_a->head = stack;
	stack_a->end = tmp_clone;
	return (stack_a);
}

t_list_p	*init(int num)
{
	t_list_p	*stack;

	stack = malloc(sizeof(t_list_p));
	stack->data = num;
	stack->next = NULL;
	stack->index = 0;
	return (stack);
}

int	max_in_list(t_list_p *head)
{
	int	max;

	max = 0;
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int	len_list(t_list_p *head_main)
{
	int			i;
	t_list_p	*head;
	t_list_p	*tmp;

	head = head_main;
	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	set_index(t_main **stack_A_main)
{
	t_main		*stack_a;
	int			min;
	t_list_p	*tmp;
	int			i;
	int			j;

	i = 1;
	stack_a = *stack_A_main;
	stack_a->current = stack_a->head;
	j = len_list(stack_a->current);
	while (j--)
	{
		stack_a->current = stack_a->head;
		min = max_in_list(stack_a->current);
		while (stack_a->current)
		{
			if (stack_a->current->data <= min && stack_a->current->index == 0)
			{
				tmp = stack_a->current;
				min = tmp->data;
			}
			stack_a->current = stack_a->current->next;
		}
		tmp->index = i++;
	}
}
