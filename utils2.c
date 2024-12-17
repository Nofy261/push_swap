/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:10:03 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 17:03:13 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char **cut_argv, t_list *stack_a)
{
	write (2, "Error\n", 6);
	free_all(cut_argv);
	free_list(stack_a);
	exit(EXIT_FAILURE);
}

int	ft_atoi(char *str, t_list *stack_a, char **cut_argv)
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
	while (str[i] >= '0' && str[i] <= '9')
		stock = stock * 10 + (str[i++] - '0');
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

void	ft_putstr_fd(char	*s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
