/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/14 13:13:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

int	redirect_output(t_mt *node, int open_mode, t_env *env)
{
	int	fd;

	if (!node || !node->aux)
		return (0);
	fd = secure_open(node->aux->key, open_mode);
	if (fd == -1)
		return (env->last_status = 1, 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		ft_error("Error redirigiendo la salida estándar\n", 0);
		return (env->last_status = 1, 1);
	}
	env->redirect.is_red_out = 1;
	close(fd);
	if (env->error_infile_name)
		return (0);
	return (env->last_status = 0, 0);
}
