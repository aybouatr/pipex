#include "../includes/pipex.h"


int main(int ac,char* av[],char* envp[])
{
    int file_input;
    int file_output;
    int i;

    if (ac >= 5)
    {
        if (ft_strncmp("here_doc", av[1],8) == 0)
        {

        }
        else
        {
            i = 2;
            file_input = open_fd(av[1],0);
            file_output = open_fd(av[ac - 1],1);
            rediction_dup2(file_input,STDIN_FILENO); 
        }
        while (i < ac - 2)
            apply_all_cmd(av[i++],envp);
        //execution()
        
    }
}