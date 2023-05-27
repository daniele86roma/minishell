/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sost_Arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_name_var(char *s, int *i)
{
	char	*var;
	int		j;

	*i = *i + 1;
	j = *i;
	while (s[j] && ft_isalnum(s[j]))
		j++;
	var = malloc(j + 1);
	j = 0;
	while (s[*i] && ft_isalnum(s[*i]))
	{
		var[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	var[j] = 0;
	if (j != 0)
		return (var);
	free(var);
	return (0);
}

char	*add_var2string(int *i, t_pipex *pipex, char	*s, char *new)
{
	char	*key;
	char	*value;

	value = "";
	key = get_name_var(s, i);
	if (key != 0)
	{
		value = get_var(key, pipex);
		free(key);
	}
	if (value)
	{
		key = ft_strjoin(new, value);
		free(new);
		return (key);
	}
	return (new);
}

void	cpy_str(char *newstr, int *i, char *s)
{
	char	*tmp;
	int		j;

	tmp = ft_strdup(newstr);
	free(newstr);
	newstr = malloc(ft_strlen(tmp) + 2);
	j = -1;
	while (tmp[++j])
		newstr[j] = tmp[j];
	free(tmp);
	newstr[j] = s[*i];
	newstr[++j] = 0;
}

char	*sost_arg(char *s, t_pipex *pipex)
{
	int		i;
	char	*newstr;
	int		apic;

	i = -1;
	apic = 0;
	newstr = ft_strdup("");
	pipex->sost = 0;
	while (s[++i])
	{
		if (s[i] == '\'')
			apic++;
		if (apic % 2 == 0)
		{
			if (s[i] == '$')
			{
				if (ft_isalpha(s[i + 1]))
				{
					newstr = add_var2string(&i, pipex, s, newstr);
					pipex->sost = 1;
				}
				else if (s[i + 1] >=48 && s[i + 1] <= 57)
				{
					pipex->sost = 1;
					i += 2;
				}
			}
		}
		cpy_str(newstr, &i, s);
	}
	return (newstr);
}