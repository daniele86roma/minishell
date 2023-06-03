/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:09 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/08 12:43:26 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	check_symb_out(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
	{
		if ((mat[i][0] == '>' || mat[i][0] == '<') && !mat[i + 1])
			return (0);
		if (mat[i][0] == '>' && mat[i + 1][0] != '>')
		{
			i++;
			if (!mat[i] || mat[i + 1][0] == '|' || mat[i + 1][0] == '<' || mat[i + 1][0] == '>')
			return (0);
		}
	}
	return (1);
}

int	check_symb_in(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
	{
		if ((mat[i][0] == '>' || mat[i][0] == '<') && !mat[i + 1])
			return (0);
		if (mat[i][0] == '<' && mat[i + 1][0] != '<')
		{
			i++;
			if (!mat[i] || mat[i + 1][0] == '|' || mat[i + 1][0] == '<' || mat[i + 1][0] == '>')
			return (0);
		}
	}
	return (1);
}
