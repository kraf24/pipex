/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:20:27 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 18:42:58 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	a;
	size_t	b;

	i = ft_strlen(dst);
	a = ft_strlen(src);
	k = 0;
	b = i;
	if (size == 0)
		return (a);
	if (size < b)
		return (a + size);
	while (src[k] != '\0' && (i + 1) < size)
	{
		dst[i++] = src[k++];
	}
	dst[i] = '\0';
	return (a + b);
}
