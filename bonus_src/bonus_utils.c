/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:35:28 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/21 16:17:58 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "bonus_pipex.h"

int fd_opener(char *argv, int i)
{
	int fd;

	if (i == 'i')
		fd = open(argv, O_RDONLY);
	else if (i == 'o')
		fd = open(argv, O_TRUNC | O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		err_msg(ERR_INFILE);
	return (fd);
}

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

char	**path(char **envp) //uesed
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

char	*command(pipex_data pipex, char *command)
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