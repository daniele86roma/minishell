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
				continue;
			tmp = sost_arg(mat[i], pipex);
			free(mat[i]);
			mat[i] = tmp;
			free(tmp);
		}
	}
}

void	print_mat(char **mat)
{
	int i = -1;

	while(mat[++i])
	{
		printf("%s", mat[i]);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;
	char	**mat;

	init(envp, &pipex, argc, argv);
	/*mat = malloc(sizeof(char **)*10);
	mat[0]="<<";
	mat[1]="test";
	mat[2]="cat";
	mat[3]="|";
	mat[4]="cat";
	mat[5]="<<";
	mat[6]="out";
	mat[7]=0;*/
	pipex.input = readline("MiniShell> ");
		pipex.sost = 1;
		while (pipex.sost == 1)
			pipex.input = sost_arg(pipex.input, &pipex);
		mat = ft_split(pipex.input, ' ');
		print_mat(mat);
	/*while (1)
	{
		pipex.input = readline("MiniShell> ");
		pipex.sost = 1;
		while (pipex.sost == 1)
			pipex.input = sost_arg(pipex.input, &pipex);
		mat = ft_split(pipex.input, ' ');
		parse(mat, &pipex);
		free_mat(mat);
		exe(&pipex);
		using_history();
		add_history(pipex.input);
	}*/
	free(mat);
	free_total(&pipex);
	return (0);
}