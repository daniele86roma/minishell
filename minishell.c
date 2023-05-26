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
	t_args	arg;
	char	*str;
	char	*res;

	init(envp, &pipex, argc, argv);
	mat = malloc(sizeof(char **) *10);
	mat[0] = 0;
	arg.key = "var";
	arg.value = "10";
	add_arg(&arg, &pipex);
	str = ft_strdup("$var, $4, $f, $ff, $.");
	res = sost_arg(str, &pipex);
	printf("%s\n", str);
	printf("%s\n", res);
	parse(mat, &pipex);
	exe(&pipex);
	/*while (1)
	{
		pipex.input = readline("MiniShell> ");
		if (pipex.input[0] == 48)
			exit (0);
		using_history();
		add_history(pipex.input);
	}*/
	free(str);
	free(mat);
	free(res);
	free_total(&pipex);
	return (0);
}