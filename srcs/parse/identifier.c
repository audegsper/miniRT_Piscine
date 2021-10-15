/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:42:21 by hyson             #+#    #+#             */
/*   Updated: 2021/10/14 20:07:11 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_bool	is_blank(char c)
{
	return (c == ' ' || c == '\v' || c == '\t');
}

int				identifier(char *line)
{
	int			i;

	i = 0;
	if (!ft_strncmp(line, "", ft_strlen(line)))
	{
		write(1, "blank\n", 6);
		return (BLANK);
	}
	while (is_blank(line[i]))
		++i;
	if (line[i] == 'A' && is_blank(line[i + 1]))
	{
		write(1, "a\n", 2);
		return (AMBIENT);
	}
	else if (line[i] == 'C' && is_blank(line[i + 1]))
	{
		write(1, "c\n", 2);
		return (CAMERA);
	}
	else if (line[i] == 'L' && is_blank(line[i + 1]))
	{
		write(1, "l\n", 2);
		return (LIGHT);
	}
	else if (line[i] == 'p' && line[i + 1] == 'l' && is_blank(line[i + 2]))
	{
		write(1, "pl\n", 3);
		return (PLANE);
	}
	else if (line[i] == 's' && line[i + 1] == 'p' && is_blank(line[i + 2]))
	{
		write(1, "sp\n", 3);
		return (SPHERE);
	}
	else if (line[i] == 'c' && line[i + 1] == 'y' && is_blank(line[i + 2]))
	{
		write(1, "cy\n", 3);
		return (CYLINDER);
	}
	return (ERROR);
}
