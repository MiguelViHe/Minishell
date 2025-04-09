/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_key_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:46:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:42:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtadd_key_prefix(char *prefix, t_mt *node)
{
	char	*new_key;

	if (!prefix || !node)
		return ;
	new_key = ft_strjoin(prefix, node->key);
	free(node->key);
	node->key = new_key;
}
