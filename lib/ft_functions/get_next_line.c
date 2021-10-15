/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:48:48 by hyson             #+#    #+#             */
/*   Updated: 2021/10/15 23:58:27 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minirt.h"
#include "lib.h"

static t_bool	ft_backup(char **s, char *s2)
{
	char	*s1;

	if (!*s)
	{
		*s = ft_strdup(s2);
		if (!*s)
			return (FALSE);
		return (TRUE);
	}
	s1 = ft_strdup(*s);
	free_ptr((void **)s);
	if (!s1)
		return (FALSE);
	if (!dalloc((void **)s, ft_strlen(s1) + ft_strlen(s2) + 1, 1))
	{
		free_ptr((void **)(&s1));
		return (FALSE);
	}
	ft_strlcpy(*s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(*s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free_ptr((void **)(&s1));
	return (TRUE);
}

static t_bool	ft_check_newline(char *str, int *ret)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			*ret = i;
			return (TRUE);
		}
	}
	*ret = -1;
	return (FALSE);
}

static int		ft_split_line(char **save, char **line, int idx)
{
	char	*tmp;

	(*save)[idx] = '\0';
	*line = ft_strdup(*save);
	if (!*line)
	{
		free_ptr((void **)(save));
		return (ERROR);
	}
	if (!ft_strlen(*save + idx + 1))
	{
		free_ptr((void **)(save));
		return (SUCCESS);
	}
	tmp = *save;
	*save = ft_strdup(*save + idx + 1);
	free_ptr((void **)(&tmp));
	if (!*save)
		return (ERROR);
	return (SUCCESS);
}

static int		ft_exception(char **save, char **line,
		int read_size, char **buf)
{
	int	idx;

	idx = -1;
	free_ptr((void **)(buf));
	if (read_size < 0)
	{
		free_ptr((void **)(save));
		return (ERROR);
	}
	if (*save)
	{
		if (ft_check_newline(*save, &idx))
			return (ft_split_line(save, line, idx));
		*line = *save;
		*save = NULL;
		return (END);
	}
	if (!dalloc((void **)line, 1, sizeof(char)))
	{
		free_ptr((void **)save);
		return (ERROR);
	}
	return (END);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			ret;
	static char *save[OPEN_MAX + 3];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd ||
		!dalloc((void **)(&buf), BUFFER_SIZE + 1, 1))
		return (ERROR);
	while (TRUE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (!ft_backup((&(save[fd])), buf))
		{
			free_ptr((void **)(&buf));
			return (ERROR);
		}
		if (ft_check_newline(save[fd], &ret))
		{
			free_ptr((void **)(&buf));
			return (ft_split_line(&(save[fd]), line, ret));
		}
	}
	return (ft_exception(&save[fd], line, ret, &buf));
}
