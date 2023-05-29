/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:36 by adi-fort          #+#    #+#             */
/*   Updated: 2023/05/23 12:21:30 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		g_exitcode = 130;
	}
}

void	ft_signal(void)
{
	struct sigaction	signal;

	signal.sa_handler = &ft_handler;
	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
}
