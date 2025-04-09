/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:18 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 14:09:48 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	execute_command(t_command *cmd, char **env)
{
	(signal(SIGINT, SIG_DFL), signal(SIGQUIT, SIG_DFL));
	if (cmd->cmd_path)
	{
		if (access(cmd->cmd_path, X_OK) == 0)
		{
			execve(cmd->cmd_path, cmd->args.names, env);
			ft_printf_fd(2, "%s: execve failed\n", cmd->args.names[0]);
		}
		else
			ft_printf_fd(2, "%s: Command not accessible\n", cmd->args.names[0]);
	}
	else
		ft_printf_fd(2, "%s: Command not found\n", cmd->args.names[0]);
	free_array2d(env);
	exit(EXIT_FAILURE);
}

int	exe_in_child(t_command *cmd, t_env *envp, char **array_envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		execute_command(cmd, array_envp);
	else if (pid < 0)
	{
		ft_putstr_fd("Command not accessible\n", 2);
		envp->last_status = 1;
		free_array2d(array_envp);
		return (1);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT
			|| WTERMSIG(status) == SIGQUIT))
		write(1, "\n", 1);
	envp->last_status = update_last_status(status);
	free_array2d(array_envp);
	return (0);
}

int	select_command(t_command *cmd, t_env *envp, int is_child)
{
	int			i;
	t_builtin	*bltn;
	char		**array_envp;
	int			status;

	i = 0;
	bltn = envp->builtins;
	while (bltn[i].name)
	{
		if (ft_pmatch_str(cmd->command, bltn[i].name,
				ft_strlen(bltn[i].name)) == 0)
		{
			status = bltn[i].func(cmd, envp);
			if (is_child)
				exit(status);
			return (status);
		}
		i++;
	}
	array_envp = mtconvert_array2d(envp->mt_env);
	if (!is_child)
		return (exe_in_child(cmd, envp, array_envp));
	execute_command(cmd, array_envp);
	return (0);
}

int	process_command(t_mt *node, t_env *env, int is_child)
{
	t_command	*cmd;

	if (!node || !env)
		return (-1);
	cmd = create_command(node, env);
	if (cmd)
	{
		if (ft_pmatch_str(cmd->command, "path", 4) == 0)
			print_array2d(env->path);
		else if (ft_pmatch_str(cmd->command, "vars", 4) == 0)
			print_lst_data(env->mt_var);
		else
			select_command(cmd, env, is_child);
		free_command(cmd);
	}
	node->values.state = END;
	return (0);
}
