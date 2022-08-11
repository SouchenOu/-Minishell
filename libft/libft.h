/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:52 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 15:46:34 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
long long			ft_atoi(const char *str);
long long			my_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strrchr(const char *s, int r);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_isalpha(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
#endif
