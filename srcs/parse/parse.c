/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/10/15 23:35:46 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		read_file(int argc, char **argv)
{
	int		fd;
	char 	*line;
	int		ret;
	t_object_condition ob;

	if (argc != 2)
		e_file_param();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		e_file_open();
	while (TRUE)
	{
		ret = get_next_line(fd, &line);
		if (ret == END)
			break ;
		if (ret < 0)
				e_file_read(fd);
		if (parse(line, fd, &ob))
			continue ;
		free_ptr((void **)(&line));
	}
	close(fd);

	return (0);
}

static	t_bool	get_status(t_object_condition *ob, char *line, int id)
{
	t_bool	ret;

	ret = ERROR;
	if (id == AMBIENT)
		ret = get_ambient(ob, line);
}

t_bool		parse(char *line, int fd, t_object_condition *ob)
{
	char	*tmp;
	int		id;
	tmp = line;

	/*
	** 구분자별로 모듈 나누기
	** 모듈별로 담아놓을 변수가 다름
	*/
	if (!ft_strncmp(tmp, "", ft_strlen(tmp)))
	{
		write(1, "blank\n", 6);
		return (BLANK);
	}
	while (is_blank(*tmp))
		++tmp;
	id = identifier(line);
	if (!id)
		e_identifier((void **)&line, fd);
	else if (id <= 3)
		tmp = tmp + 2;
	else
		tmp = tmp + 3;

	// if (id == AMBIENT)
	// 	get_ambient(ob, tmp);
	// else if (id == CAMERA)
	// else if (id == LIGHT)
	// else if (id == PLANE)
	// else if (id == SPHERE)
	// else if (id == CYLINDER)
	//else //

	return (SUCCESS);
}
