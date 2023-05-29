/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:21:23 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/20 12:33:49 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_parser *parser)
{
	int	j;

	free(parser->line);
	parser->line = NULL;
	j = 0;
	while (parser->chest && parser->chest[j])
	{
		free(parser->chest[j]);
		parser->chest[j] = NULL;
		j++;
	}
	free(parser->chest);
	parser->chest = NULL;
}

int ft_print_error(t_parser *parser)
{
	write(2, "Syntax error\n", 13); 
	ft_free(parser);
	return (-1);
}
