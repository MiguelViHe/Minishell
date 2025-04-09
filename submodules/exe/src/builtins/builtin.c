/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:39:30 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 13:18:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "cmd.h"

void	init_builtins(t_builtin *builtins)
{
	builtins[0].name = "cd";
	builtins[0].func = cd_builtin;
	builtins[1].name = "env";
	builtins[1].func = env_builtin;
	builtins[2].name = "pwd";
	builtins[2].func = pwd_builtin;
	builtins[3].name = "exit";
	builtins[3].func = exit_builtin;
	builtins[4].name = "echo";
	builtins[4].func = echo_builtin;
	builtins[5].name = "unset";
	builtins[5].func = unset_builtin;
	builtins[6].name = "export";
	builtins[6].func = export_builtin;
	builtins[7].name = NULL;
	builtins[7].func = NULL;
}

int	execute_builtin(t_command *cmd, t_env *envp)
{
	int			i;
	t_builtin	*bltn;

	i = 0;
	bltn = envp->builtins;
	while (bltn[i].name)
	{
		if (!ft_pmatch_str(cmd->command, bltn[i].name, ft_strlen(bltn[i].name)))
			return (bltn[i].func(cmd, envp));
		i++;
	}
	return (-1);
}
