/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:31:47 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/25 21:11:33 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PIPEX_H
# define BONUS_PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

# include <string.h>

# include <sys/wait.h>

# define ERR_INPUT "Invalid number of arguments\n"
# define ERR_INFILE "file doesn't exist hihihihihihahahahah"
# define ERR_OUTFILE "no rules for outfile"
# define ERR_CMD "no such command"
# define ERR_PIPE "pipe error"

typedef struct s_pipex
{
	int		pipes[2];
	pid_t	child;
	int		infile;
	int		outfile;
	char	*comand;
	char	**cmd_path;
	char	**cmd;
}	t_pipex_data;

void	free_2dstr(char **str);
char	**path(char **envp);
char	*command(t_pipex_data pipex, char *command);

int		fd_opener(char *argv, int i);

int		error(char *msg);
void	err_msg(char *err);
void	pipex(int argc, char *argv[], char *envp[]);

#endif