/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:41:49 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/10 08:41:52 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H_
# define LEM_IN_H_
# include "get_next_line.h"
# include "graph.h"

typedef struct	s_lem
{
	t_graph		*g;
	int			total_ants;
	int			begin_room;
	int			end_room;
}				t_lem;

int			parse_link(t_lem *lem, char *str);
int			parse_command(t_lem *lem, char *str);
int			parse_room(t_lem *lem, char *str);
void		room_status(t_lem *lem);
int			make_move(t_lem *lem, t_vertex *from, t_vertex *to, int *visited);
int			solve(t_lem *lem);

#endif
