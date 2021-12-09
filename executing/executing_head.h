/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_head.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:24:47 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 22:08:11 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_HEAD_H
# define EXECUTING_HEAD_H
# include "../libft/libft.h"
# include "../head_global.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct t_node
{
	char			*data;
	char			*str_error;
	struct t_node	*next;
}t_node;

typedef struct s_fd
{
	int	fd_int;
	int	fd_out;
	int	fd_pipe[2];
	int	p;
}t_fd;

typedef struct s_pipex
{
	char	*bin;
	char	*temp;
	char	*path;
	int		fd;
	char	**path_split;
}t_pipex;
int					mywrite(void);
void				mywrite_int(void);
void				rest_buffer(void);
void				message_print_red(char *s, char *str, int exit_error);
void				message_print_export(char *s, int exit_error);
void				message_print(char *s, char *str, int error);
void				free_and_wait(t_node *head);
void				free_arg(t_cmds *tmp1);
void				freelist(t_node *head);
int					my_ft_strchr(char *s);
t_node				*insertfirst(char *data, t_node *head);
void				printlist(t_node *head);
void				ft_check_exit(t_cmds *tmp1);
char				*ft_check_two(t_cmds *tmp1);
void				exec_built_second(t_cmds *tmp);
struct s_data_item	*search(char *key, struct s_data_item *temp);
void				delete(struct s_data_item *temp);
void				display(t_cmds *tmp, struct s_data_item *temp);
void				insert(char *key, char *data);
int					hashcode(char *chaine);
int					delete_element(struct s_data_item **t, char *key);
void				print_disply(t_cmds *tmp, struct s_data_item *temp, int *i);
void				ft_check_error_zero(t_cmds *tmp1);
void				ft_overwrites(t_cmds *tmp1, t_fd *fd);
void				ft_append_intput(t_cmds *tmp1, t_fd *fd);
void				ft_append_output(t_cmds *tmp1, t_fd *fd);
void				ft_here_doc(t_cmds *tmp1, t_fd *fd, int zero, int i);
void				ft_redirection(t_cmds *cmds, t_fd *fd);
void				ft_executing_in_child(t_cmds *cmds, char **envs);
void				error_message(void);
int					ft_strcmp(char *s1, const char *s2);
int					file_descriptor(t_cmds *cmds, int zero, int i);
char				*getenv_new(char **envs);
void				free_array(char **array);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
int					my_pipe(int argc, char **argv, char **envs);
int					test_built_cmd(t_cmds *tmp);
int					get_next_line(int fd, char **line);
void				ft_join(t_pipex *pipex, char *cmd);
void				exec_cmd(t_cmds *cmd, char *envs[]);
void				dup_env(char **envp);
int					hachage(char *chaine);
char				*getenv_new(char **envs);
void				free_array(char **array);
int					pipex(int argc, char **argv, char **envs);
void				exec_built(t_cmds *tmp);
void				print_error(char *a, char *b);
void				ft_check_error_one(t_cmds *cmds);
char				*ft_check_error_two(t_cmds *cmds);
char				*ft_check_error_three(t_cmds *cmds);
void				exe_cd(t_cmds *tmp);
void				exe_pwd(void);
void				exe_export(t_cmds *tmp, struct s_data_item *temp);
void				exe_unset(t_cmds *tmp, struct s_data_item *temp);
void				exe_echo( t_cmds *tmp);
void				ft_check_error_for(char *file);
void				print(void);

#endif