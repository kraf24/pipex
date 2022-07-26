/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:32:03 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/30 17:31:39 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	co;
	size_t	unt;
	size_t	size;
	char	*temo;

	size = ft_strlen(needle);
	co = 0;
	temo = (char *)haystack;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (temo[co] != '\0' && co < len)
	{
		unt = 0;
		while (temo[co + unt] == needle[unt] && len - co >= size)
		{
			if (needle[unt + 1] == '\0')
			{
				return (&temo[co]);
			}
			unt++;
		}
		co++;
	}
	return (0);
}
