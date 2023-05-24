/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/05/24 09:36:08 by adi-fort         ###   ########.fr       */
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

//EXIT
void	ft_exit(void);

//CD
void	ft_cd(void);

#endif
