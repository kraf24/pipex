/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:02:47 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/09 17:32:50 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dest1;
	size_t			counter;

	counter = 0;
	if (!dest && !src)
		return (NULL);
	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	while (counter < n)
	{
		dest1[counter] = src1[counter];
		counter++;
	}
	return (dest);
}
