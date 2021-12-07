/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_head.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 07:59:30 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 00:20:12 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HEAD_H
# define PARSING_HEAD_H

# include "../libft/libft.h"
# include "../head_global.h"

typedef struct s_env_no_qts
{
	char	*ret;
	char	*tmp;
	char	*temp;
	char	*data;
	int		data_alloc;
	char	*s;
}	t_env_no_qts;

typedef struct s_index
{
	int		*lenght;
	int		j;
	char	**str;
}	t_index;

int		true_condiftion(char *str, int j);
int		valid_echo_option(char *arg);
int		is_there_option(char *type, char **arg);
int		amg_free(char *s);
int		len_wrds(char *str, char c);
int		ifsplitis(char *s);
int		skip_s_sqts(int i, char *s);
int		skip_d_sqts(int i, char *s);
int		if_redrction(char *s);
int		len_wrds(char *str, char c);
int		edit_cmds(void);
int		len_wrds_edit(char *str, char c);
int		nbr_len(int n);
int		if_redrction(char *s);
int		red_syntax_errors_free(char **str, int *tmp);
int		error_syntax_diff(char *str, int i, int len);
int		error_return_syntax(int len, int i, char *str);
int		is_ambiguous(char *str);
int		*int_alloc(int i);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		get_lenght_by_char(char *s, char c);
int		len_array(char **args);
int		check_syntax(char *s);
int		syntax_pipes(char **splitline);
int		syntax_s_sqts(int *i, char *s);
int		syntax_d_sqts(int *i, char *s);
int		syntax_quotes(void);
int		syntax_errors(char **splitline, int type);
int		check_emptyline(void);
int		syntax_len_wrds(char *str, char c);
int		syntax_dyal_red(char **str);
int		get_type_red(char *str);
int		edit_cmds(void);
int		syntax_quotes(void);
int		syntax_errors(char **splitline, int type);
int		check_emptyline(void);
int		syntax_quotes_half(int *i);
int		syntax_d_sqts(int *i, char *s);
int		syntax_s_sqts(int *i, char *s);
int		syntax_pipes(char **splitline);
int		check_syntax(char *s);
int		ifsplitis(char *s);
int		skip_s_sqts(int i, char *s);
int		skip_d_sqts(int i, char *s);
int		while_plus(int j, char *str, int *j2);
int		is_ambiguous_exist(char *s);
int		sytax_red_double(char *str);
int		get_type_red(char *str);
void	init_some_var_halfqts(char *str, int *j, char **r, char **t);
char	*ret_change_env_qts(t_env_no_qts evq, int *j, char *str, int j2);
char	*change_env_half_qots(char *str, int *j, int j2);
char	*ret_chng_env(t_env_no_qts ev, int *j, char *str, int j2);
char	*ret_change_env_half_qots(char *str, int *j);
char	*addqouts_half(int i, char *ret, char *s);
char	**more_splt(int *indexs, int j);
char	*tmp_change_qots(char *str, int *j);
char	**split_one_cmnd(void);
char	**split_line_pipe(char *s);
char	**edited_split(char *str, char c);
char	**edited_split_typecmd(char *str, char c);
char	*delete_backspace(char *s);
char	*strjoin1(char *s, char c);
char	**get_args(char *line);
char	**get_args_ifred(char *line, char **str, int j);
char	**join2d(char **args, char *s);
char	**get_type_cmnd(char *line);
char	*get_type_cmnd_ifred(char *line, char **str, int nbr);
char	*charjoin(char *s, char c);
char	**get_position(int *indexs_rd, int i, char *cmd);
void	check_if_env(char *var, char **envs);
char	**change_env(char **str);
char	*addqouts(char *s);
void	free_array(char **str);
char	**get_filename(char *str);
char	**edited_split_typecmd(char *str, char c);
char	**edited_split_typecmd_half(char *str, char **ret, int j);
char	*split_typecmd_half_dbl_qots(int *i, char *str, char c, char *rett);
char	**alloc_ret_split(char **ret, char *str, char c);
char	**ft_split_plus(char *str, char c);
char	**get_filename(char *str);
char	**more_splt_allc(int j, int *indexs, int *lenght);
char	**more_splt_half(int j, char **str, int *lenght, int *indexs);
char	**join2d_filenames(char **args, char *s);
void	join_org_names_red(char **str);
char	*ft_split_half_dbl_qots(int *i, char *str, char *ret, char c);
char	**alloc_ft_split(char **ret, char *str, char c);
void	free_list(void);
char	**ft_split_plus_half(char *str, int i, char **ret, int j);
char	*status_env_ret_qts(char *tmp, char *str, int j);
char	*status_env_ret(char *tmp, char *str, int j);
char	*change_env_dqots(char *str, int *j);
char	*change_env_half_qots(char *str, int *j, int j2);
char	*change_env_no_qots(char *str, int *j, int j2);
char	*change_env_while(char *str, int j, int j2);
char	**get_all_args(char **args, char *type);
char	**get_args_ifred_else(int y, char **str, char **tmp);
char	**args_red_else_half(char **tmp, int i, char **ret, int *cmd);
char	**get_args_ifred_if(int len, char **ret, char **str, char **tmp);
char	**ifred_if_half(char **tmp, char **ret, int i, char **str);
char	*else_org_split_typecmd_half(char *ret, int *i, char c);
char	**alloc_ft_split(char **ret, char *str, char c);
char	*split_mode_dbl_qots(int *i, char *str, char *ret, char c);
char	**split_mode(char *str);
char	**char_dbl_alloc(int i);
char	*char_alloc(int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	printf_output(void);
char	*ft_strtrim_space(char const *s1, char const *set);

#endif
