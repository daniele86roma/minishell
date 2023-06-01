/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:11 by dcastagn          #+#    #+#             */
/*   Updated: 2023/05/26 11:16:22 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**preparsed_filter(char **strs)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (strs[++i])
		if (ft_strncmp(strs[i], "|", 1) || (ft_strncmp(strs[i], " ", 1)))
			j++;
	ret = malloc(sizeof(char *) * (j + 1));
	if (!ret)
		return (0);
	i = -1;
	j = -1;
	while (strs[++i])
	{
		if (!ft_strncmp(strs[i], "|", 1) || (!ft_strncmp(strs[i], " ", 1)))
			continue ;
		ret[++j] = ft_strdup(strs[i]);
		if (!ret[j])
			return (0);
	}
	ret[++j] = 0;
	return (ret);
}

void	printwoquotes(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\"')
			while (cmd[++i] != '\"')
				printf("%c", cmd[i]);
		else if (cmd[i] == '\'')
			while (cmd[++i] != '\'')
				printf("%c", cmd[i]);
		else
			printf("%c", cmd[i]);
	}
}

void	echo_print(char **str, int i, int flag)
{
	while (str[i])
	{
		printwoquotes(str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	if (flag == 0)
		return ;
	else
		printf("\n");
}

int	echoflagcheck(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	our_echo(char *s)
{
	int		i;
	int		flag;
	char	**str;
	char	**argv;

	argv = create_matrix(s);
	str = preparsed_filter(argv);
	i = 1;
	if (!str[i])
	{
		printf("\n");
		free(str[0]);
		free(str);
		return ;
	}
	if (!ft_strncmp(str[i], "-n", 2) && echoflagcheck(str[i]))
	{
		flag = 0;
		i++;
		while (str[i] && !ft_strncmp(str[i], "-n", 2) && echoflagcheck(str[i]))
			i++;
	}
	else
		flag = 1;
	echo_print(str, i, flag);
	free_mat(str);
	free_mat(argv);
}