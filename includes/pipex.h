/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:44:46 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/02 11:50:28 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 333
# endif

int		check_cmd(char **av, int ac);
void	ft_free(char **arr, char *str);
int		execution(char **envp, char *cmd);
void	child_process(char **envp, char *file_inp, char *cmd, int *fd_p);
void	parent_process(char **envp, char *file_oup, char *cmd, int *fd_p);
void	error(int n);
char	*ft_get_path(char **envp, char *cmd);

void	apply_all_cmd(char *cmd, char **envp);
int		open_fd(char *name_file, int fd);
int		ftt_sttrchr(const char *str, char search_str);
char	*ftt_strjoin(char *s1, char *s2);
char	*get_read_str(int fd, char *s_str);
char	*get_than_line(char *s_str);
char	*get_next_line(char **line);
char	*get_remminder(char *s_str);
int		ft_here_doc(char *limiter, char *file);

#endif
