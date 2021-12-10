/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:13:43 by murachid          #+#    #+#             */
/*   Updated: 2021/12/10 21:09:05 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	ft_redirection(t_cmds *cmds, t_fd *fd, int i)
{
	t_cmds		*tmp1;
	int			zero;

	tmp1 = cmds;
	cmds->multiple = 0;
	zero = dup(0);
	while (tmp1->redrctions)
	{
		if (tmp1->redrctions->type == 1)
			ft_overwrites(cmds, fd);
		else if (tmp1->redrctions->type == 2)
			ft_append_output(cmds, fd);
		else if (tmp1->redrctions->type == 3)
			ft_here_doc(tmp1, fd, zero, i);
		else if (tmp1->redrctions->type == 0)
			ft_append_intput(tmp1, fd);
		tmp1->redrctions = tmp1->redrctions->next;
	}
}

char	**init_list(void)
{
	char	**exe;

	exe = malloc(sizeof(char *) * 8);
	exe[0] = ft_strdup("pwd");
	exe[1] = ft_strdup("exit");
	exe[2] = ft_strdup("echo");
	exe[3] = ft_strdup("cd");
	exe[4] = ft_strdup("export");
	exe[5] = ft_strdup("unset");
	exe[6] = ft_strdup("env");
	exe[7] = NULL;
	return (exe);
}
