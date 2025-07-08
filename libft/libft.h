/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:04:32 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/17 20:11:22 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

char				*ft_itoa(int i);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *str, int i);
char				*ft_strrchr(const char *s, int i);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

int					ft_toupper(int i);
int					ft_tolower(int i);
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_isdigit(int i);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t l);
int					ft_strncmp(const char *s1, const char *s2, size_t l);

void				ft_putnbr_fd(int i, int fd);
void				ft_bzero(void *s, size_t l);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memchr(const void *s, int i, size_t l);
void				*ft_memcpy(void *dst, const void *src, size_t i);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *index);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **list, t_list *new);
void				ft_lstadd_front(t_list **list, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
