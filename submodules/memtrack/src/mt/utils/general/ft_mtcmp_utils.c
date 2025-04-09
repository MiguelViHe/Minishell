/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcmp_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:43:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:44:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcmp_key(t_mt *node, const char *key, size_t n)
{
	if (!node || !key)
		return (0);
	return (ft_strncmp(node->key, key, n) == 0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	cmp_int(void *a, void *b, size_t n)
{
	(void)n;
	return (*(int *)a - *(int *)b);
}

int	ft_cordscmp(t_cords a, t_cords b)
{
	if (a.x != b.x)
		return (a.x - b.x);
	if (a.y != b.y)
		return (a.y - b.y);
	return (a.z - b.z);
}
