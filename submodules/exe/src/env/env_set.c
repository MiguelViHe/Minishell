/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:51:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 19:32:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

char	*build_new_env(const char *name, const char *value, int total_len)
{
	char	*str;

	str = ft_calloc(total_len, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, name, total_len);
	ft_strlcat(str, "=", total_len);
	if (value)
		ft_strlcat(str, value, total_len);
	return (str);
}

static void	replace_node(t_mt **list, const char *name, char *new_env)
{
	t_mt	*new_node;

	new_node = ft_mtnew(new_env, new_env, STRING);
	ft_mtreplace(list, ft_mtsearch_key(*list, name), new_node);
}

int	ft_setenv(const char *name, const char *value, t_env *envp, int is_env)
{
	int		total_len;
	char	*env_str;
	char	*new_env;
	t_mt	**list;

	total_len = ft_strlen(name) + 1 + ft_strlen(value) + 1;
	new_env = build_new_env(name, value, total_len);
	if (is_env)
		list = &envp->mt_env;
	else
		list = &envp->mt_var;
	env_str = ft_getenv(name, *list);
	if (env_str)
	{
		replace_node(list, name, new_env);
		free(env_str);
	}
	else if (!is_env)
	{
		ft_mtpush_data_right(list, new_env, new_env, STRING);
		envp->num_var++;
	}
	else
		return (free(new_env), ft_setenv(name, value, envp, 0));
	return (0);
}
