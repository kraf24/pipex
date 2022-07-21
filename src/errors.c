/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:33:22 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/05 19:58:22 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pipex.h"

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	err_msg(char *err)
{
	perror(err);
	exit(1);
}
