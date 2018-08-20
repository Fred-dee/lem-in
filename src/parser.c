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
		lem->start_flag = 1;
		v->num_ants = lem->total_ants;
		lem->begin_room = v->number;
	}
	else
	{
		lem->end_flag = 1;
		lem->end_room = v->number;
	}
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

void	dfs_path(t_lem *lem, t_vertex *vert, int *arr, char **ret)
{
	size_t		i;
	t_vertex	*v;

	i = 0;
	arr[vert->number] = 0;
	swapnfree(ret, ft_strjoin(*ret, vert->name));
	swapnfree(ret, ft_strjoin(*ret, " , "));
	while(i < ft_lstsize(&vert->neighbours))
	{
		v = ft_graph_getvertex_byid(lem->g, *(int *)ft_lstat(vert->neighbours, i)->content);
		if (arr[v->number] == -1)
		{
			dfs_path(lem, v, arr, ret);
			
			arr[vert->number] = 1;
		}
		i++;
	}
}

int	has_validpath(t_lem *lem)
{
	char		*str;
	t_vertex	*start;
	int			arr[lem->g->num_vertices];
	int			i;

	str = ft_strnew(1);
	start = ft_graph_getvertex_byid(lem->g, lem->begin_room);
	i = 0;
	while (i < lem->g->num_vertices)
		arr[i++] = -1;
	if (start != NULL)
	{
		dfs_path(lem, start, arr, &str);
		printf("The path is: %s\n", str);
		if (ft_strstr(str, start->name) != NULL && 
			ft_strstr(str, ft_graph_getvertex_byid(lem->g, lem->end_room)->name) != NULL)
		{
			free(str);
			return (TRUE);
		}
	}
	free(str);
	ft_putstr_clr(LIGHT_RED, "ERROR: Does not contain a valid path \n");
	return (FALSE);
}