/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:39:56 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/22 16:40:26 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define MIN_INT (-MI - 1)
# define MI 2147483647
# include "./libft.h"

int		get_next_line(const int fd, char **line);
void	swapnfree(char **var, char *new_val);
#endif
