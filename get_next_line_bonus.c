/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cryu <cryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:49:29 by cryu              #+#    #+#             */
/*   Updated: 2021/02/20 17:22:31 by cryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_newline(char *s)
{
	int idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		res_line(char **save_line, char **line, int newline_idx)
{
	int		save_line_size;
	char	*tmp;

	save_line_size = (int)ft_strlen(*save_line);
	(*save_line)[newline_idx] = '\0';
	*line = ft_strdup(*save_line);
	if (save_line_size == newline_idx + 1)
	{
		free(*save_line);
		*save_line = 0;
		return (SUCCESS);
	}
	else
	{
		tmp = ft_strdup(*save_line + newline_idx + 1);
		free(*save_line);
		*save_line = tmp;
		return (SUCCESS);
	}
}

int		res_end(char **save_line, char **line)
{
	int newline_idx;

	if (!(*save_line))
	{
		*line = ft_strdup("");
		return (ENDFILE);
	}
	newline_idx = check_newline(*save_line);
	if (newline_idx >= 0)
		return (res_line(save_line, line, newline_idx));
	else
	{
		*line = *save_line;
		*save_line = 0;
		return (ENDFILE);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*save_line[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			newline_idx;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE <= 0))
		return (ERROR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		save_line[fd] = ft_strjoin(save_line[fd], buf);
		newline_idx = check_newline(save_line[fd]);
		if (newline_idx >= 0)
			return (res_line(&save_line[fd], line, newline_idx));
	}
	if (read_size < 0)
		return (ERROR);
	return (res_end(&save_line[fd], line));
}
