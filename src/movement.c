#include <lem_in.h>

void	room_status(t_lem *lem)
{
	t_list		*tmp;
	t_vertex	*v;
	
	if (lem != NULL && lem->g->vertices != NULL)
	{
		tmp = lem->g->vertices;
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