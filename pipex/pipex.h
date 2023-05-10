/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_CMD "Command not found\n"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"

typedef struct s_pipex
{
	char	**path;
	int		fdin;
	int		fdout;
	char	*command;
	char	**cmd_args;
	int		stout;
	int		stin;
	int		fd[2];
}	t_pipex;

int		msg(char *err);
void	msg_error(char *err);
void	exe(char **argv, char *envp[]);
void	path(char *envp[], t_pipex *pipex);
char	*get_cmd(char **paths, char *cmd);
void	free_all(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	child2(t_pipex *pipex, char **argv, char **envp);
void	child1(t_pipex pipex, char **argv, char **envp);
void	print_file(void);
#endif
