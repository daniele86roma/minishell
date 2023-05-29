/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:20 by dcastagn          #+#    #+#             */
/*   Updated: 2023/05/26 13:51:09 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_homepath(t_pipex *pipex)
{
	int		i;
	char	*homepwd;

	i = 0;
	if (!pipex->envp)
		return (printf("couldnt access envps\n") - 21);
	while (pipex->envp[i])
	{
		if (!ft_strncmp("HOME=", pipex->envp[i], 5))
			break ;
		i++;
	}
	homepwd = ft_strchr(pipex->envp[i], '/');
	chdir(homepwd);
	return (0);
}

char	*find_oldpwd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp[i])
	{
		if (!ft_strncmp("OLDPWD", pipex->envp[i], 6))
			break ;
		i++;
	}
	return (ft_strchr(pipex->envp[i], '/'));
}

char	*find_pwd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp[i])
	{
		if (strncmp("PWD", pipex->envp[i], 3) == 0)
			break ;
		i++;
	}
	return (ft_strchr(pipex->envp[i], '/'));
}

void	overwrite_envp(t_pipex *pipex, char *path)
{
	char	*a;
	char	*b;

	a = find_pwd(pipex);
	b = find_oldpwd(pipex);
	a = b;
	b = path;
	(void)a;
}
//aggiungere printf("%s\n", getcwd(s, 100)) per prova
// 	char	s[100];

int	mycd(char **str, t_pipex *pipex)
{
	int		args;
	char	*path;
	char	*oldpath;

	args = 0;
	while (str[++args])
		;
	if (args == 1)
		return (find_homepath(pipex));
	else if (args == 2)
	{
		path = strdup(str[1]);
		oldpath = getcwd(0, 0);
		overwrite_envp(pipex, path);
		chdir(path);
		path = getcwd(0, 0);
		if (strcmp(path, oldpath))
			return (0);
		else
			return (printf("No such file or directory\n") - 25);
	}
	else
		return (printf("too many arguments\n") - 18);
}

int	ft_cd(char **mat, t_pipex *pipex)
{
	int		args;
	char	*path;
	char	*oldpath;

	args = -1;
	while (mat[++args])
		;
	if (args == 0)
		return (find_homepath(pipex));
	else if (args == 1)
	{
		path = ft_strdup(mat[1]);
		oldpath = getcwd(0, 0);
		overwrite_envp(pipex, path);
		chdir(path);
		path = getcwd(0, 0);
		if (ft_strcmp(path, oldpath))
			return (0);
		else
			return (printf("No such file or directory\n") - 25);
	}
	else
		return (printf("too many arguments\n") - 18);
}