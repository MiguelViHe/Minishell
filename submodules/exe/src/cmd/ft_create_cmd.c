/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/28 12:20:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	print_command(t_command *cmd)
{
	ft_printf("----------cmd----------\n");
	ft_printf("cmd: %s\n", cmd->command);
	ft_printf("cmd_path: %s\n", cmd->cmd_path);
	ft_printf("----------args----------\n");
	print_cmd_args2d(cmd->args);
	ft_printf("-----------------------\n");
}

void	add_normal_token(t_mt *token, t_cmd_args *args, size_t *i, t_env *envp)
{
	char	*aux;

	aux = ft_expand(token->data, token->values.state, envp, 0);
	if (aux && *aux)
	{
		args->names[*i] = aux;
		args->need_space[*i] = token->values.boolean;
		(*i)++;
	}
	else
		free (aux);
}

void	add_token_to_args(t_mt *list, t_cmd_args *args, size_t *i, t_env *envp)
{
	if (!ft_mtcheck_state(list, WILDCARD))
		add_normal_token(list, args, i, envp);
	else
		expand_wildcard(list->data, args, i);
}

t_cmd_args	mtbranch_array2d(t_mt *list, t_env *envp)
{
	t_cmd_args	args;
	size_t		list_size;
	size_t		i;

	if (!list)
		return ((t_cmd_args){NULL, NULL});
	i = 0;
	list_size = ft_mtcount_node_wildcard(list->aux);
	args.names = ft_calloc(1 + list_size + 1, sizeof(char *));
	if (!args.names)
		return ((t_cmd_args){NULL, NULL});
	args.need_space = ft_calloc(1 + list_size + 1, sizeof(t_bool));
	if (!args.need_space)
		return (free(args.names), ((t_cmd_args){NULL, NULL}));
	args.names[i] = ft_expand(list->data, list->values.state, envp, 0);
	args.need_space[i++] = list->values.boolean;
	list = list->aux;
	while (list)
	{
		add_token_to_args(list, &args, &i, envp);
		list = list->vect[RIGHT];
	}
	return (args);
}

t_command	*create_command(t_mt *parsed_cmd, t_env *envp)
{
	t_command	*new_command;

	new_command = malloc(sizeof(t_command));
	if (!new_command)
		ft_error("Error al crear el comando\n", 1);
	new_command->command = ft_expand(parsed_cmd->data, parsed_cmd->values.state,
			envp, 0);
	new_command->args = mtbranch_array2d(parsed_cmd, envp);
	new_command->cmd_path = get_cmd_path(envp->path, new_command->command);
	if (!*new_command->command)
		return (free_command(new_command), NULL);
	return (new_command);
}
