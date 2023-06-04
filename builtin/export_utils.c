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
		while (s[i] && s[i] == ' ')
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
		if (s[i])
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
		if (s[i])
			i++;
		arg.value = sost_arg(value, pipex);
		add_arg(&arg, pipex);
		free(value);
		free(key);
	}
}