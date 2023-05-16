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

int	main(int argc, char **argv, char *envp[])
{
	char	*input;
	t_pipex	pipex;
	t_commands command;

	(void)argc;
	(void)argv;
	path(envp, &pipex);
	command.redout = 1;
	command.filein = "in";
	command.fileout = "out";
	command.args = "ls -la";
	command.next = 0;
	ft_create_envp(&pipex, envp);
	pipex.commands = &command;
	exe(&pipex);
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
