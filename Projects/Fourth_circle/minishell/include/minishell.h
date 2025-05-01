/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:24 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/01 15:16:41 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

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

// Reassembler
typedef enum e_redir_type
{
	R_IN,
	R_OUT,
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
	char 			**bin;
	t_redir			*redirection;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_arg	*arg;
	t_cmd	*cmd;
	int		last_code;
}	t_data;

int    read_input(t_data *data);

// Execution
int	is_builtin(const char *cmd);
int	exec_builtin(char **args);
int	echo(char **arg);

// Parser
void	ft_lstadd_back_m(t_arg **arg, t_arg *new);
void	ft_lstadd_back_r(t_redir **arg, t_redir *new);
t_arg	*ft_lstnew_m(t_token_type type, char *value);
t_redir	*ft_lstnew_r(t_redir_type type, char *target);
void	ft_lstclear_m(t_arg **lst);
int		check_pipe(t_arg *arg);
int		parser(char *line, t_arg **arg);
void	expanser(t_arg **arg);
int		is_separator(char c);
int		reassembler(t_data *data);