/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:49:02 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 15:42:52 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		o;
	size_t		i;
	char		*str;

	i = 0;
	if (!s || !f)
		return (0);
	o = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (o + 1));
	if (!str)
		return (NULL);
	while (i < o)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
