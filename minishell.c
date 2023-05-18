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

void	init(char *envp[], t_pipex *pipex, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	path(envp, pipex);
	save_io(pipex);
	ft_create_envp(pipex, envp);
	pipex->commands = 0;
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex		pipex;
	t_commands *command;
	t_commands *command2;

	command2 = malloc(sizeof(t_commands));
	command = malloc(sizeof(t_commands));
	
	command->redout = 0;
	command->redin = 1;
	command->filein = "in";
	command->fileout = "";
	command->args = "cat";

	command2->redout = 1;
	command2->redin = 1;
	command2->filein = "in";
	command2->fileout = "out4";
	command2->args = "cat";
	
	init(envp, &pipex, argc, argv);
	add_command(command, &pipex);
	add_command(command2, &pipex);
	create_red(&pipex);
	exe(&pipex);
	close_red(&pipex);
	/*while (1)
	{
		pipex.input = readline("MiniShell> ");
		if (pipex.input[0] == 48)
			exit (0);
		using_history();
		add_history(pipex.input);
	}*/
	return (0);
}