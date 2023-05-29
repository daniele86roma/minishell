/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// librerie standard
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

//libreria libft
# include "libft/libft.h"

//libreria per pipex
# include "pipex/pipex.h"

//libreria per builtin
# include "builtin/builtin.h"

//libreria per args
# include "args/args.h"

//libreria per parsing
# include "parse/parse.h"
# include "parser/parser.h"

#endif
