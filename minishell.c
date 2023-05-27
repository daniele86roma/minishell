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
	pipex->args = 0;
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;
	char	**mat;

	init(envp, &pipex, argc, argv);
	mat = malloc(sizeof(char **) *10);
	mat[0] = "export";
	mat[1] = "c=10 f=3";
	mat[2] = 0;
	parse(mat, &pipex);
	exe(&pipex);
	print_args(&pipex);
	mat[0] = "unset";
	mat[1] = "c";
	mat[2] = "a";
	mat[3] = 0;
	parse(mat, &pipex);
	exe(&pipex);
	print_args(&pipex);
	/*while (1)
	{
		pipex.input = readline("MiniShell> ");
		if (pipex.input[0] == 48)
			exit (0);
		using_history();
		add_history(pipex.input);
	}*/
	free(mat);
	free_total(&pipex);
	return (0);
}