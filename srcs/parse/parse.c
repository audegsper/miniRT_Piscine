/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 23:03:372:37 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		read_file(int argc, char **argv)
{
		int		fd;
	char 	*line;
	int		ret;
	t_object_condition *ob;

	/*
		구조체 동적할당 필요. 하나로 정리 필요
	*/
	ob = (t_object_condition*)malloc(sizeof(t_object_condition));
	ob->sp = malloc(sizeof(t_sphere));
	ob->a = malloc(sizeof(t_sphere));
	ob->c = malloc(sizeof(t_camera));
	ob->l = malloc(sizeof(t_light));
	ob->pl = malloc(sizeof(t_plane));

	if (argc != 2)
		e_file_param();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		e_file_open();
	// 	while (TRUE)
	// {
	// 	ret = get_next_line(fd, &line);
	// 	if (ret == END)
	// 		break ;
	// 	if (ret < 0)
	// 			e_file_read(fd);
	// 	if (parse(line, fd, ob))
	// 		continue ;
	// 	free_ptr((void **)(&line));
	// }
	ret = get_next_line(fd, &line);
	if (ret == END)
		return (1);
	if (ret < 0)
			e_file_read(fd);
	parse(line, fd, ob);
	free_ptr((void **)(&line));
	close(fd);


	// printf("x! : %f\n", ob->sp->p.x);
	// printf("y : %f\n", ob->sp->p.y);
	// printf("z : %f\n", ob->sp->p.z);
	// printf("r : %f\n", ob->sp->r);
	// printf("r : %d\n", ob->sp->c.r);
	// printf("g : %d\n", ob->sp->c.g);
	// printf("b : %d\n", ob->sp->c.b);

	// printf("s : %f\n", ob->a->s);
	// printf("r : %f\n", ob->a->c.x);
	// printf("g : %f\n", ob->a->c.y);
	// printf("b : %f\n", ob->a->c.z);

	// printf("fov : %f\n", ob->c->fov);
	// printf("x : %f y : %f z : %f\n", ob->c->p.x, ob->c->p.y, ob->c->p.z);
	// printf("n.x : %f n.y : %f n.z : %f\n", ob->c->n.x, ob->c->n.y, ob->c->n.z);

	// printf("x : %f y : %f z : %f\n", ob->l->p.x, ob->l->p.y, ob->l->p.z);
	// printf("bright ratio : %f\n", ob->l->bright_ratio);
	// printf("r : %f g : %f b : %f\n", ob->l->c.x, ob->l->c.y, ob->l->c.z);

	printf("x : %f y : %f z : %f\n", ob->pl->p.x, ob->pl->p.y, ob->pl->p.z);
	printf("n.x : %f n.y : %f n.z : %f\n", ob->pl->n.x, ob->pl->n.y, ob->pl->n.z);
	printf("r : %f g : %f b : %f\n", ob->pl->c.x, ob->pl->c.y, ob->pl->c.z);


	return (0);
}


static	t_bool	get_status(t_object_condition *ob, char *line, int id)
{
	t_bool	ret;

	ret = FALSE;

	{// if (id == AMBIENT)
		// ret = get_ambient(ob, line); //아직 이 녀석 미완성. 주변광만 받아옴. rgb받아야하고 주변광과 rgb둘다 유효한지 확인도 해야함
	// g_rt.ambient = color(255.0 / 255.0 * 0.2, 255.0 / 255.0 * 0.2, 255.0 / 255.0 * 0.2);
	// g_rt.ambient = color(rgb값 / 255.0 * 비율);
	}

	if (id == AMBIENT)
		ret = get_ambient(ob, line);

	else if (id == CAMERA)
		ret = get_camera(ob, line);
	// g_rt.cam.p = point(0,0,-5);
	// g_rt.cam.n = point(0.0,0.0,1);
	// g_rt.cam.fov = 80;
	// set_camera();
	// }

	else if (id == LIGHT)
		ret = get_light(ob, line);
	// {// else if (id == LIGHT)
	// // 	ret = get_light(ob, line);
	// 	set_light(ob);
	// }

	else if (id == SPHERE)
	{
		ret = get_sphere(ob, line);
		set_sphere(ob);
	}

	else if (id == PLANE)
		ret = get_plane(ob, line);

	// else if (id == CYLINDER)
	{
		// 	ret = get_cylinder(ob, line);
		// set_sylinder(ob);
	}


	// 처리해야할 녀석들


	// else if (id == SPHERE)
	// 	ret = get_sphere(ob, line);
	// else if (id == PLANE)
	// 	ret = get_plane(ob, line);

	return (ret);
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
	id = identifier(tmp);
	if (!id)
		e_identifier((void **)&line, fd);
	else if (id <= 3)
		tmp = tmp + 2;
	else
		tmp = tmp + 3;
	if (!get_status(ob, tmp, id))
		e_condition_value((void **)(&line), fd);
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
