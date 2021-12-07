/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:25:01 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 23:46:45 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_global.h"

int	check_t_child(char *flag_to_check)
{
	static int	global_check;

	if (flag_to_check)
	{
		if (*flag_to_check == '1')
			global_check = 1;
		if (*flag_to_check == '0')
			global_check = 0;
	}
	return (global_check);
}

void	ft_sgone(int numofsig)
{
	if (numofsig == SIGINT)
		write(2, "\n", 1);
	if (numofsig == SIGQUIT)
		write(2, "Quit: 3\n", 9);
}

void	ft_tow(int numofsig)
{
	char	*buffer;

	// if (numofsig == SIGINT)
	// {
	// 	buffer = ft_strdup(rl_line_buffer);
	// 	rl_on_new_line();
	// 	rl_replace_line("", 1);
	// 	rl_redisplay();
	// 	write(2, buffer, ft_strlen(buffer));
	// 	write(2, "   \nUser@minishell>", 21);
	// 	free(buffer);
	// }
	// if (numofsig == SIGQUIT)
	// {
	// 	rl_on_new_line();
	// 	rl_redisplay();
	// 	write(2, "  \b\b", 4);
	// }
}

void	sig_handler(int numofsig)
{
	char	*ptr;

	ptr = NULL;
	if (check_t_child(ptr) == 1)
		ft_sgone(numofsig);
	else
		ft_tow(numofsig);
	stop();
}

int	main(int ac, char **av, char **envs)
{
	t_cmds		*fl;

	ac = 0;
	av = NULL;
	fl = init_stuct();
	list_envs(envs);
	
	// signal(SIGINT, sig_handler);
	// signal(SIGQUIT, sig_handler);
	while (1)
	{
		fl->stop = 1;
		main_parsing(envs);
	}
	return (0);
}
