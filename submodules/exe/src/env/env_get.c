/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:38:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 11:36:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

// Return the length of the value of env var named "name".
// If flag ==1 and var is "HOME" return 1. (~ in prompt).
// else return the normal length.
size_t	get_len_env(char *name, t_mt *mt_env, int flag)
{
	char	*value;
	char	*home;
	size_t	len;

	home = ft_getenv_value("HOME", mt_env);
	value = ft_getenv_value(name, mt_env);
	if (ft_pmatch_str(value, home, ft_strlen(home)) == 0 && flag)
		len = 1;
	else
		len = ft_strlen(value);
	return (free(home), free(value), len);
}

// return a ptr to the value of the name env. (Not a copy)
char	*ft_getenv_ptr_value(const char *name, t_mt *envp)
{
	t_mt	*aux;

	aux = ft_mtsearch_key(envp, name);
	if (aux)
		return ((char *)aux->data + ft_strlen(name) + 1);
	return (NULL);
}

// return a copy of the value of the name env.
char	*ft_getenv_value(const char *name, t_mt *envp)
{
	t_mt	*aux;

	aux = ft_mtsearch_key(envp, name);
	if (aux)
		return (ft_strdup((char *)aux->data + ft_strlen(name) + 1));
	return (NULL);
}

// return a copy of the whole env.
char	*ft_getenv(const char *name, t_mt *envp)
{
	t_mt	*aux;

	aux = ft_mtsearch_key(envp, name);
	if (aux)
		return (ft_strdup(aux->data));
	return (NULL);
}
