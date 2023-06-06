/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_args(t_args *arg, t_pipex *pipex)
{
	t_args	*tmp;

	tmp = pipex->args;
	while(tmp)
	{
		if (ft_strcmp_args(arg->key, tmp->key) == 0)
		{
			tmp->value = arg->value;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	add_ordered(t_args *new, t_pipex *pipex)
{
	t_args	*tmp;

	tmp = pipex->args;
	while(tmp)
	{
		if (ft_strcmp_args(new->key, tmp->key) <= 0 && (tmp->next == 0 || ft_strcmp_args(new->key, tmp->next->key) >= 0))
		{
			new->next = tmp->next;
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
	new->next = pipex->args;
	pipex->args = new;
}

void	add_arg(t_args *arg, t_pipex *pipex)
{
	t_args	*new;

	if (check_args(arg, pipex))
		return;
	new = malloc(sizeof(t_args));
	new->key = arg->key;
	new->value = arg->value;
	if (!pipex->args)
		{
			new->next = 0;
			pipex->args = new;
			return;
		}
	add_ordered(new, pipex);
}

void	unset_args(char *key, t_pipex *pipex)
{
	t_args	*tmp;
	t_args	*prev;

	tmp = pipex->args;
	prev = tmp;
	if (tmp && ft_strcmp_args(tmp->key, key) == 0)
	{
		pipex->args = pipex->args->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		return ;
	}
	while(tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		if (tmp && ft_strcmp_args(tmp->key, key) == 0)
		{
			prev->next = tmp->next;
			free(tmp->value);
			free(tmp->key);
			free(tmp);
			return ;
		}
	}	
}