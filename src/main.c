/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:37:44 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/25 21:06:53 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pipex.h"

char	**path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_data	pipex;

	if (argc != 5)
		return (error(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		err_msg(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0777);
	if (pipex.outfile < 0)
		err_msg(ERR_OUTFILE);
	if (pipe(pipex.pipes) < 0)
		err_msg(ERR_PIPE);
	pipex.cmd_path = path(envp);
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		first_child_process(pipex, argv, envp);
	pipex.child2 = fork();
	if (pipex.child2 == 0)
		second_child_process(pipex, argv, envp);
	close(pipex.pipes[1]);
	close(pipex.pipes[0]);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
	free_2dstr(pipex.cmd_path);
	return (0);
}
