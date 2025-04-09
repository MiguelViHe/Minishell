/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:27:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/12 11:15:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

int	manage_redirection(t_mt *node, t_env *env)
{
	int	result;

	if (ft_pmatch_str(node->key, "<", 1) == 0)
		result = redirect_input(node, 0, env);
	else if (ft_pmatch_str(node->key, ">", 1) == 0)
		result = redirect_output(node, 1, env);
	else if (ft_pmatch_str(node->key, ">>", 2) == 0)
		result = redirect_output(node, 2, env);
	else if (ft_pmatch_str(node->key, "<<", 2) == 0)
		result = redirect_heredoc(node, env);
	node->values.state = END;
	return (result);
}

int	manage_logic_operator(t_mt *node, t_env *env, int is_child)
{
	ft_execute_tree(node->vect[LEFT], env, is_child);
	restore_stdin_stdout(env);
	if (ft_pmatch_str(node->key, "&&", 2) == 0)
	{
		if (env->last_status == 0)
			ft_execute_tree(node->vect[RIGHT], env, is_child);
		else if (!is_child)
			endizide_nodes(node->vect[RIGHT]);
	}
	else if (ft_pmatch_str(node->key, "||", 2) == 0)
	{
		if (env->last_status != 0)
			ft_execute_tree(node->vect[RIGHT], env, is_child);
		else if (!is_child)
			endizide_nodes(node->vect[RIGHT]);
	}
	node->values.state = END;
	return (env->last_status);
}

int	manage_operators_redirections(t_mt *node, t_env *env, int is_child)
{
	int	result;

	result = 0;
	if (ft_mtcheck_state(node, REDIRECTION))
		result = manage_redirection(node, env);
	else if (ft_pmatch_str(node->key, "|", 1) == 0)
	{
		result = execute_pipe(node, env);
		if (!is_child)
			endizide_nodes(node);
	}
	else
		result = manage_logic_operator(node, env, is_child);
	return (result);
}

int	manage_commands(t_mt *node, t_env *env, int is_child)
{
	int	result;

	result = 0;
	if (ft_mtcheck_state(node, ASSIGNMENT) && ft_strchr(node->key, '='))
		result = ft_assignation(node, env);
	else if (ft_mtcheck_state(node, PARENTESIS))
	{
		result = ft_execute_tree(node->aux, env, 0);
		node->values.state = END;
	}
	else
		result = process_command(node, env, is_child);
	return (result);
}

int	ft_execute_tree(t_mt *node, t_env *env, int is_child)
{
	int	result;

	if (!node)
		return (0);
	result = 0;
	if (node->values.state != END)
	{
		if (is_ope_or_red(node))
			result = manage_operators_redirections(node, env, is_child);
		else
			result = manage_commands(node, env, is_child);
		if (result == 0)
		{
			result = ft_execute_tree(node->vect[LEFT], env, is_child);
			result = ft_execute_tree(node->vect[RIGHT], env, is_child);
		}
	}
	return (result);
}
