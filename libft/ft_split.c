/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:30:27 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/09 18:06:54 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	size_t	j;
	int		count;

	j = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			j++;
			count = 1;
		}
		else if (*s == c)
		{
			count = 0;
		}
		s++;
	}
	return (j);
}

static char	*ft_lenght(const char *s, char del, int *len)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i + *len] != del)
	{
		if (s[i + *len] == '\0')
			break ;
		i++;
	}
	res = ft_substr(s, *len, i);
	*len += i + 1;
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (i != ft_count(s, c))
	{
		if (s[len] == c)
		len++;
		else
			res[i++] = ft_lenght(s, c, &len);
	}
	res[i] = 0;
	return (res);
}
