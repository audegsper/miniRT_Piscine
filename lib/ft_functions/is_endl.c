/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_endl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:41:14 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 12:41:45 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_endl(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s && is_blank((*s)))
		++s;
	if (!*s)
		return (TRUE);
	return (FALSE);
}
