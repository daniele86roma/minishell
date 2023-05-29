/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:02:17 by dcastagn          #+#    #+#             */
/*   Updated: 2023/05/16 11:58:26 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handlequotes(char *str, int *i)
{
	
}

void redirectOut(char *fileName, int flag)
{
	int	out;
	if (flag)
		out = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0600);
	else
		out = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	dup2(out, 1);
	if (out < 0)
	{
		perror("Error cannot open file\n");
		exit(1);
	}
	if (dup2(out, STDOUT_FILENO) < 0)
	{
		perror("Error cannot redirect output");
		exit(1);
	}
	close(out);
}

void redirectIn(char *fileName)
{
	int	in;
	in = open(fileName, O_RDONLY);
	if (in < 0)
	{
		perror("Error cannot open file\n");
		exit(1);
	}
	dup2(in, 0);
	close(in);
}

char	*recognize_filename(char *str, int *i)
{
	int		filename_index;
	char	*filename;

	filename_index = 0;
	filename = malloc(sizeof(char) * 256);
	if (!filename)
		perror("Errore allocazione filename redirection");
	while (ft_isspace(str[++(*i)]))
			;
	while (!ft_isspace(str[(*i)]) && str[(*i)] != '\0' && filename_index < 255)
	{
		if (str[*i] == '\"')
		{
			while (str[++(*i)] != '\"')
				filename[filename_index++] = str[(*i)++];
		}
		if (str[*i] == '\'')
		{
			while (str[++(*i)] != '\'')
				filename[filename_index++] = str[(*i)++];
		}
		filename[filename_index++] = str[(*i)++];
	}
	filename[filename_index] = '\0';
	return (filename);
}

void	redict(char **input)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < strlen(input[j][i]))
	{
		if (input[j][i] == '\'')
			while (input[j][++i] != '\'')
				;
		if (input[j][i] == '\"')
			while (input[j][++i] != '\"')
				;
		if (input[j][i] == '>')
		{
			i++;
			if (input[j][i] == '>')
			{
				i++;
				redirectOut(recognize_filename(input[j], &i), 1);
			}
			else
				redirectOut(recognize_filename(input[j], &i), 0);
		}
		if (input [j][i]  == '<')
		{
			i++;
			if (input[j][i] == '<')
			{
				i++;
				ft_heredoc(recognize_filename(input[j], &i));
			}	
			redirectIn(recognize_filename(input[j], &i));
		}
	}
}
