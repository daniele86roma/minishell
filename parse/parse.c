/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	return_builtin(char **mat, int *i)
{
	if (ft_strcmp_args(mat[*i], "pwd") == 0 || ft_strcmp_args(mat[*i], "env") == 0 || ft_strcmp_args(mat[*i], "echo") == 0)
		return (1);
	if (ft_strcmp_args(mat[*i], "cd") == 0 || ft_strcmp_args(mat[*i], "unset") == 0 || ft_strcmp_args(mat[*i], "exit") == 0 || ft_strcmp_args(mat[*i], "export") == 0)
		return (2);
	return (0);
}

int	set_red_out(char **mat, int *i, t_commands *com)
{
	if (ft_strcmp_args(mat[*i], ">") == 0)
	{
		*i = *i + 1;
		if (mat[*i] == 0 || mat[*i][0] == '|')
		{
			write(2, "bash: errore di sintassi vicino al token non atteso", 52);
			//freematrice
			return (1);
		}
		com->fileout = mat[*i];
		com->redout = 2;
		*i = *i +1;
		return (0);
	}
	if (ft_strcmp_args(mat[*i], ">>") == 0)
	{
		*i = *i + 1;
		if (mat[*i] == 0 || mat[*i][0] == '|')
		{
		write(2, "bash: errore di sintassi vicino al token non atteso", 52);
			//freematrice
			return (1);
		}
		com->fileout = mat[*i];
		com->redout = 2;
		*i = *i + 1;
		return (0);
	}
	return  (0);
}

int	set_red_in(char **mat, int *i, t_commands *com)
{
	if (ft_strcmp_args(mat[*i], "<") == 0)
	{
		*i = *i +1;
		if (mat[*i] == 0 || mat[*i][0] == '|')
		{
			write(2, "bash: errore di sintassi vicino al token non atteso", 52);
			//freematrice
			return (1);
		}
		com->filein = mat[*i];
		com->redin = 1;
		*i = *i + 1;
		return (0);
	}
	if (ft_strcmp_args(mat[*i], "<<") == 0)
	{
		*i = *i + 1;
		if (mat[*i] == 0 || mat[*i][0] == '|')
		{
		write(2, "bash: errore di sintassi vicino al token non atteso", 52);
			//freematrice.
			return (1);
		}
		com->filein = mat[*i];
		com->redin = 2;
		*i = *i + 1;
		return (0);
	}
	return (0);
}

void	parse(char **mat, t_pipex *pipex)
{
	int			i;
	int			err;
	t_commands	com;
	char		*arg;
	char		*tmp;

	i = 0;
	err = 0;
	com.redin = 0;
	com.redout = 0;
	while (err == 0 && mat[i])
	{
		arg = ft_strdup("");
		com.builtin = return_builtin(mat, &i);
		while (mat[i] && mat[i][0] != '|')
		{
			err = set_red_in(mat, &i, &com);
			err = set_red_out(mat, &i, &com);
			if (!mat[i])
				break;
			tmp = ft_strjoin(arg, " ");
			free(arg);
			arg = ft_strjoin(tmp, mat[i]);
			i++;
		}
	}
	//freematrice;
	com.args = ft_strtrim(arg, " ");
	new_commands(&com, pipex);
	free(arg);
}