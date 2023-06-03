/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_symb_out(char **mat)
{
	int	i;

	i = - 1;
	while (mat[++i])
	{
		if (!mat[i + 1] && mat[i][0] == '>')
			return (0);
		if (mat[i + 1] && mat[i][0] == '>' && mat[i + 1][0] == '>')
		{
			i++;
			if (!mat[i + 1] || mat[i + 1][0] == '|' || mat[i + 1][0] == '<' || mat[i + 1][0] == '>')
			return (0);
		}
	}
	return (1);
}

int	check_symb_in(char **mat)
{
	int	i;

	i = - 1;
	while (mat[++i])
	{
		if (!mat[i + 1] && mat[i][0] == '<')
			return (0);
		if (mat[i + 1] && mat[i][0] == '<' && mat[i + 1][0] == '<')
		{
			i++;
			if (!mat[i + 1] || mat[i + 1][0] == '|' || mat[i + 1][0] == '<' || mat[i + 1][0] == '>')
			return (0);
		}
	}
	return (1);
}

int	check_token(t_pipex *pipex)
{	
	if (check_symb_in(pipex->mat) == 0 || check_symb_out(pipex->mat) == 0)
	{
    	write(2, "MiniShell: Syntax error near token unexpected\n", 47);
    	free_mat(pipex->mat);
		return (1);
    }
	return (0);
}

int	check_quote_generic(char *s, char c)
{
	int	i;
	int count;

	i= -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c)
			count++;
	}
	return (count % 2);
}

int	check_quote(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
	{
		if (check_quote_generic(mat[i], '"') || check_quote_generic(mat[i], '\''))
		{
			write (1, ">\n", 2);
			return (1);
		}
	}
	if (mat[i - 1])
		{
			if (mat[i -1][0] == '|')
			{
				write (1, ">\n", 2);
				return (1);
			}
		}
	return (0);
}