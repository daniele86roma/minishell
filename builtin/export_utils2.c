/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**remove_space_from(char **mat)
{
	int		i;
	int 	count;
	char	**newmat;

	i = -1;
	count = 0;
	while(mat[++i])
	{
		if (mat[i][0] != ' ')
			count++;
	}
	count++;
	newmat = malloc(sizeof(char **) *count);
	i = -1;
	count = 0;
	while (mat[++i])
	{
		if (mat[i][0] != ' ')
		{
			newmat[count] = ft_strdup(mat[i]);
			count++;
		}
	}
	newmat[count] = 0;
	free_mat(mat);
	return (newmat);
}

void	compact_mat(char **mat)
{
	int		i;
	char	*tmp;
	int 	j;
	
	i = 0;
	while (mat[i])
		i++;
	i--;
	j = i;
	while (i > 0)
	{
		if (mat[i][0] != ' ' && mat[i - 1][0] != ' ')
		{
			tmp = ft_strjoin(mat[i - 1], mat[i]);
			free(mat[i]);
			free(mat[i - 1]);
			mat[i] =ft_strdup(" ");
			mat[i -1] = tmp;
			i = j;
		}
		i--;
	}
}

char	**parsing_export(char *s)
{
	int		i;
	char	**mat;
	char	*wrd;

	i = -1;
	mat = malloc(sizeof(char *) * 1);
	mat[0] = 0;
	while (s[++i])
	{
		if (s[i] == '<' || s[i] == '>' || s[i] == '|' || s[i] == ' ')
			mat = add_chr(mat, s[i]);
		else if (s[i] == '\'' || s[i] == '"')
		{
			wrd = fnd_qts(s, &i);
			mat = add_wrd(mat, wrd);
			continue;
		}
		else
		{
			wrd = fnd_wrd(s, &i);
			mat = add_wrd(mat, wrd);
		}
	}
	compact_mat(mat);
	mat = remove_space_from(mat);
	cmd_trim(mat);
	return (mat);
}

void	ft_export2(char *s, t_pipex *pipex)
{
	int		i;
	int		j;
	char	*key;
	char	*value;
	t_args	arg;

	i = 6;
	while (s[i])
	{
		while (s[i] && !ft_isalpha(s[i]))
			i++;
		key = malloc(ft_strlen(s));
		j = 0;
		while (s[i] && s[i] != '=')
		{
			key[j] = s[i];
			j++;
			i++;
		}
		key[j] = 0;
		if (!s[i])
		{
			free(key);
			continue;
		}
		if (s[i] == '=')
			i++;
		arg.key= ft_strdup(key);
		value = malloc(ft_strlen(s));
		j = 0;
		while (s[i] && s[i] != ' ')
		{
			value[j] = s[i];
			j++;
			i++;
		}
		value[j] = 0;
		arg.value = sost_arg(value, pipex);
		add_arg(&arg, pipex);
		free(value);
		free(key);
		if (s[i])
			i++;
	}
}