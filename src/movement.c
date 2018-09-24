/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:25:23 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/22 16:25:27 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	room_status(t_lem *lem)
{
	t_list		*tmp;
	t_vertex	*v;

	if (lem != NULL && lem->g->vertices != NULL)
	{
		tmp = lem->g->vertices;
		ft_putchar('\n');
		while (tmp != NULL)
		{
			v = (t_vertex *)tmp->content;
			ft_putstr_clr(LIGHT_CYAN, "Room: ");
			ft_putstr_clr(LIGHT_GREEN, v->name);
			ft_putendl_clr(LIGHT_CYAN, " has");
			ft_putnbr_clr(LIGHT_RED, v->num_ants);
			ft_putendl(" ants");
			tmp = tmp->next;
		}
	}
}

void	free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
		free(arr[i++]);
	free(arr);
	arr = NULL;
}

int		make_move(t_lem *lem, t_vertex *from, t_vertex *to, int *visited)
{
	if ((to->num_ants == 0 || to->number == lem->end_room)
		&& (visited[to->number] == 0 || visited[to->number] == 1 || visited[to->number] == -1))
	{
		if (from->num_ants > 0)
		{
			from->num_ants--;
			to->ant_name = from->ant_name;
			if (from->number == lem->begin_room)
				from->ant_name++;
			else
				from->ant_name = -1;
			to->num_ants++;
			ft_putchar('L');
			ft_putnbr(to->ant_name);
			ft_putchar('-');
			ft_putstr(to->name);
			ft_putchar(' ');
			return (TRUE);
		}
	}
	return (FALSE);
}
