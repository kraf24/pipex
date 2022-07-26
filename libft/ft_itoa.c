/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:09:03 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 17:29:21 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sub_print(long nb, char *res, int len, int neg)
{
	if (nb != 0)
		res = malloc(sizeof(char) * (len + 1));
	else
		return (res = ft_strdup("0"));
	if (!res)
		return (NULL);
	if (neg)
		nb = -nb;
	res[len] = '\0';
	while (--len)
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg == 1)
		res[0] = '-';
	else
		res[0] = (nb % 10) + '0';
	return (res);
}

static int	ft_size(long n, int *neg)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		*neg = 1;
		n *= -1;
	}
	while (n >= 1)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	n1;
	char	*res;
	int		size;
	int		neg;

	res = NULL;
	n1 = n;
	neg = 0;
	size = ft_size(n1, &neg);
	res = sub_print(n1, res, size, neg);
	if (!res)
		return (0);
	return (res);
}
