/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:14:54 by paescano          #+#    #+#             */
/*   Updated: 2023/08/14 17:31:35 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//Buffer deafult with size 5 bytes
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// main function of get the next line
char	*get_next_line(int fd);
// read fd until '\n' or end fd and return the result string
char	*ft_read_fd(int fd, char *buffer_read);
// return a string until '\n' or end the result string;
char	*ft_get_line(char *buffer_read);
// return the remaining buffer
char	*ft_restart(char *buffer_read);

// Returns a pointer to the first occurrence of the character c in the string s.
char	*ft_strchr(char *s, int c);
// Returns a pointer to a new string which is a duplicate of string.
char	*ft_strndup(char *s, size_t x);
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief Return a size of any string
 * 
 * @param s 
 * @return * Return the size of a string
 */
size_t	ft_strlen(char *s);
/**
*	Copies n bytes from memory area src to
*	memory area dest.  The memory areas must not overlap.
*/
void	*ft_memcpy(void *dest, void *src, size_t n);

#endif