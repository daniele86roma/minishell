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
	if (pipex->stout == 1)
	{
		pipex->fdout = open(fileout, O_TRUNC | O_RDWR | O_CREAT, 0666);
		if (pipex->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
	else if (pipex->stout == 2)
	{
		pipex->fdout = open(fileout, O_APPEND | O_RDWR | O_CREAT, 0666);
		if (pipex->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
	else
	{
		pipex->fdout = open("tmp", O_TRUNC | O_RDWR | O_CREAT, 0666);
		if (pipex->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
}

void	check_file(char *filein, char *fileout, t_pipex *pipex)
{
	if (access(filein, F_OK) == 0)
	{
		pipex->fdin = open(filein, O_RDONLY);
		if (pipex->fdin < 0)
			msg_error(ERR_INFILE);
		check_fileout(fileout, pipex);
		return ;
	}
	printf("zs: %s: %s\n", strerror(errno), filein);
	exit (0);
}

/*void	process()
{

}*/

void	child1(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.fdin, 0);
	close(pipex.fd[1]);
	pipex.cmd_args = ft_split(argv[1], ' ');
	pipex.command = get_cmd(pipex.path, pipex.cmd_args[0]);
	if (!pipex.command)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.command, pipex.cmd_args, envp);
}

void	child2(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->fd[0], 0);
	close(pipex->fd[1]);
	dup2(pipex->fdout, 1);
	close(pipex->fd[0]);
	pipex->cmd_args = ft_split(argv[2], ' ');
	pipex->command = get_cmd(pipex->path, pipex->cmd_args[0]);
	if (!pipex->command)
	{
		child_free(pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex->command, pipex->cmd_args, envp);
	return ;
}

void	exe(char **argv, char **envp)
{
	pid_t	p1;
	pid_t	p2;
	t_pipex	pipex;

	ft_create_envp(&pipex, envp);
	//ft_env(&pipex);
	p2 = 0;
	check_file(argv[0], argv[3], &pipex);
	path(envp, &pipex);
	pipe(pipex.fd);
	if (pipe(pipex.fd) < 0)		msg_error(ERR_PIPE);
	p1 = fork();
	if (p1 == 0)
		child1(pipex, argv, envp);
	else
		p2 = fork();
	if (p2 == 0)
		child2(&pipex, argv, envp);
	close(pipex.fdin);
	close(pipex.fdout);
	close(pipex.fd[1]);
	close(pipex.fd[0]);
	waitpid(p2, 0, 0);
	if (pipex.stout == 1)
		print_file();
	free_all(&pipex);
}
