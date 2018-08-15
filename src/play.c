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

void	DFS(t_graph *g, t_vertex *vert, int *arr)
{
	size_t		i;
	t_vertex	*v;

	i = 0;
	printf("I am visiting: %s\n", vert->name);
	while(i < ft_lstsize(&vert->neighbours))
	{
		v = ft_graph_getvertex_byid(g, *(int *)ft_lstat(vert->neighbours, i)->content);
		if (arr[v->number] == -1)
			DFS(g, v, arr);
		i++;
	}
	arr[vert->number] = 1;
}

void	run_turn(t_lem *lem, t_vertex *begin_room)
{
	int		visited[lem->g->num_vertices];
	int		i;

	i = 0;
	while (i < lem->g->num_vertices)
		visited[i++] = -1;
	DFS(lem->g, begin_room, visited);
}

int		solve(t_lem *lem)
{
	t_vertex	*begin_room;
	t_vertex	*end_room;

	if (lem != NULL && lem->g != NULL && lem->g->vertices != NULL)
	{
		if((begin_room = ft_graph_getvertex_byid(lem->g, lem->begin_room)) == NULL)
			return (FALSE);
		if((end_room = ft_graph_getvertex_byid(lem->g, lem->end_room)) == NULL)
			return (FALSE);
		run_turn(lem, begin_room);
	}
	return (FALSE);
}