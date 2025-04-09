/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assignation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:36:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/13 17:08:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "cmd.h"
#include "exe_utils.h"
#include "types.h"

/*
Check if all the nodes are assignations. 
Return 0 if a command exist in the list.
Return 1 if all are assignations.
*/
int	is_all_assignations(t_mt *node)
{
	t_mt	*tmp;

	tmp = node;
	while (tmp)
	{
		if (!ft_mtcheck_state(tmp, ASSIGNMENT))
			return (0);
		tmp = tmp->vect[RIGHT];
	}
	return (1);
}

/*
Cleans the quotes of a string.
*/
char	*ft_clear_quotes(char *str)
{
	if (!str)
		return (NULL);
	if (str[0] == '\'')
		return (ft_strtrim(str, "'"));
	else if (str[0] == '"')
		return (ft_strtrim(str, "\""));
	else
		return (ft_strdup(str));
}

/*
Creates the new variable or reasign the value of an existing variable.
*/
int	create_assignation(char *cmd, t_env *envp)
{
	char	**split_cmd;
	char	*value;

	if (!cmd || !envp)
		return (1);
	split_cmd = ft_split(cmd, '=');
	value = ft_clear_quotes(split_cmd[1]);
	ft_setenv(split_cmd[0], value, envp, 1);
	generate_path(split_cmd[0], &envp);
	free(value);
	free_array2d(split_cmd);
	return (0);
}

/*
It creates the assignation of variables (name=var). 
If there are one or more assignations followed by a command the variables are 
created just for the env of this command. After that they dissapear.
*/
int	ft_assignation(t_mt *node, t_env *envp)
{
	if (!node || !envp)
		return (-1);
	if (is_all_assignations(node))
	{
		if (create_assignation(node->data, envp))
		{
			restore_stdin_stdout(envp);
			ft_printf("assignation is not possible.\n");
			envp->last_status = 1;
			return (1);
		}
		node->values.state = END;
		return (envp->last_status = 0, 0);
	}
	else
		return (assign_with_command(node, envp));
}
