/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(char *envp[], t_pipex *pipex)
{
	path(envp, pipex);
	save_io(pipex);
	ft_create_envp(pipex, envp);
	create_red(pipex);
}

int	main(int argc, char **argv, char *envp[])
{
	char		*input;
	t_pipex		pipex;
	t_commands command;

	(void)argc;
	(void)argv;
	command.redout = 0;
	command.redin = 1;
	command.filein = "in";
	command.fileout = "out";
	command.args = "ls -la";
	command.next = 0;
	pipex.commands = &command;
	init(envp, &pipex);
	exe(&pipex);
	close_red(&pipex);
	while (1)
	{
		input = readline("MiniShell> ");
		if (*input == 48)
			exit (0);
		using_history();
		add_history(input);
	}

	return (0);
}
