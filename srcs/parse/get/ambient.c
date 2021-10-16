/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:59:59 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 18:05:28 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_bool	parse_a(t_object_condition *ob, char *line)
{
	t_bool		ret;

	ret = TRUE;
	if (!check_double(&line, &(ob->a->s)))
		ret = FALSE;
	return (ret);
}

t_bool	get_ambient(t_object_condition *ob, char *line)
{
	if (!parse_a(ob, line))
		return (FALSE);

	//a 옵션들 확인해주는 모듈필요
	return (TRUE);
}
