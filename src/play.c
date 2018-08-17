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
	arr[vert->number] = 1;
	//printf("I am visiting: %s\n", vert->name);
	while(i < ft_lstsize(&vert->neighbours))
	{
		v = ft_graph_getvertex_byid(lem->g, *(int *)ft_lstat(vert->neighbours, i)->content);
		if (arr[v->number] == -1)
			DFS(lem, v, arr);
		if(v->number != lem->end_room)
			make_move(lem, vert, v);
		i++;
	}
	printf("I am visiting: %s\n", vert->name);
	//make_move(lem, vert, v);
	//if(v->number != lem->end_room)
		//make_move(lem, vert, v);
}

void	run_turn(t_lem *lem, t_vertex *begin_room)
{
	int		visited[lem->g->num_vertices];
	int		i;

	i = 0;
	while (i < lem->g->num_vertices)
		visited[i++] = -1;
	DFS(lem, begin_room, visited);
	room_status(lem);
}

void	game(t_lem *lem, t_vertex* begin_room, t_vertex *end_room, int *visited);

int		solve(t_lem *lem)
{
	t_vertex	*begin_room;
	t_vertex	*end_room;
	int			*visited;
	int			i;
	t_list		*tmp;

	if (lem != NULL && lem->g != NULL && lem->g->vertices != NULL)
	{
		i = 0;
		if((begin_room = ft_graph_getvertex_byid(lem->g, lem->begin_room)) == NULL)
			return (FALSE);
		if((end_room = ft_graph_getvertex_byid(lem->g, lem->end_room)) == NULL)
			return (FALSE);
		if ((visited = (int *)ft_memalloc(sizeof(int) * lem->g->num_vertices)) == NULL)
			return (FALSE);
		while (i < lem->g->num_vertices)
			visited[i++] = -1;
		visited[lem->end_room] = 1;
		while (end_room->num_ants != lem->total_ants && is_in(visited, lem->g->num_vertices, -1) == TRUE)
		{
			if (begin_room->num_ants == 0)
			{
				visited[begin_room->number] = 1;
				i = 0;
				tmp = begin_room->neighbours;
				while (tmp != NULL)
				{
					if
					tmp = tmp->next;
				}

				//while ((size_t) i < ft_lstsize(begin_room->neighbours))
				while (t)
			}

			run_turn(lem, begin_room);
		}
	}
	return (FALSE);
}