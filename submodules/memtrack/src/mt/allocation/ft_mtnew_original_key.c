/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew_original_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:24:52 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 14:07:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*ft_mtnew_original_key(char *key, t_mt *node)
{
	int		i;
	char	*new_key;
	char	*key_suffix;
	char	*tmp;

	if (!key || !node)
		return (NULL);
	new_key = ft_strdup(key);
	i = 1;
	while (ft_mtexists_mt(node, new_key))
	{
		key_suffix = ft_itoa(i++);
		tmp = new_key;
		if (ft_strrchr(tmp, '-'))
		{
			if (ft_isdigit(*(ft_strrchr(tmp, '-') + 1)))
				*(ft_strrchr(tmp, '-')) = 0;
		}
		tmp = ft_straddc(tmp, '-');
		new_key = ft_mtnew_key(tmp, key_suffix);
		(free(tmp), free(key_suffix));
	}
	if (!ft_mtexists_mt(node, new_key))
		return (free(key), new_key);
	return (NULL);
}
