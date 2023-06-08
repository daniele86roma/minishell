/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/07 18:34:51 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_path(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp("PATH", pipex->envp[i], 4) == 0)
			break ;
		i++;
	}
	return (i);
}

void	unset_pat(t_pipex *pipex)
{
	int	i;

	i = find_path(pipex);
	free(pipex->envp[i]);
	pipex->envp[i] = ft_strdup("PATH=");
}

void	set_path(char *s, t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = find_path(pipex);
	tmp = ft_strjoin(pipex->envp[i], s);
	free(pipex->envp[i]);
	pipex->envp[i] = tmp;
}
