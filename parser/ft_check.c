/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:00:00 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/29 10:07:07 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_fchar(t_parser *parser)
{
	int	i;

	i = ft_strlen(parser->line) - 1;
	while (i >= 0 && parser->line[i] == 32)
		i--;
	if (parser->line[i] == '|' || parser->line[i] == '>'
		|| parser->line[i] == '<' || parser->line[i] == '&')
		ft_print_error(parser);
}

void	ft_check_and(t_parser *parser, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (parser->line && parser->line[i])
	{
		if (parser->line[i] == c)
		{
			i++;
			count++;
			while (parser->line && (parser->line[i] == 32 || parser->line[i] == c))
			{
				if (parser->line[i] == c)
					count++;	
				i++;
			}
		if (count > 2)
			ft_print_error(parser);
		}
		i++;
	}
}

void	ft_check_quote(t_parser *parser)
{
	int	i;
	int	j;

	j = 0;
	while (parser->chest && parser->chest[j])
	{
		i = 0;
		while (parser->chest && parser->chest[j][i])
		{
			if (parser->chest[j][i] == '"')
			{
				i++;
				while (parser->chest[j][i] && parser->chest[j][i] != '"')
					i++;
				if (parser->chest[j][i] == 0)
					ft_print_error(parser);
			}
			i++;
		}
		j++;
	}
}

void    ft_check_double(t_parser *parser, char c)
{
    int i;

    i = 0;
    while (parser->line && parser->line[i])
    {
        if (parser->line[i] == c)
        {
            i++;
            while (parser->line && parser->line[i] && parser->line[i] == 32)
                i++;
            if (parser->line[i] == c)
                ft_print_error(parser);
        }
        i++;
    }
}
