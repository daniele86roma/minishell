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
	t_commands command;

	init(envp, &pipex, argc, argv);
	
	command.args = "";
	command.redin = 0;
	command.redout = 1;
	command.fileout = "tfddf";
	command.builtin = 1;
	new_commands(&command, &pipex);
	command.args = "wc";
	command.redout = 1;
	command.fileout = "out2";
	command.builtin = 1;
	new_commands(&command, &pipex);
	exe(&pipex);
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