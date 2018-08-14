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
	char	*str;
	int		read_ret;
	t_lem	lem;

	lem.g = ft_graph_new();
	if((read_ret = get_next_line(0, &str)) < 0)
		return (-1);
	lem.total_ants = ft_atoi(str);
	while((read_ret = get_next_line(0, &str)) > 0)
	{
		printf("%d: %s\n", read_ret, str);
		if (ft_strchr(str, '-') != NULL)
			parse_link(&lem, str);
		else if(ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0)
			parse_command(&lem, str);
		else if (str[0] != '#')
			parse_room(&lem, str);
		free(str);
	}
	printf("The total amount of ants is: %d\n", lem.total_ants);
	ft_graph_genmatrices(lem.g);
	ft_graph_print(lem.g);
	return (0);
}
