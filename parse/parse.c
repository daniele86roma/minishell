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
#include "../pipex/pipex.h"

void	parse(char **mat, t_pipex *pipex)
{
	int			i;
	int			j;
	int			err;
	t_command	com;

	i = -1;
	j = 0;
	err = 0;
	while (err == 0 && mat[++i])
	{
		while (mat[i] && mat[i][j] != '|')
		{
			if (ft_strcmp_args(mat[i], "<") == 0)
				{
					if (mat[++i] = 0 || mat[i][j] == '|')
					{
						write(2, "bash: errore di sintassi vicino al token non atteso", 52);
						//freematrice
						err = 1;
						break ;
					}
					com.redin = 1;
				}
		}
	}
}