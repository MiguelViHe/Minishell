/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:53:30 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/27 16:39:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	del_and_update(t_mt **list, t_mt *del, int *num, t_env **envp)
{
	if (ft_pmatch_env(del->key, "PATH", 4) == 0)
	{
		free_array2d((*envp)->path);
		(*envp)->path = NULL;
	}
	ft_mtdel_one(list, del);
	(*num)--;
}

int	unset_builtin(t_command *cmd, t_env *envp)
{
	int		i;
	t_mt	*del;
	t_mt	**list;
	int		*num;

	i = 1;
	while (cmd->args.names && cmd->args.names[i])
	{
		del = ft_mtsearch_key(envp->mt_env, cmd->args.names[i]);
		list = &envp->mt_env;
		num = &envp->num_env;
		if (!del)
		{
			del = ft_mtsearch_key(envp->mt_var, cmd->args.names[i]);
			list = &envp->mt_var;
			num = &envp->num_var;
		}
		if (del)
			del_and_update(list, del, num, &envp);
		i++;
	}
	return (envp->last_status = 0, 0);
}
