/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:10:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/10 18:08:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_UTILS_H
# define EXE_UTILS_H

# include "exe.h"

// arra2d_utils.c
int		free_array2d(char **array);
size_t	array2d_len(char **array);
void	print_array2d(char **array);
char	**mtconvert_array2d(t_mt *list);

// cmd_args_utils.c
int		free_cmd_args2d(t_cmd_args *args);
void	print_cmd_args2d(t_cmd_args args);

// ft_perfect_match.c
int		ft_pmatch_env(const char *s1, const char *s2, size_t n);
int		ft_pmatch_str(const char *s1, const char *s2, size_t n);

// prompt_utils.c
int		pwd_is_home(t_mt *mt_env);
char	*generate_prompt(t_mt *mt_env);

// tmlst_utils.c.c
void	print_lst_data(t_mt *array);
void	ft_mtdel_one(t_mt **first, t_mt *node);
t_mt	*ft_mtpop_one(t_mt **first, char *find);
size_t	ft_mtcount_node(t_mt *lst);
size_t	ft_mtcount_node_wildcard(t_mt *lst);

//secure_open_file.c
int		secure_open(char *file_name, int in_out);

//in_out.c
void	close_stdin_stdout(t_env *env);
void	restore_stdin(t_env *env);
void	restore_stdout(t_env *env);
void	restore_stdin_stdout(t_env *env);

#endif
