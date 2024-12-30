#include "../includes/pipex.h"


void rediction_dup2(int fd,int fd_to_rediction)
{
    if(dup2(fd,fd_to_rediction) == -1)
        error(1);
}

void execution(char** envp,char* cmd)
{
    char*   path;
    char**  s_cmd;
    char** sp_cmd;
    int    i;

    sp_cmd = ft_split(cmd,'/');
    i = 0;
    while (sp_cmd[i + 1] != NULL)
        i++;
    s_cmd = ft_split(sp_cmd[i],' ');
    path = ft_get_path(envp,s_cmd[0]);
    ft_free(sp_cmd,NULL);
    if(!path)
    {
        ft_free(s_cmd,NULL);
        error(1);
    }
    if (execve(path,s_cmd,NULL) == -1)
    {
        ft_free(s_cmd,path);
        error(1);
    }
    ft_free(s_cmd,path);
}

void	error(int n)
{
	perror("\033[31mError");
	exit(n);
}

char* ft_get_path(char** envp,char* cmd)
{
    char* path;
    int  i;
    char** s_path;
    char *first_path;

    i = 0;
    s_path = NULL;
    while (envp[++i + 1] != NULL);
    while (i >= 0 && s_path == NULL)
    {
        if(ft_memcmp(envp[i],"PATH=",5) == 0)
            s_path = ft_split(envp[i] + 5,':');
        i--;
    }
    i = 0;
    while (s_path[i])
    {
        first_path = ft_strjoin(s_path[i] , "/");
        path = ft_strjoin(first_path,cmd);
        if (access(path,F_OK) == 0)
            return (ft_free(s_path,first_path),path);
        free(first_path);
        free(path);
        i++;
    }
    return (ft_free(s_path,NULL),error(127),NULL);
}
void ft_free(char** arr,char* str)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    if (str)
        free(str);
}
