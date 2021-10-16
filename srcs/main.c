/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 19:06:52 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//int			main(int argc, char **argv)
 int		main()
{
	t_rt *rt = (t_rt *)malloc(sizeof(t_rt)); //dohykim
	//read_file(argc, argv); // hyson
	show_s_sphere(rt); //dohykim
	rt->s = init_sphere(vec_create(0, 0, -1), 0.5); //dohykim
	show_s_sphere2(rt); //dohykim
	free(rt); //dohykim
	return (0);
}
