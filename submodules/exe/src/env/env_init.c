/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:51:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/27 11:24:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

// Finds the line that starts with "PATH=" in env, and, if exists
// creates and array splitting the line with ":" and returns it.
char	**split_path_env(char *env[])
{
	int		i;
	char	*path;
	char	**path_array;

	i = 0;
	path = NULL;
	path_array = NULL;
	if (!env)
		return (NULL);
	while (!path && env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	if (path)
	{
		path += 5;
		path_array = ft_split(path, ':');
		i = 0;
	}
	return (path_array);
}

void	initialize_environ(t_env *environ, int counter)
{
	environ->num_env = counter;
	environ->mt_env = NULL;
	environ->num_var = 0;
	environ->mt_var = NULL;
	environ->input = NULL;
	environ->prompt = NULL;
	environ->last_status = 0;
	environ->error_infile_name = NULL;
	environ->redirect.is_red_in = 0;
	environ->redirect.is_red_out = 0;
	environ->redirect.original_stdin = dup(STDIN_FILENO);
	environ->redirect.original_stdout = dup(STDOUT_FILENO);
	environ->prev_dir = NULL;
}

char	*initialize_path_history(t_mt *env)
{
	char	*path;

	path = ft_strjoin(ft_getenv_ptr_value("HOME", env), "/.minishell_history");
	if (!path)
		return (NULL);
	return (path);
}

// Genera una copia del entorno en una variable de tipo t_env
t_env	*copy_envp(char **envp)
{
	int		counter;
	char	*node_content;
	t_env	*environ;

	counter = 0;
	environ = ft_calloc(1, sizeof(t_env));
	if (!(environ))
		return (NULL);
	while (envp[counter])
		counter++;
	initialize_environ(environ, counter);
	counter = 0;
	while (counter < environ->num_env)
	{
		node_content = ft_strdup(envp[counter]);
		if (!node_content)
			return (NULL);
		ft_mtpush_data_right(&environ->mt_env, node_content, node_content,
			STRING);
		counter++;
	}
	environ->path = split_path_env(envp);
	environ->path_history = initialize_path_history(environ->mt_env);
	init_builtins(environ->builtins);
	return (environ);
}
