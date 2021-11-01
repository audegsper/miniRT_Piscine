/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:42:21 by hyson             #+#    #+#             */
/*   Updated: 2021/11/01 12:32:01 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	identifier(char *line)
{
	int			i;

	i = 0;
	if (line[i] == 'A' && is_blank(line[i + 1]))
		 return (AMBIENT);
	else if (line[i] == 'C' && is_blank(line[i + 1]))
		 return (CAMERA);
	else if (line[i] == 'L' && is_blank(line[i + 1]))
		 return (LIGHT);
	else if (line[i] == 'p' && line[i + 1] == 'l' && is_blank(line[i + 2]))
		 return (PLANE);
	else if (line[i] == 's' && line[i + 1] == 'p' && is_blank(line[i + 2]))
		return (SPHERE);
	else if (line[i] == 'c' && line[i + 1] == 'y' && is_blank(line[i + 2]))
		return (CYLINDER);
	return (ERROR);
}
