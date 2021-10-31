/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/31 17:58:29 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void)
{
	mlx_destroy_window(g_rt.mlx, g_rt.win);
	printf("Bye Bye~");
	exit(0);
}

int	key_hook(int keycode)
{
	if (keycode == 53)
		exit_hook();
	return (0);
}

void	rendering(void)
{
	int			i;
	int			j;
	t_color3	color_tmp;
	int			color_mlx;

	g_rt.mlx = mlx_init();
	g_rt.win = mlx_new_window(g_rt.mlx, g_rt.width, g_rt.height, "miniRT");
	j = g_rt.height;
	while (--j >= 0)
	{
		i = 0;
		while (i < g_rt.width)
		{
			color_tmp = trace_ray(j, i);
			color_mlx = color_pixel(color_tmp);
			mlx_pixel_put(g_rt.mlx, g_rt.win, i, g_rt.height - j, color_mlx);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	g_rt.width = 640; //1920
	g_rt.height = 640; //1080
	read_file(argc, argv);
	rendering();
	mlx_hook(g_rt.win, 2, 0, key_hook, g_rt.mlx);
	mlx_hook(g_rt.win, 17, 0, exit_hook, g_rt.mlx);
	mlx_loop(g_rt.mlx);
	while(1)
		;
	return (0);
}
