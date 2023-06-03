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

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr)
	{
		if (size)
		{
			new_ptr = malloc(size);
			if (!new_ptr)
				return (NULL);
			ft_bzero(new_ptr, size);
			ft_memcpy(new_ptr, ptr, size);
		}
		else
		{
			new_ptr = (unsigned char *)malloc (sizeof(ptr));
			if (!new_ptr)
				return (NULL);
		}
		free(ptr);
		return (new_ptr);
	}
	return ((unsigned char *)malloc(sizeof(ptr) * size));
}

int	updatingpwd(t_pipex *pipex)
{
	const char	*var_name;
	char		*new_value;
	char		*new_var;
	int			i;

	var_name = "PWD";
	new_value = getcwd(0, 0);
	i = -1;
	while (pipex->envp[++i] != NULL)
	{
		if (ft_strncmp(pipex->envp[i], var_name, ft_strlen(var_name)) == 0)
		{
			new_var = malloc(ft_strlen(var_name) + ft_strlen(new_value) + 2);
			new_var = ft_strjoin("PWD=", new_value);
			pipex->envp[i] = new_var;
			return (0);
		}
	}
	pipex->envp = ft_realloc(pipex->envp, sizeof(char *) * (i + 2));
	new_var = malloc(ft_strlen(var_name) + ft_strlen(new_value) + 2);
	new_var = ft_strjoin("PWD=", new_value);
	pipex->envp[i] = new_var;
	pipex->envp[i + 1] = 0;
	return (0);
}

int	updatingoldpwd(t_pipex *pipex)
{
	const char	*var_name;
	char		*new_value;
	char		*new_var;
	int			i;

	var_name = "OLDPWD";
	new_value = getcwd(0, 0);
	i = -1;
	while (pipex->envp[++i] != NULL)
	{
		if (ft_strncmp(pipex->envp[i], var_name, ft_strlen(var_name)) == 0)
		{
			new_var = malloc(ft_strlen(var_name) + ft_strlen(new_value) + 2);
			new_var = ft_strjoin("OLDPWD=", new_value);
			pipex->envp[i] = new_var;
			return (0);
		}
	}
	pipex->envp = ft_realloc(pipex->envp, sizeof(char *) * (i + 2));
	new_var = malloc(ft_strlen(var_name) + ft_strlen(new_value) + 2);
	new_var = ft_strjoin("OLDPWD=", new_value);
	pipex->envp[i] = new_var;
	pipex->envp[i + 1] = 0;
	return (0);
}

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

int	ft_cd(char **mat, t_pipex *pipex)
{
	int		args;
	char	*path;
	char	*oldpath;

	args = 0;
	while (mat[++args])
		;
	if (args == 1)
		return (find_homepath(pipex));
	else if (args == 2)
	{
		path = ft_strdup(mat[1]);
		oldpath = getcwd(0, 0);
		updatingoldpwd(pipex);
		chdir(path);
		updatingpwd(pipex);
		path = getcwd(0, 0);
		if (ft_strcmp(path, oldpath))
			return (0);
		else
			return (printf("No such file or directory\n") - 25);
	}
	else
		return (printf("too many arguments\n") - 18);
}