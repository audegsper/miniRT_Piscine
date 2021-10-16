/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/17 00:07:55 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			main(int argc, char **argv)
//  int		main()
{
	int		fd;
	char 	*line;
	int		ret;
	t_object_condition *ob;

	ob = (t_object_condition*)malloc(sizeof(t_object_condition));
	ob->sp = malloc(sizeof(t_sphere));

	// ft_memset((void *)ob, 0, sizeof(t_object_condition));
	if (argc != 2)
		e_file_param();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		e_file_open();
	ret = get_next_line(fd, &line);
	if (ret == END)
		return (1);
	if (ret < 0)
			e_file_read(fd);
	parse(line, fd, ob);
	free_ptr((void **)(&line));
	printf("x! : %f\n", ob->sp->p.x);
	printf("y : %f\n", ob->sp->p.y);
	printf("z : %f\n", ob->sp->p.z);
	printf("r : %f\n", ob->sp->r);
	printf("r : %d\n", ob->sp->c.r);
	printf("g : %d\n", ob->sp->c.g);
	printf("b : %d\n", ob->sp->c.b);
	close(fd);
	t_rt *rt = (t_rt *)malloc(sizeof(t_rt)); //dohykim
	// read_file(argc, argv); // hyson
	show_s_sphere(rt); //dohykim
	// // init_sphere(t_point3}, {double}});
	 rt->s = init_sphere(vec_create(ob->sp->p.x, ob->sp->p.y, ob->sp->p.z), ob->sp->r); //dohykim
	show_s_sphere2(rt); //dohykim
	free(rt); //dohykim
	return (0);
}
