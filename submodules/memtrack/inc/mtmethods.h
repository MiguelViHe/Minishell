/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtmethods.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:16:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/20 13:10:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTMETHODS_H
# define MTMETHODS_H

# include "libft.h"
# include "mtstructs.h"

typedef struct s_mt
{
	char		*key;
	void		*data;
	struct s_mt	*aux;
	void		*ptr_aux;
	t_values	values;
	t_mt		*vect[MAX_DIRECTIONS];
	t_cords		cords;
	void		(*free_data)(void **);
}				t_mt;

// ==================== Memory Management ====================

void			ft_mtdelete(t_mt **mt);
void			ft_mtclear(t_mt **lst);
void			ft_mtdel_list(void **data);

// ==================== Count Functions ====================
int				ft_mtcount_data_type(t_mt *node, t_data_type type);
int				ft_mtcount_node_type(t_mt *node, t_node_type type);
int				ft_mtcount_state(t_mt *node, int state);
size_t			ft_mtcount_node(t_mt *lst);
int				ft_mtsize(t_mt *lst);

// ==================== Iteration and Set Functions ====================
void			ft_mtiter(t_mt *lst, void *param, void (*func)(t_mt *, void *));
void			ft_mtprint(t_mt *lst, int b, char *c);
void			ft_mtset_to_free(t_mt *mt, int to_free);
void			ft_mtset_free_func(t_mt *node, void (*free_func)(void **));

// ==================== Movement Functions ====================
void			ft_mtmigrate_right(t_mt **src, t_mt **dest);
void			ft_mtmigrate(t_mt **src, t_mt **dest);
void			ft_mtpush(t_mt **dst, t_mt **src, t_direction direction);
void			ft_mtpush_last(t_mt **dest, t_mt **src, t_direction direction);
void			ft_mtrotate(t_mt **lst, t_direction direction);
void			ft_mtreverse_rotate(t_mt **lst, t_direction direction);
void			ft_mtswap(t_mt **lst, t_direction direction);

// ==================== Deletion Functions ====================

void			ft_mtpoplast(t_mt **lst, t_direction direction);
void			ft_mtpop(t_mt **lst);
void			ft_mtremove(t_mt **mt, t_mt *node_to_remove);

// ==================== Insertion Functions ====================
void			ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos);
void			ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node);
void			ft_mtreplace_all(t_mt **list, t_mt **replace);
void			ft_mtunset_ptr_aux(t_mt *node, void *field);

// ==================== Add Functions ====================

void			ft_mtaddfirst(t_mt **lst, t_mt *new, t_direction direction);
void			ft_mtaddlast(t_mt **lst, t_mt *new, t_direction direction);
void			ft_mtaddlast_down(t_mt **lst, t_mt *new);
void			ft_mtaddlast_up(t_mt **lst, t_mt *new);
void			ft_mtaddlast_right(t_mt **lst, t_mt *new);
void			ft_mtaddlast_left(t_mt **lst, t_mt *new);
int				ft_mtaddlast_child(t_mt *parent, t_mt *child);
void			ft_mtaddlast_aux(t_mt *node, t_mt *aux);
void			ft_mtaddlast_back(t_mt **lst, t_mt *new);
void			ft_mtaddlast_front(t_mt **lst, t_mt *new);

// ==================== Check Functions ====================
int				ft_mtexists_mt(t_mt *root, const char *key);
int				ft_mtexists_cords(t_mt *node, t_cords cords);
int				ft_mtis_connected(t_mt **first, t_mt *node);
int				ft_mtcheck_state(t_mt *mt, int state);
int				ft_mtcheck_priority(t_mt *mt, int priority);
int				ft_mtcheck_key(t_mt *mt, char *key);

// ==================== Key Management ====================
char			*ft_mtnew_original_key(char *key, t_mt *node);

// ==================== Filter Functions ====================
void			ft_mtfilter(t_mt *lst, void *param, int (*predicate)(t_mt *,
						void *), t_mt **result);

// ==================== Fold Functions ====================
int				ft_mtfold(t_mt *lst, void *param, int (*func)(t_mt *, void *));

// ==================== Collection Functions ====================
t_mt			*ft_mtcollect_node_type(t_mt *mt, t_node_type type);
t_mt			*ft_mtcollect_data_type(t_mt *mt, t_data_type type);
t_mt			*ft_mtcollect_state(t_mt *mt, int state);
t_mt			*ft_mtsub(t_mt **mt, t_mt *node_to_sub);

// ==================== Search Functions ====================

t_mt			*ft_mtsearch(t_mt *lst, void *p, t_predicate predicate);
t_mt			*ft_mtsearch_key(t_mt *root, const char *key);
t_mt			*ft_mtsearch_cords(t_mt *node, t_cords cords);

// ==================== Navigation Functions ====================

t_mt			*ft_mtlast(t_mt *lst, t_direction direction);
t_mt			*ft_mtroot(t_mt *lst);

// ==================== Utility Functions ====================

t_mt			*ft_mtzip(t_mt **lst);
t_mt			*ft_mtunzip(void **data, size_t size);
t_mt			*ft_mtnew(const char *key, void *data, t_data_type type);
t_mt			*ft_mtdup(t_mt *src);
t_mt			*ft_mtnew_chaos(void *data);
void			ft_mtpush_data(t_mt **lst, const char *key, void *data,
					t_data_type type);
void			ft_mtpush_data_right(t_mt **lst, const char *key, void *data,
					t_data_type type);
void			ft_mtremove_data(t_mt *lst, char *key);
void			ft_mtreplace_all_data(t_mt **lst, void *new_data,
					t_data_type type);

// ==================== Manipulation Functions ====================

t_mt			*ft_mtdisconnect_safe(t_mt **ref, t_mt *node);
void			ft_mtconnect_safe(t_mt **lst, t_mt *new, t_direction direction);
int				ft_mtexchange_dir(t_mt **lst, t_mt *cur, t_direction direction);
void			ft_mtexchange_nodes(t_mt **token, t_mt *first, t_mt *last);

#endif // MTMETHODS_H
