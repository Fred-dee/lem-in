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

int	main(int ac, char *av[])
{
	char		*str;
	int			read_ret;
	t_lem		lem;

	lem.g = ft_graph_new();
	if((read_ret = get_next_line(0, &str)) < 0)
		return (-1);
	lem.total_ants = ft_atoi(str);
	free(str);
	lem.debug_flag = 0;
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "-v") == 0)
			lem.debug_flag = 1;
	}
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
	if (lem.start_flag != 1 || lem.end_flag != 1)
	{
		ft_putstr_clr(LIGHT_RED, "ERROR: Either ##start or ##end not set\n");
		return (FALSE);
	}
	if (has_validpath(&lem) == FALSE)
		return(FALSE);
	ft_putchar('\n');
	solve(&lem);
	ft_graph_del(&lem.g);
	while (1)
	{}
	return (0);
}
