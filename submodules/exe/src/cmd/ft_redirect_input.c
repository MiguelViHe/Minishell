/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/14 12:20:16 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	print_openfile_error(char *file)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}

int	redirect_input(t_mt *node, int open_mode, t_env *env)
{
	int	fd;

	restore_stdin(env);
	fd = secure_open(node->aux->key, open_mode);
	if (fd == -1)
	{
		endizide_nodes(node);
		if (!env->error_infile_name)
			env->error_infile_name = ft_strdup(node->aux->key);
		return (env->last_status = 1, 0);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		ft_error("Error redirigiendo la entrada estándar\n", 0);
		return (env->last_status = 1, 1);
	}
	env->redirect.is_red_in = 1;
	close(fd);
	return (env->last_status = 0, 0);
}
