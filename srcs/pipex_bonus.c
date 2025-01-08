/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:43:34 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/31 08:43:37 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	apply_all_cmd(char *cmd, char **envp)
{
	int		fd_p[2];
	pid_t	pip;

	if (pipe(fd_p) == -1)
		error(1);
	pip = fork();
	if (pip == -1)
		error(1);
	if (pip == 0)
	{
		close(fd_p[0]);
		dup2(fd_p[1], STDOUT_FILENO);
		execution(envp, cmd);
	}
	else
	{
		close(fd_p[1]);
		dup2(fd_p[0], STDIN_FILENO);
		waitpid(pip, NULL, 0);
	}
}

char	*get_remminder(char *s_str)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	len = 0;
	i = 0;
	while (s_str[len] != '\0' && s_str[len] != '\n')
		len++;
	if (s_str[len] == '\0')
		return (ft_strdup(""));
	buffer = malloc(sizeof(char) + ((ft_strlen(s_str) - len) + 1));
	if (!buffer)
		return (NULL);
	len++;
	while (s_str[len] != '\0')
	{
		buffer[i] = s_str[len];
		i++;
		len++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(char **line)
{
	static char	*s_str;
	char		*r_str;
	char		*temp;

	r_str = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	s_str = get_read_str(0, s_str);
	if (!s_str)
		return (NULL);
	temp = s_str;
	r_str = get_than_line(s_str);
	free(temp);
	if (!r_str)
		return (NULL);
	s_str = get_remminder(s_str);
	if (!s_str)
		return (free(r_str), NULL);
	if (s_str[0] == '\0')
	{
		free(s_str);
		s_str = NULL;
	}
	*line = r_str;
	return (r_str);
}

int	ft_here_doc(char *limiter, char *file)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		error(1);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(ft_strjoin(limiter, "\n"), line,
					ft_strlen(line), 1) == 0)
				return (free(line), exit(EXIT_SUCCESS), 0);
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	wait(NULL);
	return (open_fd(file, 1));
}

int	main(int ac, char *av[], char *envp[])
{
	int	file_in_or_out[2];
	int	i;

	if (ac >= 5 && check_cmd(av, ac))
	{
		if (ft_strncmp("here_doc", av[1], 8, 0) == 0)
		{
			i = 3;
			file_in_or_out[1] = ft_here_doc(av[2], av[ac - 1]);
		}
		else
		{
			i = 2;
			file_in_or_out[0] = open_fd(av[1], 0);
			file_in_or_out[1] = open_fd(av[ac - 1], 1);
			dup2(file_in_or_out[0], STDIN_FILENO);
		}
		while (i < ac - 2)
			apply_all_cmd(av[i++], envp);
		dup2(file_in_or_out[1], STDOUT_FILENO);
		execution(envp, av[ac - 2]);
	}
	else
		return (ft_putstr_fd("Error: Bad arguments\n", 1), exit(1), 0);
	return (close(file_in_or_out[1]), close(file_in_or_out[0]), 0);
}
