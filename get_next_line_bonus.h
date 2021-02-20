/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cryu <cryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:10:20 by cryu              #+#    #+#             */
/*   Updated: 2021/02/20 17:23:43 by cryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# define SUCCESS 1
# define ENDFILE 0
# define ERROR -1

# include <stdlib.h>
# include <unistd.h>

int		get_next_line_bonus(int fd, char **line);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
