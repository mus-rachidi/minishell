/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_global.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:43:57 by murachid          #+#    #+#             */
/*   Updated: 2021/12/10 21:32:50 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_GLOBAL_H
# define HEAD_GLOBAL_H
# include "libft/libft.h"
# define SIZE 1
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h> 

typedef struct s_filerdr
{
	char				*name;
	int					type;
	struct s_filerdr	*next;
	int					error;
	char				*all;
	char				*org_name;
	int					ambiguous;
}t_filerdr;

typedef struct s_cmds
{
	int				s_code;
	char			*line;
	char			*command;
	char			*type;
	char			**arguments;
	int				option;
	int				size;
	int				multiple;
	int				es;
	char			*check_error;
	t_filerdr		*filerdr;
	char			**all;
	int				i_fl;
	char			**filenames;
	t_filerdr		*redrctions;
	struct s_cmds	*next_cmd;
	int				g_check;
	int				g_check_error;
	char			*str_error;
}t_cmds;

typedef struct s_data_item
{
	char				*data;
	char				*key;
	struct s_data_item	*next;
}t_data_item;

t_data_item	*g_hasharray[SIZE];

typedef struct s_free
{
	void				*newt;
	struct s_free		*next_t;
}t_free;

typedef struct s_free_stc
{
	t_free	*free_p;
}t_free_stc;

t_free_stc			*init_struct_free(void);
void				free_one(char *s);
void				free_all(void *n);
struct	s_data_item	*search(char *key, struct s_data_item *temp);
void				sig_handler(int numofsig);
int					check_t_child(char *flag_to_check);
void				exit_stat(int ret, int flag, t_cmds *cd);
int					check_t_child(char *flag);
int					main_parsing(char **envs);
void				exec_cmd_test(t_cmds *cmds, char **envs);
int					my_ft_strchr(char *s);
void				list_envs(char *envs[]);
t_cmds				*init_stuct(void);
t_cmds				*new_node(char *str);
void				join_list(t_cmds *tmp, t_cmds *src);
void				clear_red_list(t_filerdr *f);
void				init_linkedlist(char **str);
void				free_redrection(t_filerdr *f);
void				clear_list(t_cmds *tmp);
t_filerdr			*new_red_list(char *str);
t_filerdr			*init_header_list_rd(t_filerdr *org_list,
						int p, char **str);
int					*get_indexs_rd(t_cmds *test, int *indexs_rd, int *i);
t_cmds				*data_if_not_red(t_cmds *test);
t_cmds				*data_if_red_exist(t_cmds *test, int *ret_value);
t_cmds				*cmd_alloc(int i);
t_filerdr			*red_alloc(int i);
char				*ft_getenv(char *s);
void				join_red_list(t_filerdr *add_tmp, t_filerdr *src);
void				free_filenames(void);
#endif