/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:13:43 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 18:19:18 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	ft_redirection(t_cmds *cmds, t_fd *fd)
{
	t_cmds		*tmp1;
	int			zero;
	static int	i;

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
		{
			i++;
			ft_here_doc(tmp1, fd, zero, i);
		}
		else if (tmp1->redrctions->type == 0)
			ft_append_intput(tmp1, fd);
		tmp1->redrctions = tmp1->redrctions->next;
	}
}
