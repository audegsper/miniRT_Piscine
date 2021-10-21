/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:14 by hyson             #+#    #+#             */
/*   Updated: 2021/10/21 17:40:37 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_light (/* t_object_condition *ob */)
{

	t_light	*light;

	light = (t_light *) malloc(sizeof(t_light));
	light->p = point(5,4,-1);
	light->bright_ratio = 0.6;
	light->c = color(255.0/255.0, 255.0/255.0, 255.0/255.0);

	add_object(&g_rt.light ,new_object(LIGHT, light));
}

// void	get_light(t_object_condition **ob)
// {}
