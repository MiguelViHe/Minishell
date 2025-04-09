/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/10 16:43:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include "structs.h"
# include <stdio.h>
# include <stdlib.h>

// Ahora puedes usar estos tipos en las siguientes estructuras
typedef struct s_mt			t_mt;
typedef struct s_hash_table	t_hash_table;
typedef void				(*t_free_funtion)(void **);
typedef int					(*t_predicate)(t_mt *, void *);

typedef struct s_cords
{
	int						x;
	int						y;
	int						z;
}							t_cords;

typedef enum e_mtstate
{
	EMPTY,
	FILLED,
	DELETED
}							t_mtstate;

typedef enum e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	FRONT,
	BACK,
	MAX_DIRECTIONS
}							t_direction;

typedef enum e_data_type
{
	NONE,
	PTR,
	STRING,
	LIST,
	HASH_TABLE
}							t_data_type;

typedef enum e_node_type
{
	ROOT,
	LEAF,
	BRANCH
}							t_node_type;

typedef struct s_values
{
	int						data_type;
	int						node_type;
	size_t					size;
	int						count;
	int						to_free;
	int						state;
	int						priority;
	t_bool					boolean;
	t_bool					swap_checked;
}							t_values;

#endif
