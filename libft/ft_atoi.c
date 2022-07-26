/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:54:05 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/10 18:34:04 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chek_minus(const char *str, int *num)
{
	while (str[*num] >= 0 && (str[*num] == 32 || str[*num] == '\t'
			|| str[*num] == '\n' || str[*num] == '\r'
			|| str[*num] == '\v' || str[*num] == '\f'))
	{
		++*num;
	}
	if (str[*num] == '-')
	{
		++*num;
		return (1);
	}
	else if (str[*num] == '+')
	{
		++*num;
		return (0);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	num;
	int	b;

	a = 0;
	num = 0;
	b = chek_minus(str, &num);
	while (str[num] != '\0')
	{
		if (str[num] > '9' || str[num] < '0')
		{
			break ;
		}
		a = (a * 10) + (str[num] - '0');
		++num;
	}
	if (b == 1)
	{
		a = (-1) * a;
	}
	return (a);
}
