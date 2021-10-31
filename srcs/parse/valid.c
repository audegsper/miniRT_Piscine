/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:20:10 by hyson             #+#    #+#             */
/*   Updated: 2021/10/31 19:20:36 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	valid_color(t_color3 c)
{
	return ((c.x >= 0.0 && c.x <= 255.0) && (c.y >= 0.0 && c.y <= 255.0)
		&& (c.z >= 0.0 && c.z <= 255.0));
}

t_bool	valid_vec3(t_vec3 v)
{
	if (fabs(v.x) != 1 && fabs(v.y) != 1 && fabs(v.z) != 1)
		return (FALSE);
	else if ((v.x * v.x + v.y * v.y + v.z * v.z) != 1)
		return (FALSE);
	return (TRUE);
}

t_bool	valid_vec3_camera(t_vec3 v)
{
	return ((v.x >= -1.0 && v.x <= 1.0) && (v.y >= -1.0 && v.y <= 1.0) &&
			(v.z >= -1.0 && v.z <= 1.0));
}
