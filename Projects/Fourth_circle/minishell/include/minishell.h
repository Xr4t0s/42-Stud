/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:24 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 05:26:05 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

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

typedef enum e_redir
{
	R_IN,
	R_OUT
}	t_redir;

typedef struct s_cmd{
	char **cmd; // 'echo "hello"'
	t_redir	redirection; // > redir
}	t_cmd;

typedef struct s_arg
{
	t_token_type	type;
	char			*value;
	struct s_arg	*next;
}	t_arg;

typedef struct s_data
{
	t_arg	*arg;
}	t_data;

int	read_input();

// Execution
int	is_builtin(const char *cmd);
int	exec_builtin(char **args);
int	echo(char **arg);

// Parser
void	ft_lstadd_back_m(t_arg **arg, t_arg *new);
t_arg	*ft_lstnew_m(t_token_type type, char *value);
int	parser(char *line, t_arg **arg);
int	is_separator(char c);