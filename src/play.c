#include <lem_in.h>
#include <stdio.h>

int		is_in(int *arr, int len, int search)
{
	int i = 0;
	while (i < len)
		if (arr[i++] == search)
			return (TRUE);
	return (FALSE);
}

void	DFS(t_lem *lem, t_vertex *vert, int *arr)
{
	size_t		i;
	t_vertex	*v;

	i = 0;
	arr[vert->number] = 0;
	if (vert->number !=  lem->end_room)
	{
		while(i < ft_lstsize(&vert->neighbours))
		{
			v = ft_graph_getvertex_byid(lem->g, *(int *)ft_lstat(vert->neighbours, i)->content);
			if (arr[v->number] == -1)
			{
				DFS(lem, v, arr);
				if(vert->number != lem->end_room)
					make_move(lem, vert, v, arr);
				arr[vert->number] = 1;
			}
			i++;
		}
	}
}

void	run_turn(t_lem *lem, t_vertex *begin_room)
{
	int		visited[lem->g->num_vertices];
	int		i;

	i = 0;
	while (i < lem->g->num_vertices)
		visited[i++] = -1;
	DFS(lem, begin_room, visited);
	if (lem->debug_flag == 1)
		room_status(lem);
}

int		solve(t_lem *lem)
{
	t_vertex	*begin_room;
	t_vertex	*end_room;
	int			*visited;

	if (lem != NULL && lem->g != NULL && lem->g->vertices != NULL)
	{
		if((begin_room = ft_graph_getvertex_byid(lem->g, lem->begin_room)) == NULL)
			return (FALSE);
		if((end_room = ft_graph_getvertex_byid(lem->g, lem->end_room)) == NULL)
			return (FALSE);
		if ((visited = (int *)ft_memalloc(sizeof(int) * lem->g->num_vertices)) == NULL)
			return (FALSE);
		while (end_room->num_ants != lem->total_ants)
		{
			run_turn(lem, begin_room);
			ft_putchar('\n');
		}
		free(visited);
	}
	return (FALSE);
}