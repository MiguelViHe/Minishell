/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_key_suffix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:48:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:42:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtadd_key_suffix(char *suffix, t_mt *node)
{
	char	*new_key;

	if (!suffix || !node)
		return ;
	new_key = ft_strjoin(node->key, suffix);
	free(node->key);
	node->key = new_key;
}
