/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:52:06 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/05 19:57:51 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pipex.h"

void	free_2dstr(char **str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		free(str[c]);
		c++;
	}
	free(str);
}
