/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:24 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/03 05:09:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

// Disassembler
typedef enum e_token_type
{
	T_WORD,
	T_SPACE,
	T_PIPE,
	T_R_IN,
	T_R_OUT,
	T_HEREDOC,
	T_APPEND,
	T_QUOTE,
	T_DQUOTE,
	T_VAR,
	T_UNKNOWN	
}	t_token_type;

typedef struct s_arg
{
	char			*value;
	t_token_type	type;
	struct s_arg	*next;
}	t_arg;

typedef enum e_redir_type
{
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC,
	NONE
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*target;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	int				pipe;
	char			**bin;
	t_redir			*redirection;
	int				input_fd;
	int				output_fd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_arg	*arg;
	t_cmd	*cmd;
	int		last_code;
}	t_data;

// ISOLATED
typedef struct s_expansion
{
	char	*ret;
	char	*env;
	char	*left;
	char	*right;
	char	*joined;
	char	*new_str;
}	t_expansion;

typedef struct s_io_config
{
	int		i;
	int		heredoc;
	int		index_in;
	int		index_out;
}	t_io;

int		read_input(t_data *data);

// Execution
int		is_builtin(const char *cmd);
int		exec_builtin(char **args);
int		echo(char **arg);

// Parser
void	ft_lstadd_back_m(t_arg **arg, t_arg *new);
void	ft_lstadd_back_r(t_redir **arg, t_redir *new);
t_arg	*ft_lstnew_m(t_token_type type, char *value);
t_redir	*ft_lstnew_r(t_redir_type type, char *target);
void	ft_lstclear_m(t_arg **lst);
void	ft_lstclear_c(t_cmd **lst);
void	ft_lstclear_r(t_redir **lst);
int		check_pipe(t_arg *arg);
int		check_quote(char *line);
int		parser(char *line, t_arg **arg);
void	expanser(t_arg **arg);
int		is_separator(char c);
int		reassembler(t_data *data);
int		check_token_redir(t_token_type token);
int		check_token_word(t_token_type token);
int		check_redir_legit(t_arg *arg);
int		token_r_right(char *c, int i, t_arg **arg);
int		token_r_left(char *c, int i, t_arg **arg);
int		token_word(char *c, int i, t_arg **arg, int v);
void	reassembler_check(t_arg **arg, t_cmd **cmd);
void	append_arg(char *c, int start, int len, t_arg **arg, t_token_type type);
int		check_cmd(char *s, t_arg **arg);

#endif