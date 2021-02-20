/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cryu <cryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:51:41 by cryu              #+#    #+#             */
/*   Updated: 2021/02/17 09:41:30 by cryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (ft_strlen(src));
	if (!src || !src)
		return (0);
	while (src[len] && len + 1 < n)
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dst_idx;
	size_t	src_idx;

	dst_idx = 0;
	src_idx = 0;
	if (n == 0)
		return (ft_strlen(src));
	dst_idx = ft_strlen(dst);
	while (dst_idx > n)
		return (ft_strlen(src) + n);
	while (src[src_idx] && (dst_idx + src_idx) < n - 1)
	{
		dst[dst_idx + src_idx] = src[src_idx];
		src_idx++;
	}
	dst[dst_idx + src_idx] = '\0';
	return (dst_idx + ft_strlen(src));
}

char	*ft_strdup(char *s)
{
	char	*tmp;
	size_t	idx;

	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (s[idx])
	{
		tmp[idx] = s[idx];
		idx++;
	}
	tmp[idx] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(tmp, s1, s1_len + 1);
	free(s1);
	ft_strlcat(tmp + s1_len, s2, s2_len + 1);
	return (tmp);
}
