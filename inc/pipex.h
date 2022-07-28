/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:39:35 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/28 20:21:13 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

# include <string.h>

# include <sys/wait.h>

# define ERR_INPUT "Invalid number of arguments"
# define ERR_INFILE "file doesn't exist hihihihihihahahahah"
# define ERR_OUTFILE "no rules for outfile"
# define ERR_CMD "no such command"
# define ERR_PIPE "pipe error"

typedef struct s_pipex
{
	int		pipes[2];
	pid_t	child1;
	pid_t	child2;
	int		infile;
	int		outfile;
	char	*comand;
	char	**cmd_path;
	char	**cmd;
}	t_pipex_data;

int		error(char *msg);
void	err_msg(char *err);
void	free_2dstr(char **str);
void	first_child_process(t_pipex_data pipex, char *argv[], char *envp[]);
void	second_child_process(t_pipex_data pipex, char *argv[], char *envp[]);

#endif