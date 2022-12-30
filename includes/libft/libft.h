/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:23:48 by yanab             #+#    #+#             */
/*   Updated: 2022/12/30 09:43:38 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_abs(int n);
char	**ft_add_arr(char **arr, size_t index, char *value);
char	*ft_add_str(char *str, int index, char *value);
int		ft_any(const char *str, int (*f)(char));
int		ft_arr_indexof(char **arr, char *target);
int		ft_arr_len(char **arr);
int		ft_atoi(const char *nstr);
void	ft_bsort(int len, int *arr, int (*cmp)(int, int));
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
bool	ft_contains(char *str, char chr);
bool	ft_contains_set(char *str, char *set);
int		ft_countchr(char *str, char c);
char	*ft_ctos(char chr, int count);
char	**ft_del_arr(char **arr, size_t index);
int		ft_every(char *arr, int (*f)(char));
int		ft_every_char(const char *str, char c);
int		ft_find(int length, int *array, int num);
char	*ft_find_n_replace(char *str, int start_i, char *find, char *replace);
void	ft_free_arr(char ***arr);
int		ft_indexof(char *str, char c);
int		ft_inrange(int number, int min, int max);
int		ft_intlen(int n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
bool	ft_isempty(char *str);
int		ft_isprint(int c);
int		ft_isspace(int c);
char	*ft_itoa(int n);
void	ft_loop(int from, int to, void (*f)());
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putbin_fd(unsigned int n, int fd, bool is_prefixed);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_puthex_fd(unsigned int n, int fd, bool is_prefixed);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_sort_part(int *array, int size, int (*cmp)(int, int));
void	ft_qsort(int *array, int size, int (*cmp)(int, int));
void	ft_swap_str(char **arr, int i, int j);
int		ft_sort_str(char **array, int size,
			int (*cmp)(const char *, const char *));
void	ft_qsort_str(char **array, int size,
			int (*cmp)(const char *, const char *));
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	**ft_split(char const *s, char c);
char	**ft_split_set(char const *s, char *set);
int		ft_strcasecmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_arr(char **arr);
char	*ft_multijoin(int strs_count, ...);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_swap(int *arr, int i, int j);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_getline(int fd);

#endif
