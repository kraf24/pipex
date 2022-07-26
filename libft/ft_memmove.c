/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:46:23 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/09 17:25:58 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if ((dst == src || len == 0))
	{
		return (dst);
	}
	if (temp_src < temp_dst)
	{
		while (len --)
			*(temp_dst + len) = *(temp_src + len);
		return (dst);
	}
	while (len--)
	{
		*temp_dst++ = *temp_src++;
	}
	return (dst);
}
