/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:11 by dcastagn          #+#    #+#             */
/*   Updated: 2023/05/19 14:37:41 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void our_echo(char **str)
{
    int i;
    int j;

    i = 1;
    j = -1;
    if (strncmp(str[1], "echo", 4) == 0)
    {
        if (strncmp(str[2], "-n", 2) == 0)
        {
            while (str[2][++j + 1] == 'n')
                ;
            i++;
        }
        while (str[++i])
        {
            while (isspace(str[i][++j]))
                ;
            printwoquotes(str[i]);
            if (str[i + 1])
                printf(" ");
        }
        if (strncmp(str[2], "-n", 2) != 0)
            printf("\n");
    }
}
int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;
    our_echo(argv);

    return 0;
}