/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:11:22 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/29 10:13:02 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	trim_mat(char **mat)
{
	char	*tmp;
	int		i;

	i = -1;
	if(!mat)
		return;
	while(mat[++i])
	{
		tmp = ft_strtrim(mat[i], " ");
		free(mat[i]);
		mat[i] = tmp;
	}
}

void	ft_boh(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parser->line[i++])
		if (parser->line[i] == '|' || parser->line[i] == '>' || parser->line[i] == '<')
			j++;
	parser->finaline = (char *) ft_calloc (i + j * 2 + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (parser->line[i])
	{
		if (parser->line[i] == '|' || parser->line[i] == '<' || parser->line[i] == '>')
		{
			parser->finaline[j++] = 32;
			parser->finaline[j++] = parser->line[i];
			parser->finaline[j++] = 32;
		}
		else
			parser->finaline[j++] = parser->line[i];
		i++;
	}
	//free(parser->line);
	parser->line = parser->finaline;
	parser->finaline = NULL;
}

void	ft_parser_init(t_parser *parser)
{
	int		i;
	char	**temp;
	int		count;

	temp = ft_split(parser->line, 32);
	i = 0;
	count = 0;
	while (parser->line[i])
	{
		if (parser->line[i] == '|')
			count++;
		i++;
	}
	i = 0;
	while (temp[i])
		i++;
	
	parser->chest = (char **) ft_calloc (i + 10 + count, sizeof(char *));
}


void	ft_parser(t_parser *parser)
{
	int		i;
	int		j;
	int		k;
	int		x;
	int		quote;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	quote = 0;
	while ((size_t)i < ft_strlen(parser->line))
	{
		while (parser->line[i] && parser->line[i] != 32
			&& parser->line[i] != '"' && parser->line[i] != '\'')
			i++;
		quote = 2 * (parser->line[i] == '"') + (parser->line[i] == '\'');
		if (quote && ++i)
			while (parser->line[i] && ((parser->line[i] != '"'
				&& quote == 2) || (parser->line[i] != '\'' && quote == 1)))
				i++;
		i += (quote != 0);
		if (ft_strcmp(ft_substr(parser->line, k + x, i - k), " ") != 0)
		parser->chest[j++] = ft_substr(parser->line, k + x, i - k);
		x += (x == 0);
			k = i++;
	}
}