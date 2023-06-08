/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/07 18:12:03 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	reduce_fnd_qts(char *s2, int *j, int *i, char c)
{
	*j = 1;
	*i = *i + 1;
	s2[0] = c;
}

void	reduce_fnd_qts2(char *s, char *s2, int *j, int *i)
{
	s2[*j] = s[*i];
	s2[*j + 1] = 0;
	if (!s[*i])
		*i = *i - 1;
}

char	*fnd_qts(char *s, int *i)
{	
	int		k;
	int		j;
	char	*s2;
	char	c;

	j = 1;
	k = *i;
	c = s[k];
	k++;
	while (s[k] && s[k++] != c)
		j++;
	s2 = malloc(j + 2);
	reduce_fnd_qts(s2, &j, i, c);
	while (s[*i] && s[*i] != c)
	{
		s2[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	reduce_fnd_qts2(s, s2, &j, i);
	return (s2);
}