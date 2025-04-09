/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:20:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/27 11:24:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "mt.h"

# define BUILTINS 8

typedef struct s_command	t_command;
typedef struct s_env		t_env;

typedef int					(*t_builtin_func)(t_command *cmd, t_env *envp);

typedef struct s_builtin
{
	char					*name;
	t_builtin_func			func;
}							t_builtin;

typedef struct s_redirect
{
	int						is_red_in;
	int						is_red_out;
	int						original_stdin;
	int						original_stdout;
}							t_redirect;

typedef struct s_env
{
	t_mt					*mt_env;
	int						num_env;
	t_mt					*mt_var;
	int						num_var;
	char					**path;
	char					*prompt;
	char					*input;
	char					*path_history;
	char					*error_infile_name;
	int						last_status;
	t_redirect				redirect;
	t_builtin				builtins[BUILTINS];
	t_mt					*prev_dir;
}							t_env;

#endif