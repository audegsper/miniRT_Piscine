/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/21 02:16:27 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int exit_hook(void)
{
	exit(1);
}

int	key_hook(int keycode, t_rt* rt)
{
	if (keycode == 53)
	{
		mlx_destroy_window(rt->mlx, rt->mlx);
		exit(0);
	}
	return (0);
}

void	init_rt(void)
{
	g_rt.mlx = mlx_init();
	g_rt.width = 500; //1440(4:3), 1920(16:9)
	g_rt.height = 300;
}

void	rendering(void)
{
	int		i;
	int		j;

	t_vec3 dir;
	t_color3 color_tmp;

	j = g_rt.height;
	g_rt.win = mlx_new_window(g_rt.mlx, g_rt.width, g_rt.height, "miniRT");

	while (--j >= 0) //300 -> 0
	{
		i = 0;
		while (i < g_rt.width) //0 -> 500
		{
			color_tmp = color(0, 0, 0);
			dir = get_ray(j,i, g_rt.cam);
			g_rt.ray = new_ray(g_rt.cam.p, dir);

			g_rt.rec.t_min = EPSILON;
			g_rt.rec.t_max = INFINITY;

			if (hit(g_rt.object, &g_rt.ray, &g_rt.rec))
				color_tmp = phong_lighting(&g_rt.ray);
		/*	else
			{
				t_vec3 unit = v_unit(g_rt.ray.dir);
				double t = 0.5 * (unit.y + 1.0);
				color_tmp = (v_plus(v_mul(1.0 - t, vec(1, 1, 1))
				, v_mul(t, vec(0.5, 0.7, 1.0))));
			} */
			color_pixel(color_tmp);
			/*if ((j < 300 && j > 250) &&( i < 50 && i > 0))
				color_pixel(color(1,0,0));*/
			mlx_pixel_put(g_rt.mlx, g_rt.win, i, j, g_rt.color);
			i++;
		}
	}
}

int			main(int argc, char **argv)
{
	int		fd;
	char 	*line;
	int		ret;
	t_object_condition *ob;

	ob = (t_object_condition*)malloc(sizeof(t_object_condition));
	ob->sp = malloc(sizeof(t_sphere));
	init_rt();
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
	/*
	printf("x! : %f\n", ob->sp->p.x);
	printf("y : %f\n", ob->sp->p.y);
	printf("z : %f\n", ob->sp->p.z);
	printf("r : %f\n", ob->sp->r);
	printf("r : %d\n", ob->sp->c.r);
	printf("g : %d\n", ob->sp->c.g);
	printf("b : %d\n", ob->sp->c.b);
	*/
	close(fd);

	rendering();
	mlx_hook(g_rt.win, 2, 0, key_hook, &g_rt);
	mlx_hook(g_rt.win, 17, 0, exit_hook, &g_rt);
	mlx_loop(g_rt.mlx);
	return (0);
}
