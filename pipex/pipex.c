/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec(t_pipex *pipex, int fd, int *pip)
{
	dup2(pipex->commands->fdout, 1);
	if (pipex->commands->redout == 0 && pipex->commands->next != 0)
		dup2(pip[1], 1);
	close(pip[1]);
	close(pip[0]);
	pipex->commands->cmd_args = ft_split(pipex->commands->args, ' ');
	pipex->commands->command = get_cmd(pipex->path, pipex->commands->cmd_args[0]);
		if (!pipex->commands->command)
		{
			msg(ERR_CMD);
			exit(1);
		}
	dup2(fd, 0);
	close(fd);
	execve(pipex->commands->command, pipex->commands->cmd_args, pipex->envp);
	return (error("error: cannot execute ", pipex->commands->command));
}

void	close_parent(int *tmp, int *fd)
{
	close(*tmp);
	*tmp = fd[0];
}

void	wait_process(int *tmp, t_commands *wp)
{
	close(*tmp);
	while (wp != 0)
	{
		if (wp->pid != -1)
		{
			waitpid(wp->pid, 0, 0);
		}
		wp = wp->next;
	}
}

void	exe(t_pipex *pipex)
{
	int			tmp;
	int			fd[2];
	t_commands  *wp;

	tmp = dup(pipex->commands->fdin);

	wp = pipex->commands;
	while (pipex->commands != 0)
	{
		pipe(fd);
		pipex->commands->pid = fork();
		if (!pipex->commands->pid)
			exec(pipex, tmp, fd);
		else
			close_parent(&tmp, fd);
		pipex->commands = pipex->commands->next;
	}
	wait_process(&tmp, wp);
}