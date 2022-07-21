/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:31:47 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/21 16:03:45 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

#include <string.h>

#include <sys/wait.h>

# define ERR_INPUT "Invalid number of arguments\n"
# define ERR_INFILE "file doesn't exist hihihihihihahahahah"
# define ERR_OUTFILE "no rules for outfile"
# define ERR_CMD "no such command"
# define ERR_PIPE "pipe error"

typedef struct s_pipex 
{
	int pipes[2];
	pid_t child;
	int infile;
	int outfile;
	char *comand;
	char **cmd_path;
	char **cmd;
}	pipex_data;

void	free_2dstr(char **str);
char	**path(char **envp);
char	*command(pipex_data pipex, char *command);

int	fd_opener(char *argv, int i);

int		error(char *msg);
void	err_msg(char *err);

#endif