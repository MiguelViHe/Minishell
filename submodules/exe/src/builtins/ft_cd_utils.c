/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:22:26 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/27 17:03:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

char	*create_complete_path(t_mt *dir_history)
{
	t_mt	*aux;
	char	*path;

	if (!dir_history)
		return (NULL);
	aux = dir_history;
	path = ft_strdup("/");
	while (aux)
	{
		path = ft_strjoin_free(&path, &(aux->key), 0);
		if (aux->vect[RIGHT])
			path = ft_straddc(path, '/');
		aux = aux->vect[RIGHT];
	}
	return (path);
}

t_mt	*create_prev_dir(char *dir)
{
	t_mt	*new;
	t_mt	*list;
	char	**dir_split;
	char	*elem_dir;
	int		i;

	list = NULL;
	i = 0;
	dir_split = ft_split(dir, '/');
	if (!dir_split)
		return (NULL);
	while (dir_split[i])
	{
		elem_dir = ft_strdup(dir_split[i++]);
		new = ft_mtnew(elem_dir, elem_dir, STRING);
		if (!new)
			break ;
		ft_mtaddlast(&list, new, RIGHT);
	}
	return (free_array2d(dir_split), list);
}

int	move_valid_place(char **new_path, t_env *env, t_command *cmd)
{
	if (!new_path)
		return (1);
	ft_mtpoplast(&(env->prev_dir), RIGHT);
	free(*new_path);
	*new_path = create_complete_path(env->prev_dir);
	if (!*new_path)
		return (1);
	free(cmd->args.names[1]);
	cmd->args.names[1] = *new_path;
	chdir(*new_path);
	return (cd_builtin(cmd, env));
}

void	set_prev_dir(char *dir, t_env *envp)
{
	if (envp->prev_dir)
		ft_mtclear(&envp->prev_dir);
	if (!dir)
		return ;
	envp->prev_dir = create_prev_dir(dir);
	free(dir);
}
