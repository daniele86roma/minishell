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

void	check_fileout(char *fileout, t_pipex *pipex)
{
	if (pipex->commands->redout == 1)
	{
		pipex->commands->fdout = open(fileout, O_TRUNC | O_RDWR | O_CREAT, 0666);
		if (pipex->commands->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
	else if (pipex->commands->redout == 2)
	{
		pipex->commands->fdout = open(fileout, O_APPEND | O_RDWR | O_CREAT, 0666);
		if (pipex->commands->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
	else
		pipex->commands->fdout = 1;
}

void	check_file(char *filein, t_pipex *pipex)
{
	if (access(filein, F_OK) == 0)
	{
		pipex->commands->fdin = open(filein, O_RDONLY);
		if (pipex->commands->fdin < 0)
			msg_error(ERR_INFILE);
		return ;
	}
	printf("zs: %s: %s\n", strerror(errno), filein);
	exit (0);
}

int	exec(t_pipex *pipex, int fd)
{
	dup2(fd, 0);
	close(fd);
	execve(pipex->commands->command, pipex->commands->cmd_args, pipex->envp);
	return (error("error: cannot execute ", pipex->commands->command));
}

void	exe(t_pipex *pipex)
{
	int	pid;
	int	tmp;
	int	fd[2];

	pid = 0;
	tmp = dup(0);
	while (pipex->commands != 0)
	{
			pipe(fd);
			pid = fork();
			if (!pid)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
				pipex->commands->cmd_args = ft_split(pipex->commands->args, ' ');
				pipex->commands->command = get_cmd(pipex->path, pipex->commands->cmd_args[0]);
				if (!pipex->commands->command)
				{
					msg(ERR_CMD);
					exit(1);
				}
				exec(pipex, tmp);
			}
			else
			{
				close(tmp);
				close(fd[1]);
				tmp = fd[0];
			}
		pipex->commands = pipex->commands->next;
	}
	close(tmp);
}
