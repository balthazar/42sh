/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:08:00 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/27 11:08:35 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

/*
** structs
*/
typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*right;
	struct s_btree	*left;
	size_t			content_size;
	void			*content;
}					t_btree;

#endif
