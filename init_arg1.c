/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:29:18 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 15:32:12 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_int	*create_list_num_from_list(t_list_double_char *list)
{
	t_list_int			*list_num;
	t_check_error_num	checker;

	list_num = NULL;
	while (list)
	{
		checker.i = 0;
		while (list->content[checker.i])
		{
			checker.check_error = 0;
			if (create_list(list->content[checker.i], &list_num))
				return (NULL);
			checker.i++;
		}
		list = list->next;
	}
	return (list_num);
}
