# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h> 
int     save_and_restore_fd(int action)
{
    static int  fds[3] = {-1};

    if (action == 0)              
    {
        fds[STDIN_FILENO] = dup(STDIN_FILENO);
        fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
        fds[STDERR_FILENO] = dup(STDERR_FILENO);
    }
    else if (action == 1)
    {
        dup2(fds[STDIN_FILENO], STDIN_FILENO);
        close(fds[STDIN_FILENO]);
        dup2(fds[STDOUT_FILENO], STDOUT_FILENO);
        close(fds[STDOUT_FILENO]);
        dup2(fds[STDERR_FILENO], STDERR_FILENO);
        close(fds[STDERR_FILENO]);
    }
    return (1);
}

int main()
{
    int fd[2];
    char *args1[2] = {"/bin/cat", NULL};
    char *args2[2] = {"/bin/ls", NULL};

    pipe(fd);                                
    save_and_restore_fd(0);                     

    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    if (fork() == 0)                            
    {
        close(fd[0]);
        execve("/bin/cat", args1, NULL);
        exit(0);
    }
    save_and_restore_fd(1);                    

    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    save_and_restore_fd(0);
                        
    if (fork() == 0)                          
    {
        execve("/bin/ls", args2, NULL);
        exit(0);
    }
    save_and_restore_fd(1);
    close(STDIN_FILENO);                     
    while (wait(NULL) > 0);                     
    return (0);
}