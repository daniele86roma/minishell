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
	//char	*input;
	char	**comandi;
	//int		fdcopy;
	//int		fd2copy;

	(void)envp;
	/*fdcopy = dup(STDOUT_FILENO);
	fd2copy = dup(STDIN_FILENO);*/
	comandi = malloc(4 * sizeof(char *));
	comandi[0] = "in";
	comandi[3] = "ciao";
	comandi[1] = "echo";
	comandi[2] = "cat";
	(void)argc;
	(void)argv;
	ft_pwd();
	exe(comandi, envp);
	/*dup2(fdcopy, 1);
	dup2(fd2copy, 0);
	close(fdcopy);
	close(fd2copy);*/
	/*while (1)
	{
		input = readline("MiniShell> ");
		if (*input == 48)
		exit (0);
		using_history();
		add_history(input);
	}*/
	return (0);
}
