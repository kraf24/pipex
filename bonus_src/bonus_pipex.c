/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:35:51 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/26 19:01:33 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bonus_pipex.h"

void execute(t_pipex_data data, char *envp[])
{
	data.comand = command(data, data.cmd[0]);
	execve(data.comand, data.cmd, envp);
}

void proces(t_pipex_data data, char *lim)
{
	char *line;

	while (ft_strncmp(line, lim, ft_strlen(lim) + 1) != 10)
	{
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(0);
		// free(line);
		write(data.pipes[1], line, ft_strlen(line));
		write(data.pipes[1], "\n", ft_strlen(line));
	}
	// free(line);
	exit(1);
	exit(1);
}

void LIMITER(t_pipex_data data, char *argv[])
{
	if (pipe(data.pipes) < 0)
	err_msg(ERR_PIPE);
	data.child = fork();
	if (data.child == -1)
		err_msg(ERR_PIPE);
	if(data.child == 0)
		proces(data, argv[2]);
	else
	{
		close(data.pipes[1]);
		if ((dup2(data.pipes[0], STDIN_FILENO)) == -1)
			err_msg(ERR_INFILE);
		waitpid(data.child, NULL, 0);
	}
}

void arr_execute(t_pipex_data data, char *argv, char *envp[])
{
	if (pipe(data.pipes) < 0)
		err_msg(ERR_PIPE);
	data.child = fork();
	if (data.child == -1)
		err_msg(ERR_PIPE);
	if (data.child == 0)
	{
		if ((dup2(data.pipes[1], STDOUT_FILENO)) == -1)
			err_msg(ERR_OUTFILE);
		close(data.pipes[0]);
		data.cmd = ft_split(argv, ' ');
		close(data.pipes[1]);
		execute(data, envp);
	}
	else
	{
		close(data.pipes[1]);
		if ((dup2(data.pipes[0], STDIN_FILENO)) == -1)
		err_msg(ERR_INFILE);
		close(data.pipes[0]);
		waitpid(data.child, NULL, 0);
	}
}

void pipex(int argc, char *argv[], char *envp[])
{
	int start;
	
	t_pipex_data data;
	if (strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
			err_msg(ERR_INPUT);
		start = 3;
		data.outfile = fd_opener(argv[argc - 1], 't');
		LIMITER(data, argv);
	}
	else
	{
		start = 2;
		data.infile = fd_opener(argv[1], 'c');
		data.outfile = fd_opener(argv[argc - 1], 'a');
		if (dup2(data.infile, STDIN_FILENO))
			err_msg(STDIN_FILENO);
	}
	data.cmd_path = path(envp);
	while(start < argc - 2)
		arr_execute(data ,argv[start++], envp);
	if ((dup2(data.outfile, STDOUT_FILENO)) == -1)
		err_msg(ERR_OUTFILE);
	data.cmd = ft_split(argv[argc - 2], ' ');
	execute(data, envp);
	free(data.cmd_path);
}
