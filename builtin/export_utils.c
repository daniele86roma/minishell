/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*mat_to_string_export(char **mat)
{
	int		i;
	char	*arg;
	char	*tmp;

	i = 0;
	arg = ft_strdup("");
	while (mat[i])
	{
		tmp = ft_strjoin(arg, "");
		free(arg);
		arg = ft_strjoin(tmp, mat[i]);
		free(tmp);
		i++;
	}
	free(arg);
	return(tmp);
}

void	export_trim(char **mat)
{
	int		i;
	char	*tmp;

	i = -1;
	while (mat[++i])
	{
		if (mat[i][0] == '"')
		{
		tmp = ft_strtrim(mat[i], "\"");
		free(mat[i]);
		mat[i] = tmp;
		}
		if (mat[i][0] == '\'')
		{
		tmp = ft_strtrim(mat[i], "'");
		free(mat[i]);
		mat[i] = tmp;
		}
	}
}

void	ft_export(char *s, t_pipex *pipex)
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