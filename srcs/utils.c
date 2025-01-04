/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:39:51 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/31 09:39:54 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(char **av, int ac)
{
	int	i;
	int	check;

	i = 2;
	check = 0;
	if (ft_strncmp("here_doc", av[1], 8) == 0)
		i = 3;
	while (i < ac - 1)
	{
		if (av[i][0] == '\0')
		{
			ft_putstr_fd("Error : ", 2);
			ft_putstr_fd("Permission denied\n", 1);
			check = 1;
		}
		i++;
	}
	if (check != 0)
		return (exit(126), 126);
	return (1);
}

int	execution(char **envp, char *cmd)
{
	char	*path;
	char	**s_cmd;
	char	**sp_cmd;
	int		i;

	sp_cmd = ft_split(cmd, '/');
	i = 0;
	while (sp_cmd[i + 1] != NULL)
		i++;
	s_cmd = ft_split(sp_cmd[i], ' ');
	ft_free(sp_cmd, NULL);
	if (!s_cmd[0])
	{
		ft_putstr_fd("Error : command not found \n", 2);
		return (exit(127), 127);
	}
	path = ft_get_path(envp, s_cmd[0]);
	if (!path)
	{
		ft_free(s_cmd, NULL);
		error(1);
	}
	if (execve(path, s_cmd, NULL) == -1)
		return (ft_free(s_cmd, path), error(1), 1);
	return (ft_free(s_cmd, path), 1);
}
/// ////////////////////////////////
/// ////////////////////////////////
void	error(int n)
{
	perror("Error ");
	exit(n);
}

char	*ft_get_path(char **envp, char *cmd)
{
	int		i;
	char	**s_path;
	char	*path[2];

	i = 0;
	s_path = NULL;
	while (envp[i + 1] != NULL)
		i++;
	while (i >= 0 && s_path == NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			s_path = ft_split(envp[i] + 5, ':');
		i--;
	}
	i = 0;
	while (s_path != NULL && s_path[i])
	{
		path[1] = ft_strjoin(s_path[i], "/");
		path[0] = ft_strjoin(path[1], cmd);
		if (access(path[0], F_OK) == 0)
			return (ft_free(s_path, path[1]), path[0]);
		i++;
	}
	ft_free(s_path, NULL);
	return (ft_putstr_fd("command not found\n", 2), exit(127), NULL);
}

void	ft_free(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr != NULL && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (str)
		free(str);
}
