/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:26:05 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 11:44:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ptrltrim(char const *s1, char const *set)
{
	char const	*first;

	if (!s1 || !set)
		return (NULL);
	first = s1;
	while (*first && ft_strchr(set, *(first)))
		first++;
	return ((char *)first);
}

/*Allocate (with malloc) and returns a copy of s1, without the characters
specified in set at the end of s1.*/
char	*ft_strltrim(char const *s1, char const *set)
{
	char	*ptrltrim;
	char	*clean;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	ptrltrim = ft_ptrltrim(s1, set);
	if (*ptrltrim == '\0')
		return (ft_strdup(""));
	len = ft_strlen(ptrltrim);
	clean = malloc((len + 1) * sizeof(char));
	if (!clean)
		return (NULL);
	ft_strlcpy(clean, ptrltrim, len + 1);
	return (clean);
}
