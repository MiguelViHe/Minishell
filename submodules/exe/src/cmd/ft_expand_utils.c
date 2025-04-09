/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:36:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/03 18:15:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*join_value_var(char *var_name, char *result, t_env *envp)
{
	char	*var_value;

	var_value = ft_getenv_ptr_value(var_name, envp->mt_env);
	if (!var_value)
		var_value = ft_getenv_ptr_value(var_name, envp->mt_var);
	if (var_value)
		return (ft_strjoin(result, var_value));
	else
		return (ft_strjoin(result, ""));
}

char	*expand_last_status(char *result, int *i, t_env *envp)
{
	char	*aux;
	char	*expanded;

	aux = ft_itoa(envp->last_status);
	expanded = ft_strjoin(result, aux);
	(*i)++;
	free(aux);
	return (expanded);
}

int	ft_check_eof(char *str)
{
	if (!str)
		return (0);
	if (*str == '\'' || *str == '\"')
		return (3);
	return (1);
}
