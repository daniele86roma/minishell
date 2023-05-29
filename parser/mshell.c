/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:41:37 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/29 10:07:11 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**mshell(char *s)
{
	t_parser	parser;

	(void)argv;
	if (argc != 1)
		exit(write(1, "Error: Argument\n", 16));
	while (42)
	{
		parser.line = s;
		ft_boh(&parser);
		ft_parser_init(&parser);
		ft_parser(&parser);
		ft_check_fchar(&parser);
		ft_check_and(&parser, '>');
		ft_check_double(&parser, '&');
		ft_check_double(&parser, '|');
		ft_check_quote(&parser);
		// ft_free(&parser);
	}
	return (parser->chest);
}
