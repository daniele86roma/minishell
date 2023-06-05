/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/05/30 11:46:33 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_exit_status(t_pipex *pipex)
{
	t_args	arg;

	if (get_var("?", pipex) == 0)
	{
		arg.key = "?";
		arg.value = "0";
		add_arg(&arg, pipex);
	}
}

void	add_exitstatus(t_pipex *pipex)
{
	t_args	arg;

	arg.key = "?";
	arg.value = ft_itoa(WEXITSTATUS(g_exitcode));
	add_arg(&arg, pipex);
	free(arg.value);
}