/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:19:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/27 12:54:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

// Include any necessary headers here

# include "libft.h"
# include "types.h"
# include "cmd.h"

//builtin.h
void	init_builtins(t_builtin *builtins);
int		execute_builtin(t_command *cmd, t_env *envp);

//ft_cd_utils.c
void	set_prev_dir(char *dir, t_env *envp);
char	*create_complete_path(t_mt *dir_history);
int		move_valid_place(char **new_path, t_env *env, t_command *cmd);

//ft_cd.c
int		cd_builtin(t_command *cmd, t_env *envp);

//ft_env.c
int		env_builtin(t_command *cmd, t_env *envp);

//ft_pwd.c
int		pwd_builtin(t_command *cmd, t_env *envp);

//ft_exit.c
int		exit_builtin(t_command *cmd, t_env *envp);

//ft_echo.c
int		echo_builtin(t_command *cmd, t_env *envp);

//ft_unset.c
int		unset_builtin(t_command *cmd, t_env *envp);

//ft_export.c
int		export_builtin(t_command *cmd, t_env *envp);
void	generate_path(char *var, t_env **envp);

#endif
