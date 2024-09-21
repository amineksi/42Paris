/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:57:30 by amine             #+#    #+#             */
/*   Updated: 2024/09/21 20:41:31 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(char c);
int		ft_toupper(int c);
int		ft_strncmp(const char *first, const char *second, size_t length);

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

void	ft_bzero(void	*s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t count);
char	*ft_strdup(const char *s);
char	*ft_utoa(unsigned int n);
void	ft_putnbr_base(int nbr, char *base);

int		has_format_specifiers(const char *str);
void	ft_putstr(const char *str);

int		ft_prints(char *str);
int		ft_printc(int value);
int		ft_printi(int value);
int		ft_printu(unsigned int value);
int		ft_printx(unsigned int value);
int		ft_print_upperx(unsigned int value);
int		ft_printp(void *addr);

int		ft_printf(const char *str, ...);
#endif