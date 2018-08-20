/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:00:15 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/10 09:00:18 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <stdio.h>

int	main(void)
{
	char		*str;
	int			read_ret;
	t_lem		lem;
	//t_vertex	*begin_room;
	//t_vertex	*end_room;

	lem.g = ft_graph_new();
	if((read_ret = get_next_line(0, &str)) < 0)
		return (-1);
	lem.total_ants = ft_atoi(str);
	if(lem.total_ants <= 0)
	{
		ft_putstr_clr(LIGHT_RED, "ERROR: zero or negative amounts of ants.\n");
		return (FALSE);
	}
	while((read_ret = get_next_line(0, &str)) > 0)
	{
		ft_putendl(str);
		if (ft_strchr(str, '-') != NULL)
		{
			if (parse_link(&lem, str) == FALSE)
				return (FALSE);
		}
		else if(ft_strncmp(str, "##start", 7) == 0 || ft_strncmp(str, "##end", 5) == 0)
		{
			if (parse_command(&lem, str) == FALSE)
				return (FALSE);
		}
		else if (str[0] != '#')
		{
			if(parse_room(&lem, str) == FALSE)
				return (FALSE);
		}
		free(str);
	}
	//printf("The total amount of ants is: %d\n", lem.total_ants);
	ft_graph_genmatrices(lem.g);
	//ft_graph_print(lem.g);
	//room_status(&lem);
	//begin_room = ft_graph_getvertex_byid(lem.g, lem.begin_room);
	//end_room = ft_graph_getvertex_byid(lem.g, lem.end_room);
	//printf("The start room is: %d and has name %s\n",lem.begin_room,
	//begin_room->name);
	//printf("The end room is: %d and has name: %s\n",lem.end_room, 
	//end_room->name);
	//make_move(&lem, begin_room, ft_graph_getvertex_byid(lem.g, *(int *)begin_room->neighbours->content));
	//room_status(&lem);
	solve(&lem);
	return (0);
}
