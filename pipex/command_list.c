/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_command(t_commands *new, t_pipex *list)
{
	t_commands *tmp;

	tmp = list->commands;
	new->next = 0;
	if (!list->commands)
	{
		list->commands = new;
		return;
	}
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = new;
	return;
}