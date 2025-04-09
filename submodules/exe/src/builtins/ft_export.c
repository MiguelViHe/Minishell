/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:53:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/27 16:39:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	ft_print_export(t_mt *lst_exp)
{
	t_mt	*aux;
	char	**split_exp;

	if (lst_exp != NULL)
	{
		aux = lst_exp;
		while (aux)
		{
			split_exp = ft_split((char *)(aux->data), '=');
			ft_printf("declare -x %s=\"%s\"\n", split_exp[0], split_exp[1]);
			aux = aux->vect[RIGHT];
			free_array2d(split_exp);
		}
	}
}

int	ft_mtmigrate_one(t_mt **src, t_mt **dest, char *migrate)
{
	t_mt	*mig_nod;

	mig_nod = ft_mtpop_one(src, migrate);
	if (mig_nod)
	{
		ft_mtaddlast_right(dest, mig_nod);
		return (0);
	}
	return (1);
}

void	generate_path(char *var, t_env **envp)
{
	char	**array_envp;

	if (ft_pmatch_str(var, "PATH", 4) == 0)
	{
		if ((*envp)->path)
		{
			free_array2d((*envp)->path);
			(*envp)->path = NULL;
		}
		array_envp = mtconvert_array2d((*envp)->mt_env);
		(*envp)->path = split_path_env(array_envp);
		free_array2d(array_envp);
	}
}

static void	modify_counters(t_env *envp)
{
	envp->num_env++;
	envp->num_var--;
}

int	export_builtin(t_command *cmd, t_env *envp)
{
	int		i;
	char	**split_arg;
	char	*value;

	i = 1;
	if (!(cmd->args).names[i])
		ft_print_export(envp->mt_env);
	else
	{
		while (cmd->args.names[i])
		{
			split_arg = ft_split(cmd->args.names[i++], '=');
			if (split_arg[1])
			{
				value = ft_clear_quotes(split_arg[1]);
				ft_setenv(split_arg[0], value, envp, 1);
				free(value);
			}
			if (!ft_mtmigrate_one(&envp->mt_var, &envp->mt_env, split_arg[0]))
				modify_counters(envp);
			generate_path(split_arg[0], &envp);
			free_array2d(split_arg);
		}
	}
	return (envp->last_status = 0, 0);
}
