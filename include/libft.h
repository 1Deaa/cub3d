/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:30:52 by drahwanj          #+#    #+#             */
/*   Updated: 2025/03/14 14:57:50 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>

/*
Return the length of S
*/
int		ft_strlen(const char *s);
/*
Allocate COUNT elements of SIZE bytes each, all initialized to 0.
*/
void	*ft_calloc(size_t count, size_t size);
/*
Append SRC onto DEST.
*/
char	*ft_strcat(char *dest, const char *src);
/*
Finds the first occurence of C in S.
*/
char	*ft_strchr(const char *s, int c);
/*
Checks for whitespace.
*/
int		ft_isspace(char c);
/*
Duplicate of S size of N.
*/
char	*ft_strndup(const char *s, size_t n);
/*
Compare S1 with S2.
*/
int		ft_strcmp(const char *s1, const char *s2);
/*
Duplicate of STR.
*/
char	*ft_strdup(const char *str);
/*
Copy N bytes from SRC to DEST.
*/
char	*ft_strncpy(char *dest, const char *src, size_t n);
/*
Joins S1 with S1.
*/
char	*ft_strjoin(char *s1, char *s2);
/*
Checks wether C is alpha numeric or not.
*/
bool	ft_isalpha(char c);
/*
Join a C with S.
*/
char	*ft_charjoin(char *s, char c);
/*
Check if C is a digit.
*/
int		ft_isdigit(int c);
/*
Copies n - 1 bytes from a source string to a destination string.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*
Print a string on an fd.
*/
int		ft_putstr_fd(const char *str, int fd);
/*
s -> 0
*/
void	ft_memzero(void *s, size_t n);
/*
Compare N bytes from S1 with S2.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*
Split S into parts with delimiter C.
*/
char	**ft_split(char const *s, char c);
/*
free 2D arr
*/
void	free_split(char **arr);
/*
convert N into a null terminated string
*/
char	*ft_itoa(int n);
/*
convert STR into int
*/
int		ft_atoi(const char *str);

bool	ft_isalnum(char c);
/*
Finds the last occurence of C in S.
*/
char	*ft_strrchr(const char *s, int c);

#endif
