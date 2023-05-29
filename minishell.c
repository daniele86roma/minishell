/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/05/19 18:32:53 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(char *envp[], t_pipex *pipex)
{
	path(envp, pipex);
	save_io(pipex);
	ft_create_envp(pipex, envp);
<<<<<<< HEAD
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
=======
	create_red(pipex);
>>>>>>> origin/adi-fort
}

int	main(int argc, char **argv, char *envp[])
{
<<<<<<< HEAD
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
	mat[7]=0;
	pipex.input = readline("MiniShell> ");
		pipex.sost = 1;
		while (pipex.sost == 1)
			pipex.input = sost_arg(pipex.input, &pipex);
		mat = ft_split(pipex.input, ' ');*/
	while (1)
	{
		pipex.input = readline("MiniShell> ");
		/*pipex.sost = 1;
		while (pipex.sost == 1)
			pipex.input = sost_arg(pipex.input, &pipex);*/
		mat = ft_split(pipex.input, ' ');
		parse(mat, &pipex);
		free_mat(mat);
		exe(&pipex);
		using_history();
		add_history(pipex.input);
	}
	free_mat(mat);
	free_total(&pipex);
=======
	char		*input;
	t_pipex		pipex;
	t_commands *command;
	t_commands *command2;

	(void)argc;
	(void)argv;
	ft_signal();
	command = malloc(sizeof(t_commands));
	command2 = malloc(sizeof(t_commands));
	command->redout = 0;
	command->redin = 0;
	command->filein = "";
	command->fileout = "";
	command->args = "ls -la";
	command->next = command2;
	command2->redout = 2;
	command2->redin = 0;
	command2->filein = "";
	command2->fileout = "out";
	command2->args = "wc -l";
	command2->next = 0;
	pipex.commands = command;
	init(envp, &pipex);
	exe(&pipex);
	close_red(&pipex);
	while (1)
	{
		input = readline("MiniShell> ");
		if (input == 0)
			exit (0);
		if (*input == 48)
			continue ;
		using_history();
		add_history(input);
	}
>>>>>>> origin/adi-fort
	return (0);
}
