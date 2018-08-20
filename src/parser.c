#include <lem_in.h>
#include <stdio.h>

int	parse_link(t_lem *lem, char *str)
{
	t_vertex	*a;
	t_vertex	*b;
	char		*tmp;

	if(lem != NULL && lem->g != NULL)
	{
		if(ft_isprint(str[ft_strindexof(str, '\0') - 1]) == 0)
			str[ft_strindexof(str, '\0') - 1] = '\0';
		tmp = ft_strsub(str, 0, ft_strindexof(str, '-'));
		a = ft_graph_getvertex_byname(lem->g, tmp);
		free(tmp);
		tmp = ft_strsub(str, ft_strindexof(str, '-') + 1, ft_strlen(str));
		b = ft_graph_getvertex_byname(lem->g, tmp);
		if (a != NULL && b != NULL)
			ft_graph_addedge(lem->g, a->number, b->number);
		else
		{
			ft_putstr_clr(LIGHT_RED, "ERROR parsing link: ");
			ft_putendl(str);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	parse_command(t_lem *lem, char *str)
{
	char		**split;
	char		*tmp;
	t_vertex	*v;

	if (get_next_line(0, &tmp) > 0)
	{
		ft_putendl(tmp);
		if (parse_room(lem, tmp) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	split = ft_strsplit(tmp, ' ');
	v = ft_graph_getvertex_byname(lem->g, split[0]);
	if(ft_strncmp(str, "##start", 7) == 0)
	{
		v->num_ants = lem->total_ants;
		lem->begin_room = v->number;
	}
	else
		lem->end_room = v->number;
	//free split
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
		if (i != 3 || split[0][0] == 'L')
		{
			ft_putstr_clr(LIGHT_RED, "ERROR parsing room: ");
			ft_putendl(str);
			return (FALSE);
		}
		ft_graph_addvertex(lem->g, ft_graph_vertexnew(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0));
		//free the split
	}
	return (TRUE);
}