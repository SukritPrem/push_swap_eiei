/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:36:56 by spipitku          #+#    #+#             */
/*   Updated: 2023/10/09 19:08:44 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static long long	found_9_to_13(const char *str)
{
	long long	i;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	return (i);
}

static int	check_plus_or_neg(long long *sum, long long i, const char *str)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sum = *sum * (-1);
		i++;
	}
	return (i);
}

int	check_error_atoi(int *check_error, long long sum_ans)
{
	*check_error = 0;
	return ((int)(sum_ans));
}

int	ft_atoi_pushswap(const char *str, int *check_error)
{
	long long	i;
	long long	sum;
	long long	sum_ans;

	sum_ans = 0;
	sum = 1;
	i = found_9_to_13(str);
	i = check_plus_or_neg(&sum, i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		*check_error = *check_error + 1;
		sum_ans = sum_ans * 10 + (str[i++] - '0') * sum;
		if (sum_ans > 2147483647)
			return (check_error_atoi(&(*check_error), sum_ans));
		else if (sum_ans <= -2147483649)
			return (check_error_atoi(&(*check_error), sum_ans));
	}
	if (str[i] == '-' || str[i] == '+')
		return (check_error_atoi(&(*check_error), sum_ans));
	return ((int)(sum_ans));
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d",ft_atoi("++7-9"));
// }
