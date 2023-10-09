/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:10:34 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 17:19:40 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_main **stack_A_main, t_main **stack_B_main)
{
	t_main	*stack_a;
	t_main	*stack_b;

	stack_a = *stack_A_main;
	stack_b = *stack_B_main;
	if (len_list(stack_a->head) > 5)
		radix_sort(&stack_a, &stack_b);
	else if (len_list(stack_a->head) == 3)
		sort_3(&stack_a);
	else if (len_list(stack_a->head) <= 5)
		simple_sort(&stack_a, &stack_b);
}

void	free_all(t_main **stack_A_main, t_main **stack_B_main,
		t_list_int **list_num, t_list_double_char **list_char)
{
	free_list_num(&(*list_num));
	free_list_double_char(&(*list_char));
	free_stack(&(*stack_A_main), &(*stack_B_main));
}

void	check_list_num(t_list_int **list_num_main,
		t_list_double_char **list_main)
{
	t_list_int			*list_num;
	t_list_double_char	*list;

	list_num = *list_num_main;
	list = *list_main;
	if (!list_num || check_it_seem(list_num))
	{
		free_list_double_char(&list);
		if (list_num)
			free_list_num(&list_num);
		exit_error();
	}
	if (check_sort_num(list_num) || size_list_num(list_num) == 1)
	{
		free_list_double_char(&list);
		free_list_num(&list_num);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	t_main				*stack_a;
	t_main				*stack_b;
	t_list_double_char	*list;
	t_list_int			*list_num;

	list = NULL;
	check_error_char(argv, argc);
	list = create_list_from_input(argv);
	if (!list)
		exit_error();
	list_num = create_list_num_from_list(list);
	check_list_num(&list_num, &list);
	stack_b = malloc(sizeof(t_main));
	stack_b->head = NULL;
	stack_a = ft_init(list_num);
	set_index(&stack_a);
	sort_all(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b, &list_num, &list);
	exit(EXIT_SUCCESS);
}
