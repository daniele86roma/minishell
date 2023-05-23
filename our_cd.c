/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:53:02 by dcastagn          #+#    #+#             */
/*   Updated: 2023/05/23 14:57:22 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

// int main()
// {
//     char s[100];

//     printf("%s\n", getcwd(s, 100));
//     chdir("..");
//     printf("%s\n", getcwd(s, 100));
//     return (0);
// }


int mycd(char **str)
{
	int		args;
	char	*path;
	char	*oldpath;
	char	s[100];
	args = 0;
	printf("%s\n", getcwd(s, 100));
	while (str[++args])
		;
	if (args == 1)
	{
		//chdir(/*home*/);
		return (0);
	}
	//printf("%d\n", args);
	if (args == 2)
	{
		path = strdup(str[1]);
		oldpath = getcwd(0, 0);
		chdir(path);
		path = getcwd(0, 0);
		if (strcmp(path, oldpath))
		{
			printf("%s\n", getcwd(s, 100));
			return(0);
		}
		else
		{
			printf("No such file or directory\n");
			return (1);
		}
	}
}

int	main(int argc, char **argv)
{
	mycd(argv);
	return (0);
}
