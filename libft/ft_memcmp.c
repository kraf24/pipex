/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:33:03 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 16:16:16 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
		{
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		}
		str1++;
		str2++;
	}
	return (0);
}
