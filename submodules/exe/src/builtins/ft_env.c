/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:47:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/26 11:37:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

int	env_builtin(t_command *cmd, t_env *envp)
{
	t_mt	*aux;

	(void)cmd;
	if (envp->mt_env != NULL)
	{
		aux = envp->mt_env;
		while (aux)
		{
			ft_printf("%s\n", (char *)(aux->data));
			aux = aux->vect[RIGHT];
		}
		return (envp->last_status = 0, 0);
	}
	return (envp->last_status = 1, 1);
}
