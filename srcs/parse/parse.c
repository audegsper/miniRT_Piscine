/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/11/01 12:31:14 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	object_init(t_object_condition *ob)
{
	if (!ob)
		exit(1);
	ob->sp = malloc(sizeof(t_sphere));
	if (!ob->sp)
		exit(1);
	ob->a = malloc(sizeof(t_ambient));
	if (!ob->a)
		exit(1);
	ob->c = malloc(sizeof(t_camera));
	if (!ob->c)
		exit(1);
	ob->l = malloc(sizeof(t_light));
	if (!ob->l)
		exit(1);
	ob->pl = malloc(sizeof(t_plane));
	if (!ob->pl)
		exit(1);
	ob->cy = malloc(sizeof(t_cylinder));
	if (!ob->cy)
		exit(1);
}

static	void	check_param(int argc, char **argv)
{
	int	name_len;

	if (argc != 2)
		e_file_param();
	name_len = ft_strlen(argv[1]);
	if (name_len < 3 || ft_strncmp(argv[1] + name_len - 3, ".rt", 4) != 0)
		e_file_param();
}

int	read_file(int argc, char **argv)
{
	int					fd;
	char				*line;
	int					ret;
	t_object_condition	*ob;

	ob = (t_object_condition *)malloc(sizeof(t_object_condition));
	object_init(ob);
	check_param(argc, argv);
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
	if (!ft_strncmp(tmp, "", ft_strlen(tmp)) || !ft_strncmp(tmp, "#", 1))
		return (BLANK);
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
