/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 15:15:36 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/03/28 15:31:03 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*comb(char *s1, char *s2);
char	*prep(char *s, char *return_s, int endIndex);
char	*ft_strdup(char *s1);
char	*clean_pointers(char *s1, char *s2, int re);

#endif
