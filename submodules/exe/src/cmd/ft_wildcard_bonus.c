/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:28:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/28 12:21:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "cmd.h"

static void	move_both_forward(const char **pattern, const char **str)
{
	(*pattern)++;
	(*str)++;
}

// check if the pattern matches the string.
// Returns 1 if it matches, 0 if it doesn't.
int	ft_fnmatch(const char *pattern, const char *str)
{
	const char	*star;
	const char	*backup;

	star = NULL;
	backup = NULL;
	while (*str)
	{
		if (*pattern == '*')
		{
			star = pattern++;
			backup = str;
		}
		else if (*pattern == *str)
			move_both_forward(&pattern, &str);
		else if (star)
		{
			pattern = star + 1;
			str = ++backup;
		}
		else
			return (0);
	}
	while (*pattern == '*')
		pattern++;
	return (*pattern == '\0');
}

// Count and return the number of files that match the pattern excluding
// hidden files. (those that start with '.')
int	count_wildcard(char *pattern)
{
	struct dirent	*entry;
	DIR				*dir;
	int				count;

	dir = opendir(".");
	if (!dir)
		return (perror("opendir"), 0);
	count = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			if (ft_fnmatch(pattern, entry->d_name))
				count++;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (count);
}

//Charge in args the files that match the pattern excluding hidden files
// (those that start with '.')
void	expand_wildcard(char *pattern, t_cmd_args *args, size_t *i)
{
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir(".");
	if (!dir)
	{
		perror("opendir");
		return ;
	}
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			if (ft_fnmatch(pattern, entry->d_name))
			{
				args->names[(*i)] = strdup(entry->d_name);
				args->need_space[(*i)] = 1;
				(*i)++;
			}
		}
		entry = readdir(dir);
	}
	closedir(dir);
}
