/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:41:31 by lde-mich          #+#    #+#             */
/*   Updated: 2023/05/26 10:27:47 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// cmd: ls | cat | grep "ls | cat | grep 'ls | cat | grep end'"

typedef struct s_parser
{
	char	**chest;
	char	*line;
	char	*finaline;

}	t_parser;

//libft

// void	*ft_calloc(size_t count, size_t size);
// char	*ft_strdup(const char *s1);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	ft_strcmp(char *s1, char *s2);
// int		ft_strlen(const char *str);
// char	*ft_strjoin(char *s1, char const *s2);
// char	**ft_split(char const *s, char c);
// void	ft_bzero(void *str, size_t n);

//parser

void	ft_parser(t_parser *parser);
void	ft_parser_init(t_parser *parser);
void	ft_check_quote(t_parser *parser);
void	ft_check_pipe(t_parser *parser);
void	ft_check_redirections(t_parser *parser);
void	ft_print_parser(t_parser *parser);
int 	ft_print_error(t_parser *parser);
void	ft_free(t_parser *parser);
void	ft_boh(t_parser *parser);
char	**mshell(char *s);

#endif
