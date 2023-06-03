/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/05/30 11:46:33 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exitcode;

void	init(char *envp[], t_pipex *pipex, int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		exit(write(2, "Error: Argument\n", 16));
	path(envp, pipex);
	save_io(pipex);
	ft_create_envp(pipex, envp);
	pipex->commands = 0;
	pipex->args = 0;
		
}



int	main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;

	init(envp, &pipex, argc, argv);
	ft_signal();
	while (1)
	{
		pipex.input = readline("MiniShell> ");
		if (!pipex.input)
		{
			free_total(&pipex);
			exit(0);
		}
		else if (pipex.input[0] == 0)
			continue ;
		add_history(pipex.input);
		pipex.mat = create_matrix(pipex.input);
		var_mat(&pipex, pipex.mat);
		if (check_token(&pipex) || check_quote(pipex.mat))
		{
			free_mat(pipex.mat);
			continue;
		}
		parse(pipex.mat, &pipex);
		exe(&pipex);
		free_mat(pipex.mat);
	}
	free_total(&pipex);
	return (0);
}