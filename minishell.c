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

void	print_mat(char **mat)
{
	int i = -1;

	while(mat[++i])
	{
		printf("%s\n", mat[i]);
	}
}

char	*mat_to_string(char **mat)
{
	int		i;
	char	*arg;
	char	*tmp;

	i = 0;
	arg = ft_strdup("");
	while (mat[i])
	{
		tmp = ft_strjoin(arg, " ");
		free(arg);
		arg = ft_strjoin(tmp, mat[i]);
		free(tmp);
		i++;
	}
	tmp = ft_strtrim(arg, " ");
	free(arg);
	return(tmp);
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
		print_mat(pipex.mat);
		parse(pipex.mat, &pipex);
		exe(&pipex);
		free_mat(pipex.mat);
	}
	free_total(&pipex);
	return (0);
}