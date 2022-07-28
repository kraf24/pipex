/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:50 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/28 20:23:30 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bonus_pipex.h"

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}

void	err_msg(char *err)
{
	perror(err);
	exit(0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		error("Invalid number of arguments");
	pipex(argc, argv, envp);
	return (0);
}
