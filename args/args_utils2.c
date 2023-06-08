/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/08 19:47:49 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy_var_amb(char *key, char *old)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = ft_strlen(key) + 1;
	new = malloc(ft_strlen(old));
	while (old[j])
	{
		new[i] = old[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}

char	*get_var_amb(char *key, t_pipex *pipex)
{
	int		i;
	char	*var;

	i = -1;
	while (pipex->envp[++i])
	{
		if (ft_strncmp(key, pipex->envp[i], ft_strlen(key)) == 0)
		{
			var = copy_var_amb(key, pipex->envp[i]);
			return (var);
		}
	}
	return (0);
}

char	*get_var(char *key, t_pipex *pipex)
{
	t_args	*tmp;
	char	*var;

	if (!key)
		return (0);
	var = get_var_amb(key, pipex);
	if (var != 0)
		return (var);
	tmp = pipex->args;
	while (tmp)
	{
		if (ft_strcmp_args(key, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
