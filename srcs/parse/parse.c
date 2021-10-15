/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/10/15 18:50:43 by hyson            ###   ########.fr       */
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

t_bool		parse(char *line, int fd, t_object_condition *ob)
{
	char	*tmp;
	int		id;

	tmp = line;
	id = 0;
	ob = 0;

	/*
	** 구분자별로 모듈 나누기
	** 모듈별로 담아놓을 변수가 다름
	*/
	// if (identifier(line) == AMBIENT)
	// else if (identifier(line) == CAMERA)
	// else if (identifier(line) == LIGHT)
	// else if (identifier(line) == PLANE)
	// else if (identifier(line) == SPHERE)
	// else if (identifier(line) == CYLINDER)
	//else //
	if (identifier(line) == ERROR)
		e_identifier((void **)&line, fd);
	return (SUCCESS);
}