/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	in_redirect(t_commands *command)
{
	char	*input;

	input = "start";
	while (ft_strcmp_args(input, command->filein) != 0)
	{
		input = readline(">");
		if (ft_strcmp_args(input, command->filein) != 0)
		{
			write(command->fdin, input, ft_strlen(input));
			write(command->fdin, "\n", 1);
		}
	}
	close(command->fdin);
	if (access("redin", F_OK) == 0)
	{
		command->fdin = open("redin", O_RDONLY);
		if (command->fdin < 0)
			msg_error(ERR_INFILE);
		return ;
	}
}