/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_with_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:52:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/19 19:28:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

/*
Generates the arguments for the export command struct.
*/
static t_cmd_args	generate_args(t_mt *node, t_env *envp)
{
	t_cmd_args	args;

	if (!node)
		return ((t_cmd_args){NULL, NULL});
	args.names = ft_calloc(1 + 1 + 1, sizeof(char *));
	if (!args.names)
		return ((t_cmd_args){NULL, NULL});
	args.need_space = ft_calloc(1 + 1 + 1, sizeof(t_bool));
	if (!args.need_space)
		return (free(args.names), ((t_cmd_args){NULL, NULL}));
	args.names[0] = ft_expand("export", COMMAND, envp, 0);
	args.need_space[0] = 1;
	args.names[1] = ft_expand(node->data, node->values.state, envp, 0);
	args.need_space[1] = node->values.boolean;
	return (args);
}

/*
Creates a command special for export assignations.
*/
static t_command	*create_command_assign_export(t_mt *node, t_env *envp)
{
	t_command	*new_command;

	new_command = malloc(sizeof(t_command));
	if (!new_command)
		ft_error("Error al crear el comando\n", 1);
	new_command->command = ft_expand("export", COMMAND, envp, 0);
	new_command->args = generate_args(node, envp);
	new_command->cmd_path = NULL;
	if (!*new_command->command)
		return (free_command(new_command), NULL);
	return (new_command);
}

/*
Process the assignations nodes and the command node, making the assignations
exported to the environment, in case the command execute another shell.
Finally it execute the command.
*/
void	process_child_assign(t_mt *node, t_env *envp)
{
	t_mt		*tmp;
	t_command	*cmd;

	tmp = node;
	while (ft_mtcheck_state(tmp, ASSIGNMENT))
	{
		cmd = create_command_assign_export(tmp, envp);
		if (cmd)
		{
			export_builtin(cmd, envp);
			free_command(cmd);
			tmp = tmp->vect[RIGHT];
		}
	}
	process_command(tmp, envp, 1);
}

/*
Father endizide the assignations nodes, the command node and
assignations after the command node if they exist (because they
don't have to be processed.) to avoid reprocessing them later.
Also process waits for child to ensure that it finishes correctly.
*/
int	process_father_assign(t_mt *node, t_env *envp)
{
	int		status;
	t_mt	*tmp;

	tmp = node;
	while (tmp)
	{
		tmp->values.state = END;
		tmp = tmp->vect[RIGHT];
	}
	if (wait(&status) == -1)
		return (perror("wait"), envp->last_status = 1, 1);
	if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT
			|| WTERMSIG(status) == SIGQUIT))
		write(1, "\n", 1);
	return (envp->last_status = update_last_status(status), 0);
}

/*
Creates a child process to execute the assignations and the command.
Assignations after commads are not processed. 
In this way the assignations are only available for the command.
*/
int	assign_with_command(t_mt *node, t_env *envp)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("fork");
	if (pid == 0)
		process_child_assign(node, envp);
	return (process_father_assign(node, envp));
}
