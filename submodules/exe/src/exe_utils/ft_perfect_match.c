/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perfect_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 11:42:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

// compare two strings and return 0 if both are exactly the same.
int	ft_pmatch_str(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (1);
	if (ft_strncmp(s1, s2, n) != 0)
		return (1);
	if (s1[n] != '\0')
		return (1);
	return (0);
}

// compare two env variable strings and return 0 if both are exactly the same.
int	ft_pmatch_env(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (1);
	if (ft_strncmp(s1, s2, n) != 0)
		return (1);
	if (s1[n] != '=')
		return (1);
	return (0);
}
