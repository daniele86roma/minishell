/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:11:16 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/18 15:12:18 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_parser(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser->chest[i])
	{
		printf("%s\n", parser->chest[i]);
		i++;
	}
}
