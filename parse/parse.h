/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/07 18:07:18 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	parse(char **mat, t_pipex *pipex);
void	trim_mat(char **mat);
char	ft_strcmp(char *s1, char *s2);
int		check_symb_in(char **mat);
int		check_symb_out(char **mat);
int		check_token(t_pipex *pipex);
int		check_quote(char **mat);
char	*mat_to_string(char **mat);
void	print_mat(char **mat);
int		check_quote_generic(char *s, char c);
//matrix.c
char	*fnd_wrd(char *s, int *i);
char	*fnd_qts(char *s, int *i);
char	**add_wrd(char **mat, char *s);
char	**add_chr(char **mat, char c);
char	**create_matrix(char	*s);
#endif
