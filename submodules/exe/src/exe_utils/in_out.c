/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:52:59 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/10 18:07:49 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	close_stdin_stdout(t_env *env)
{
	close(env->redirect.original_stdin);
	close(env->redirect.original_stdout);
}

void	restore_stdin(t_env *env)
{
	if (env->redirect.is_red_in)
	{
		dup2(env->redirect.original_stdin, STDIN_FILENO);
		env->redirect.is_red_in = 0;
	}
}

void	restore_stdout(t_env *env)
{
	if (env->redirect.is_red_out)
	{
		dup2(env->redirect.original_stdout, STDOUT_FILENO);
		env->redirect.is_red_out = 0;
	}
}

void	restore_stdin_stdout(t_env *env)
{
	restore_stdin(env);
	restore_stdout(env);
}
