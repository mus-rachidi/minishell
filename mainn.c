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
    
   int fd = open("T",O_WRONLY); 
   dup2(fd, STDOUT_FILENO);
   close(fd);
   write(fd,"ok\n",3);
   write(STDOUT_FILENO,"ok1\n",4);
   return (0);
}