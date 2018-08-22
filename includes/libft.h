/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:20:26 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/22 16:41:53 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(Value) (Value * ((Value > 0) - (Value < 0)))

# include "colours.h"
# include <stdlib.h>
# include <string.h>
# define TRUE 1
# define FALSE 0

void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void					*ft_memmove(void *s1, const void *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_clr(char const *clr, char const *str);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_clr(char const *clr, int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_clr(char const *clr, char const *str);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strcat(char *s1, const char *s2);
void					ft_putstr(char const *s);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
char					*ft_strcpy(char	*s1, const char *s2);
int						ft_strindexof(const char *s, const char c);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *s1, const char *s2, size_t len);
char					*ft_strnew(size_t size);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strsub(char const *s,
						unsigned int start, size_t len);
char					*ft_strtrim(char const *s);
int						ft_strequ(char const *s1, char const *s2);
void					ft_strdel(char **as);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isempty(char *s);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_ispunct(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_atoi(const char *str);
long					ft_atol(const char *str);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_itoa(int n);
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstaddback(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
t_list					*ft_lstdupelem(t_list *elem);
t_list					*ft_lstdup(t_list **alst);
t_list					*ft_lstgettail(t_list *root);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstquicksort(t_list **headref);
size_t					ft_lstsize(t_list **alst);
t_list					*ft_lstat(t_list *head, size_t index);
#endif
