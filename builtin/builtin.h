/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
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

//EXIT
void	ft_exit(void);

//UNSET
void	ft_unset(char *s, t_pipex *pipex);

#endif
