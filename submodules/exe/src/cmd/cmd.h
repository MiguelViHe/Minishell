/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:46:10 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/14 12:25:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# define READ_END 0
# define WRITE_END 1

# include "libft.h"
# include "mt.h"
# include "types.h"

typedef struct s_cmd_args
{
	char	**names;
	t_bool	*need_space;
}			t_cmd_args;

typedef struct s_command
{
	char		*command;
	char		*cmd_path;
	t_cmd_args	args;
}			t_command;

/* ************************************************************************** */
/*                                 COMMANDS                                   */
/* ************************************************************************** */

// execution.c
int			ft_execute_tree(t_mt *node, t_env *env, int is_child);

// ft_assign_with_command.c
int			assign_with_command(t_mt *node, t_env *envp);

// ft_assignation.c
int			ft_assignation(t_mt *node, t_env *envp);
char		*ft_clear_quotes(char *str);

// ft_create_cmd.c
t_command	*create_command(t_mt *parsed_cmd, t_env *envp);
void		print_command(t_command *cmd);

// ft_execmd.c
int			process_command(t_mt *node, t_env *env, int is_child);

// ft_expand_utils.c
char		*expand_last_status(char *result, int *i, t_env *envp);
int			ft_check_eof(char *str);
char		*join_value_var(char *var_name, char *result, t_env *envp);
// int			is_in_single_quotes(char *str, int pos);

// ft_expand.c
char		*ft_expand(char *str, int state, t_env *envp, int b);

// ft_expand_input.c
char		*ft_expand_input(char *str, t_env *envp);

// ft_free_command.c
void		free_command(t_command *cmd);

// ft_get_cmd_path.c
char		*get_cmd_path(char **split_path, const char *cmd);

// ft_pipe_cmd.c
void		perror_and_exit(char *msg);
int			execute_pipe(t_mt *node, t_env *env);

// ft_redirect_heredoc.c
int			redirect_heredoc(t_mt *node, t_env *env);

// ft_redirect_input.c
int			redirect_input(t_mt *node, int open_mode, t_env *env);
void		print_openfile_error(char *file);

// ft_redirect_output.c
int			redirect_output(t_mt *node, int open_mode, t_env *env);

// ft_update_last_status.c
int			update_last_status(int status);

// ft_wildcard.c
int			ft_fnmatch(const char *pattern, const char *str);
int			count_wildcard(char *pattern);
void		expand_wildcard(char *pattern, t_cmd_args *args, size_t *i);

#endif