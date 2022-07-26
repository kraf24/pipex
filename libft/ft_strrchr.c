/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:29:47 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 17:48:52 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*b;

	count = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			b = (char *)s;
			++count;
		}
		s++;
	}
	if (count > 0)
	{
		return (b);
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
