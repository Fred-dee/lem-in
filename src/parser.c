#include <lem_in.h>
#include <stdio.h>

int	parse_link(t_lem *lem, char *str)
{
	t_vertex	*a;
	t_vertex	*b;
	char		*tmp;

	if(lem != NULL && lem->g != NULL)
	{
		tmp = ft_strsub(str, 0, (size_t) ft_strindexof(str, '-'));
		printf("The first name is: %s\n", tmp);
		a = ft_graph_getvertex_byname(lem->g, tmp);
		if (a == NULL)
			printf("its a thats null\n");
		free(tmp);
		tmp = ft_strchr(str, '-');
		tmp++;
		printf("The second name is: %s\n", tmp);
		b = ft_graph_getvertex_byname(lem->g, tmp);
		if (b == NULL)
			printf("its b thats null\n");
		if (a != NULL && b != NULL)
			ft_graph_addedge(lem->g, a->number, b->number);
		else
			printf("either a or b are null\n");
	}
	return (TRUE);
}

int	parse_command(t_lem *lem, char *str)
{
	char		**split;
	t_vertex	*v;

	if (get_next_line(0, &str) > 0)
	{
		if (parse_room(lem, str) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	if(ft_strcmp(str, "##start") == 0)
	{
		split = ft_strsplit(str, ' ');
		v = ft_graph_getvertex_byname(lem->g, split[0]);
		v->num_ants = lem->total_ants;
		//free split
	}
	return (TRUE);
}

int	parse_room(t_lem *lem, char *str)
{
	char	**split;
	int		i;

	if (lem != NULL && lem->g != NULL)
	{
		i = 0;
		split = ft_strsplit(str, ' ');
		while (split[i] != '\0')
			i++;
		if (i != 3)
			return (FALSE);
		ft_graph_addvertex(lem->g, ft_graph_vertexnew(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0));
		//free the split
	}
	return (TRUE);
}