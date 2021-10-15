/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/10/15 11:27:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int		read_file(int argc, char **argv)
{
	int		fd;
	char 	*line;
	int		ret;

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
		if (parse(line, fd))
			continue ;
		free_ptr((void **)(&line));
	}
	close(fd);

	return (0);
}

t_bool		parse(char *line, int fd)
{
	char	*tmp;
	int		id;

	tmp = line;
	id = 0;

	/*
	** 구분자별로 모듈 나누기
	** 모듈별로 담아놓을 변수가 다름
	*/

	if (identifier(line) == ERROR)
		e_identifier((void **)&line, fd);
	return (SUCCESS);
}
