/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:44:57 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/28 20:49:18 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pipex.h"

char	*command(t_pipex_data pipex, char *command)
{
	int		i;
	char	*result;
	char	*temp;

	i = 0;
	while (pipex.cmd_path[i])
	{
		temp = ft_strjoin(pipex.cmd_path[i], "/");
		result = ft_strjoin(temp, command);
		if (!access(result, F_OK))
		{
			free(temp);
			return (result);
		}
		free(result);
		i++;
	}
	return (0);
}

void	first_child_process(t_pipex_data pipex, char *argv[], char *envp[])
{
	dup2(pipex.pipes[1], STDOUT_FILENO);
	close(pipex.pipes[0]);
	dup2(pipex.infile, STDIN_FILENO);
	close(pipex.infile);
	pipex.cmd = ft_split(argv[2], ' ');
	pipex.comand = command(pipex, pipex.cmd[0]);
	if (!pipex.comand)
	{
		free_2dstr(pipex.cmd);
		error(ERR_CMD);
		exit(1);
	}
	execve(pipex.comand, pipex.cmd, envp);
}

void	second_child_process(t_pipex_data pipex, char *argv[], char *envp[])
{
	dup2(pipex.pipes[0], STDIN_FILENO);
	close(pipex.pipes[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.outfile);
	pipex.cmd = ft_split(argv[3], ' ');
	pipex.comand = command(pipex, pipex.cmd[0]);
	if (!pipex.comand)
	{
		free_2dstr(pipex.cmd);
		error(ERR_CMD);
		exit(1);
	}
	execve(pipex.comand, pipex.cmd, envp);
}
