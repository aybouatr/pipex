#include "../includes/pipex.h" 


void execution(char* path,char** cmd)
{
    if (execve(path,cmd,NULL) == -1)
        error();
}

void child_process(char** envp,char* file_inp,char* cmd,int* fd_p)
{
    int     fd_in;
    char*   path;
    char**  s_cmd;

    closing(fd_p[0]);
    fd_in = open(file_inp,O_RDONLY,0777);
    if (fd_in == -1)
        error();
    rediction_dup2(fd_in,STDIN_FILENO);
    s_cmd = ft_split(cmd,' ');
    path = ft_get_path(envp,s_cmd[0]);
    rediction_dup2(fd_p[1],STDOUT_FILENO);
    execution(path,s_cmd);
    ft_free(s_cmd,path);
    closing(fd_in);
    closing(fd_p[1]);
}

void parent_process(char** envp,char* file_oup,char* cmd,int* fd_p)
{
    int     fd_ou;
    char*   path;
    char** s_cmd;

    closing(fd_p[1]);
    fd_ou = open(file_oup, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_ou == -1)
        error();
    rediction_dup2(fd_p[0],STDIN_FILENO);
    s_cmd = ft_split(cmd,' ');
    path = ft_get_path(envp,s_cmd[0]);
    rediction_dup2(fd_ou,STDOUT_FILENO);
    execution(path,s_cmd);
    closing(fd_ou);
    closing(fd_p[0]);
}

int main(int ac,char* av[],char* envp[])
{
    int fd_p[2];
    pid_t p_id;

    if(ac == 5)
    {
        if (pipe(fd_p) == -1)
            error();
        p_id = fork();
        if (p_id == -1)
            error();
        if (p_id == 0)
            child_process(envp,av[1],av[2],fd_p);
        waitpid(p_id,NULL,0);
        parent_process(envp,av[4],av[3],fd_p);
    }
    else
    {
        ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
    }
    return (0);
}