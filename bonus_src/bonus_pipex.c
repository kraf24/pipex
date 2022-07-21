/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:35:51 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/21 16:20:24 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "bonus_pipex.h"

void execute(pipex_data data)
{
	data.comand = command(data, data.cmd[0]);
	execve
}

void LIMITER(char *argv[], int i)
{
	
}

void arr_execute(pipex_data data, char *argv)
{
	if (pipe(pipex.pipes) < 0)
		err_msg(ERR_PIPE);

	data->child = fork();
	if (data->child == -1)
		err_msg(ERR_PIPE);
	if (data.child == 0)
	{
		data->cmd = ft_split(argv, ' ');
		close(data.pipes[0]);
		dup2(data.pipes[1], STDOUT_FILENO);
		close(data.pipes[1]);
		execute(data);
	}
	else
	{
		close(data.pipes[1]);
		dup2(data.pipes[0], STDIN_FILENO);
		close(data.pipes[0]);
		waitpid(data.child, NULL, 0);
	}
}

void pipex(int argc, char *argv[], char *envp[])
{
	int start;
	
	pipex_data data;

	if (strncmp(argv[1], "here_doc") == 0)
	{
		start = 3;
		LIMITER(argv, argc);
		data.outfile = fd_opener(argv[argc - 1], 'o');
	}
	else
	{
		start = 2;
		data.infile = fd_opener(argv[1], 'i');
		data.outfile = fd_opener(argv[argc - 1], 'o');
		if (dup2(data.outfile, STDIN_FILENO));
		err_msg(STDIN_FILENO);
	}
	data.cmd_path = path(envp);
	while(start < argc - 2)
		arr_execute(data ,argv[start++]);
	if (dup2(data.outfile, STDOUT_FILENO));
		err_msg(ERR_OUTFILE);
	execute(data)
}