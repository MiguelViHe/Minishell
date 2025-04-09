/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:55:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:00:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/* Soluciona el UNSET TERM (buscaba cualquier cosa que empiece por TERM)
	EL
	yo tengo dos funciones ya creadas que buscan perfect_match:
		En cadenas normales (que acaban con '\0')
		Como cadenas de ENV (que tienen el formato PATH=algo)
	De momento he dejado la version que comprueba las dos cosas a la vez.
*/
static int	match_key(t_mt *node, void *key)
{
	return (!ft_strncmp(node->key, key, ft_strlen(key))
		&& (node->key[ft_strlen(key)] == '\0'
			|| node->key[ft_strlen(key)] == '='));
}

t_mt	*ft_mtsearch_key(t_mt *root, const char *key)
{
	t_mt	*result;

	if (!root || !key)
		return (NULL);
	result = ft_mtsearch(root, (void *)key, match_key);
	return (result);
}
