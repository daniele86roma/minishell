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
	(void)argv;
	if (argc != 1)
		exit(write(2, "Error: Argument\n", 16));
	path(envp, pipex);
	save_io(pipex);
	ft_create_envp(pipex, envp);
	pipex->commands = 0;
	pipex->args = 0;
}

void	var_mat(t_pipex *pipex, char **mat)
{
	int		i;
	char	*tmp;

	if (!mat)
		return ;
	pipex->sost = 1;
	while (pipex->sost == 1)
	{
		i = -1;
		while (mat[++i])
		{
			if (mat[i][0] == '\'')
			{
				pipex->sost = 0;
				continue;
			}
			tmp = sost_arg(mat[i], pipex);
			free(mat[i]);
			mat[i] = tmp;
		}
	}
}

void	print_mat(char **mat)
{
	int i = -1;

	while(mat[++i])
	{
		printf("%s\n", mat[i]);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;
	
	init(envp, &pipex, argc, argv);
	while (1)
	{
		pipex.input = readline("MiniShell> ");
		using_history();
		add_history(pipex.input);
		pipex.mat = mshell(pipex.input);
		var_mat(&pipex, pipex.mat);
		parse(pipex.mat, &pipex);
		exe(&pipex);
		//freepipex.mat
	}
	free_total(&pipex);
	return (0);
}