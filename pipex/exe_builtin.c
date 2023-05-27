/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_builtin(t_pipex *pipex, int *fd, int *pip, t_commands *commands)
{
    if ((commands->builtin == 2 && commands->next != 0) || commands != pipex->commands)
        return;
    if (ft_strncmp(commands->args, "exit", 4) == 0)
        ft_exit();
	else if (ft_strncmp(commands->args, "export", 6) == 0)
        ft_export(commands->args, pipex);
	else if (ft_strncmp(commands->args, "unset", 5) == 0)
        ft_unset(commands->args, pipex);
    if (commands->redout == 0 && commands->next == 0)
		dup2(pipex->stdout, 1);
	else if (commands->redout != 0)
	    dup2(commands->fdout, 1);	
	else
		dup2(pip[1], 1);
	close(pip[1]);
	close(*fd);
	if (ft_strncmp(commands->args, "pwd", 3) == 0)
        ft_pwd();
}

int	is_path(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
	{
		if (s[i] == '/')
			return(1);
	}
	return (0);
}