/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:21:16 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 15:40:31 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t size)
{
	size_t			count;
	unsigned char	*temp;

	count = 0;
	temp = (unsigned char *)b;
	while (count < size)
	{
		temp[count] = c;
		count++;
	}
	return (temp);
}
