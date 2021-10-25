/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:10 by hyson             #+#    #+#             */
/*   Updated: 2021/10/24 17:48:56 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_sylinder(/* t_object_condition *ob */)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->p = point(50.0, 0.0, 20.6);
	cylinder->n = v_unit(vec(0.0, 0.0, 1.0));
	cylinder->c = color(10, 0, 255);
	cylinder->d = 14.2;
	cylinder->h = 21.42;
}

// void	get_cylinder(t_object_condition **ob)
// {

// }
