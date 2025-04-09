/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:47:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/28 11:46:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

int	check_opt(char *opt)
{
	char	*clean_opt;

	clean_opt = ft_strtrim(opt, "'\"");
	if (ft_pmatch_str(clean_opt, "-n", 2) == 0)
		return (free(clean_opt), 1);
	return (free(clean_opt), 0);
}

// NO USADA DE MOMENTO. En la ultima vuelta del segundo while, no concatena el 
// espacio porque he reservado el espacio justo para cada cadena + su espacio.
// Pero al iniciar len en 0 el espacio de la ultima es usado para el \0, 
// evitando asi que la ultima tenga un espacio(truco).
char	*generate_echo_arg(char **args)
{
	char	*arg;
	size_t	len;
	int		i;

	len = 0;
	i = 1;
	while (args[i])
		len += ft_strlen(args[i++]) + 1;
	arg = ft_calloc(len, sizeof(char));
	i = 1;
	while (args[i])
	{
		ft_strlcat(arg, args[i++], len);
		ft_strlcat(arg, " ", len);
	}
	return (arg);
}

int	echo_builtin(t_command *cmd, t_env *envp)
{
	int		i;
	int		opt;
	int		num_args;

	(void)envp;
	num_args = array2d_len(cmd->args.names);
	if (num_args > 1)
	{
		i = 1;
		opt = check_opt(cmd->args.names[i]);
		i += opt;
		while (cmd->args.names[i])
		{
			ft_printf("%s", cmd->args.names[i]);
			if (cmd->args.need_space[i])
				ft_printf(" ");
			i++;
		}
		if (!opt)
			ft_printf("\n");
	}
	return (envp->last_status = 0, 0);
}
