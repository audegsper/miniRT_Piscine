/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:33:44 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 00:12:45 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minirt.h"
#include "lib.h"

t_bool	is_blank(char c)
{
	return (c == ' ' || c == '\v' || c == '\t');
}
