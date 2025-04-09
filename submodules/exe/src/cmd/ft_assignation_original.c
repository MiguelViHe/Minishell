/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assignation_original.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:36:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/12 19:22:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "builtin.h"
// #include "cmd.h"
// #include "exe_utils.h"
// #include "types.h"

// int	check_all_assignations(char **args)
// {
// 	int	i;

// 	i = 0;
// 	while (args[i])
// 	{
// 		if (!ft_strchr(args[i], '='))
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_clear_quotes(char *str)
// {
// 	if (!str)
// 		return (NULL);
// 	if (str[0] == '\'')
// 		return (ft_strtrim(str, "'"));
// 	else if (str[0] == '"')
// 		return (ft_strtrim(str, "\""));
// 	else
// 		return (ft_strdup(str));
// }

// int	create_assignations(t_command *cmd, t_mt *node, t_env *envp)
// {
// 	char	**split_arg;
// 	char	*value;
// 	int		i;

// 	if (!cmd || !node || !envp)
// 		return (1);
// 	i = 0;
// 	while (cmd->args.names[i])
// 	{
// 		split_arg = ft_split(cmd->args.names[i], '=');
// 		value = ft_clear_quotes(split_arg[1]);
// 		ft_setenv(split_arg[0], value, envp, 1);
// 		generate_path(split_arg[0], &envp);
// 		free(value);
// 		free_array2d(split_arg);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_assignation(t_mt *node, t_env *envp)
// {
// 	int			result;
// 	t_command	*cmd;

// 	if (!node || !envp)
// 		return (-1);
// 	cmd = create_command(node, envp);
// 	result = check_all_assignations(cmd->args.names);
// 	if (result == 0)
// 		create_assignations(cmd, node, envp);
// 	else
// 	{
// 		restore_stdin_stdout(envp);
// 		ft_printf("assignation: '%s' is not found.\n", cmd->args.names[result]);
// 		envp->last_status = result;
// 	}
// 	node->values.state = END;
// 	return (free_command(cmd), result);
// }
