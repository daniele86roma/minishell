/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

typedef struct s_args
{
	char		    *key;
	char            *value;
	struct s_args   *next;
}	t_args;

void    add_arg(t_args *arg, t_pipex *pipex);
void    print_args(t_pipex *pipex);
void	free_args(t_pipex *pipex);
int     ft_strcmp_args(char *s1, char *s2);
void    print_args(t_pipex *pipex);
void	unset_args(t_args *arg, t_pipex *pipex);

#endif