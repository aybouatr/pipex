/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:42:29 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/31 08:42:34 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ftt_strchr(const char *str, char search_str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == search_str)
			return (1);
		str++;
	}
	return (0);
}

char	*ftt_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (free(s1), new);
}

char	*get_read_str(int fd, char *s_str)
{
	char	*buffer;
	ssize_t	len_resd;
	char	*temp;

	len_resd = 1;
	buffer = NULL;
	while (!ftt_strchr(s_str, '\n') && len_resd != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		len_resd = read(fd, buffer, BUFFER_SIZE);
		if (len_resd == -1)
			return (free(buffer), NULL);
		buffer[len_resd] = '\0';
		if (len_resd == 0 && s_str == NULL)
			return (free(buffer), NULL);
		temp = s_str;
		s_str = ftt_strjoin(s_str, buffer);
		free(temp);
		if (!s_str)
			return (free(buffer), NULL);
		free(buffer);
	}
	return (s_str);
}

char	*get_than_line(char *s_str)
{
	size_t	len;
	char	*buffer;

	len = 0;
	while (s_str[len] != 0 && s_str[len] != '\n')
		len++;
	buffer = malloc(sizeof(char) + (len + 2));
	if (!buffer)
		return (NULL);
	len = 0;
	while (s_str[len] != 0 && s_str[len] != '\n')
	{
		buffer[len] = s_str[len];
		len++;
	}
	if (s_str[len] == '\n')
	{
		buffer[len] = '\n';
		buffer[len + 1] = '\0';
	}
	else
		buffer[len] = '\0';
	return (buffer);
}

int	open_fd(char *name_file, int fd)
{
	int	file;

	file = 0;
	if (fd == 0)
		file = open(name_file, O_RDWR, 0777);
	else if (fd == 1)
		file = open(name_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		error(1);
	return (file);
}
