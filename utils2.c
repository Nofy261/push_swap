/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:10:03 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/19 13:36:43 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	parse_number(char *str, int *i, t_list **stack_a, char **cut_argv)
{
	long	stock;
	int		countnumber;

	stock = 0;
	countnumber = 0;
	while (str[*i] == '0')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		countnumber++;
		stock = stock * 10 + (str[*i] - '0');
		if (countnumber > 10)
			print_error(cut_argv, stack_a);
		(*i)++;
	}
	return (stock);
}

int	ft_parse_long(char *str, t_list **stack_a, char **cut_argv)
{
	int		i;
	int		sign;
	long	stock;

	i = 0;
	sign = 1;
	stock = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			print_error(cut_argv, stack_a);
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	stock = parse_number(str, &i, stack_a, cut_argv);
	stock *= sign;
	if (!(stock > -2147483649 && stock < 2147483648) || str[i] != '\0')
		print_error(cut_argv, stack_a);
	return (stock);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
