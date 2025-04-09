/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:51:38 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/27 16:33:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

int	free_cmd_args2d(t_cmd_args *args)
{
	int	i;

	if (args && args->names && *(args->names))
	{
		i = 0;
		while (args->names[i])
		{
			free(args->names[i]);
			i++;
		}
		free(args->names);
		free(args->need_space);
	}
	return (0);
}

void	print_cmd_args2d(t_cmd_args args)
{
	size_t	i;

	if (!(args.names))
	{
		ft_printf("array in empty\n");
		return ;
	}
	i = 0;
	while (args.names[i])
	{
		ft_printf("%s flag = %d\n", args.names[i], args.need_space[i]);
		i++;
	}
}
