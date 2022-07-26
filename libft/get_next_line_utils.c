/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:03:15 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/25 21:03:08 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_string(char *string)
{
	size_t		size;
	char		*str;

	size = 0;
	if (!string[size])
		return (NULL);
	while (string[size] != '\n' && string[size])
		size++;
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, string, size + 2);
	return (str);
}

char	*ft_get_new_string(char *string)
{
	size_t	size;
	int		i;
	char	*new_str;

	i = 0;
	size = ft_strlen(string);
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (size - i));
	if (!new_str)
		return (NULL);
	i++;
	ft_strlcpy(new_str, &string[i], size - i + 1);
	free(string);
	return (new_str);
}

char	*ft_strchr_get(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
