/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 23:03:32 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	object_init(t_object_condition *ob)
{
	ob->sp = malloc(sizeof(t_sphere));
	ob->a = malloc(sizeof(t_sphere));
	ob->c = malloc(sizeof(t_camera));
	ob->l = malloc(sizeof(t_light));
	ob->pl = malloc(sizeof(t_plane));
	ob->cy = malloc(sizeof(t_cylinder));
}

int	read_file(int argc, char **argv)
{
	int					fd;
	char				*line;
	int					ret;
	t_object_condition	*ob;

	ob = (t_object_condition *)malloc(sizeof(t_object_condition));
	object_init(ob);
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
		if (parse(line, fd, ob))
			continue ;
		free_ptr((void **)(&line));
	}
	close(fd);
	return (0);
}

static	t_bool	get_status(t_object_condition *ob, char *line, int id)
{
	t_bool	ret;

	ret = FALSE;
	if (id == AMBIENT)
		ret = get_ambient(ob, line);
	else if (id == CAMERA)
		ret = get_camera(ob, line);
	else if (id == LIGHT)
		ret = get_light(ob, line);
	else if (id == SPHERE)
		ret = get_sphere(ob, line);
	else if (id == PLANE)
		ret = get_plane(ob, line);
	else if (id == CYLINDER)
		ret = get_cylinder(ob, line);
	return (ret);
}

t_bool	parse(char *line, int fd, t_object_condition *ob)
{
	char	*tmp;
	int		id;

	tmp = line;
	if (!ft_strncmp(tmp, "", ft_strlen(tmp)))
	{
		write(1, "blank\n", 6);
		return (BLANK);
	}
	while (is_blank(*tmp))
		++tmp;
	id = identifier(tmp);
	if (!id)
		e_identifier((void **)&line, fd);
	else if (id <= 3)
		tmp = tmp + 2;
	else
		tmp = tmp + 3;
	if (!get_status(ob, tmp, id))
		e_condition_value((void **)(&line), fd);
	return (SUCCESS);
}
