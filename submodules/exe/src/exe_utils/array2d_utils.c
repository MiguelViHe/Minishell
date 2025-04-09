/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:19:55 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/27 15:51:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

int	free_array2d(char **array)
{
	int	i;

	if (array && *array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (1);
	}
	return (0);
}

size_t	array2d_len(char **array)
{
	size_t	len;

	len = 0;
	while (array && array[len])
		len++;
	return (len);
}

void	print_array2d(char **array)
{
	size_t	i;

	if (!array || !(*array))
	{
		ft_printf("array in empty\n");
		return ;
	}
	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

char	**mtconvert_array2d(t_mt *list)
{
	char	**array;
	size_t	list_size;
	size_t	i;

	if (!list)
		return (NULL);
	i = 0;
	list_size = ft_mtcount_node(list);
	array = ft_calloc(list_size + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (list)
	{
		array[i++] = ft_strdup(list->data);
		list = list->vect[RIGHT];
	}
	return (array);
}
