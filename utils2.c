/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:10:03 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/15 19:06:18 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	long	stock;

	i = 0;
	sign = 1;
	stock = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
		{
			write (2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		stock = stock * 10 + (str[i] - '0');
		i++;
	}
	stock *= sign;
	if (!(stock > -2147483649 && stock < 2147483648))
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
		
	}
	if (str[i] != '\0')
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
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