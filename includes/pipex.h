#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
# include "../libft/libft.h"
#include <fcntl.h>

void rediction_dup2(int fd,int fd_to_rediction);
void ft_free(char** arr,char* str);
void closing(int fd);
void execution(char* path,char** cmd);
void child_process(char** envp,char* file_inp,char* cmd,int* fd_p);
void parent_process(char** envp,char* file_oup,char* cmd,int* fd_p);
void	error(void);
char* ft_get_path(char** envp,char* cmd);

#endif