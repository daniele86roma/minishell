/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

//ENV
void	ft_create_envp(t_pipex *pipex, char **envp);
void	free_envp(t_pipex *pipex);
void	ft_env(t_pipex *pipex);

//PWD
void	ft_pwd(void);

//EXPORT
void	ft_export(char *s, t_pipex *pipex);

//ECHO
char	**preparsed_filter(char **strs);
void	free_mat(char **mat);
void	printwoquotes(char *cmd);
void	echo_print(char **str, int i, int flag);
int		echoflagcheck(char *str);
void	our_echo(char *argv);

//CD
int		find_homepath(t_pipex *pipex);
char	*find_oldpwd(t_pipex *pipex);
char	*find_pwd(t_pipex *pipex);
void	overwrite_envp(t_pipex *pipex, char *path);
int 	mycd(char **str, t_pipex *pipex);

//EXIT
void	ft_exit(void);
#endif
