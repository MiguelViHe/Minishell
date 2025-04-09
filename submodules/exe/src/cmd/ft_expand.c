/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:28:34 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/11 14:46:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*ft_in_expansible(char *str, int *i, char *result, t_env *envp)
{
	int		start;
	char	*expanded;
	char	*var_name;

	start = ++(*i);
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	if (*i > start)
	{
		var_name = ft_substr(str, start, *i - start);
		expanded = join_value_var(var_name, result, envp);
		free(var_name);
	}
	else if (str[start] == '?')
		expanded = expand_last_status(result, i, envp);
	else
		expanded = ft_strjoin(result, "$");
	return (free(result), expanded);
}

static char	*ft_not_in_expansible(char *str, int i, char *result)
{
	char	*character;
	char	*expanded;

	character = ft_substr(str, i, 1);
	expanded = ft_strjoin(result, character);
	free(result);
	free(character);
	return (expanded);
}

char	*ft_expand(char *str, int state, t_env *envp, int b)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	if (ft_pmatch_str(str, "$?", 2) == 0)
		return (ft_itoa(envp->last_status));
	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && state != SINGLE_QUOTE)
			result = ft_in_expansible(str, &i, result, envp);
		else
		{
			result = ft_not_in_expansible(str, i, result);
			i++;
		}
	}
	if (b)
		free(str);
	return (result);
}
