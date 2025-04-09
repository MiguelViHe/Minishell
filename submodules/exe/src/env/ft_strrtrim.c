/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:26:05 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 11:45:22 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ptrrtrim(char const *s1, char const *set)
{
	char const	*end;

	if (!s1 || !set)
		return (NULL);
	end = s1 + ft_strlen(s1);
	while (end > s1 && ft_strchr(set, *(end - 1)))
		end--;
	return ((char *)end);
}

/*Allocate (with malloc) and returns a copy of s1, without the characters
specified in set at the beginning of s1.*/
char	*ft_strrtrim(char const *s1, char const *set)
{
	char	*ptrrtrim;
	char	*clean;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	ptrrtrim = ft_ptrrtrim(s1, set);
	if (!ptrrtrim)
		return (NULL);
	len = ptrrtrim - s1;
	clean = malloc((len + 1) * sizeof(char));
	if (!clean)
		return (NULL);
	ft_strlcpy(clean, s1, len + 1);
	return (clean);
}
