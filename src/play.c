#include <lem_in.h>

int		is_in(int *arr, int len, int search)
{
	int i = 0;
	while (i < len)
		if (arr[i++] == search)
			return (TRUE);
	return (FALSE);
}

void	run_turn(t_lem *lem)
{
	
}

int		solve(t_lem *lem)
{
	t_vertex	*begin_room;
	t_vertex	*end_room;

	if (lem != NULL && lem->g != NULL && lem->g->vertices != NULL)
	{
		if((begin_room = ft_graph_getvertex_byid(lem.g, lem.begin_room)) == NULL)
			return (FALSE);
		if((end_room = ft_graph_getvertex_byid(lem.g, lem.end_room)) == NULL)
			return (FALSE);
		run_turn(&lem);
	}
	return (FALSE);
}