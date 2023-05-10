/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_file(void)
{
	char	*buf;
	int		fd;

	fd = open("tmp", O_RDONLY);
	buf = malloc(1);
	while (read(fd, buf, 1))
	{
		write(2, &buf[0], 1);
	}
	free(buf);
	close(fd);
}
