/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:32:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/27 11:25:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	ft_env_free(t_env *environ)
{
	if (environ->mt_env)
		ft_mtclear(&environ->mt_env);
	if (environ->mt_var)
		ft_mtclear(&environ->mt_var);
	if (environ->path)
		free_array2d(environ->path);
	if (environ->input)
		free_null((void **)&environ->input);
	if (environ->prompt)
		free_null((void **)&environ->prompt);
	if (environ->path_history)
		free_null((void **)&environ->path_history);
	if (environ->error_infile_name)
		free_null((void **)&environ->error_infile_name);
	if (environ->prev_dir)
		ft_mtclear(&environ->prev_dir);
	close_stdin_stdout(environ);
	free_null((void **)&environ);
}

void	ft_env_free_func(void **environ)
{
	t_env	*env;

	env = (t_env *)*environ;
	if (env->mt_env)
		ft_mtclear(&env->mt_env);
	if (env->mt_var)
		ft_mtclear(&env->mt_var);
	if (env->path)
		free_array2d(env->path);
	if (env->input)
		free_null((void **)&env->input);
	if (env->prompt)
		free_null((void **)&env->prompt);
	if (env->path_history)
		free_null((void **)&env->path_history);
	if (env->error_infile_name)
		free_null((void **)&env->error_infile_name);
	if (env->prev_dir)
		ft_mtclear(&env->prev_dir);
	close_stdin_stdout(env);
	free_null(environ);
}
