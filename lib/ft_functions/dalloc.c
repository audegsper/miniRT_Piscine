/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:55:33 by hyson             #+#    #+#             */
/*   Updated: 2021/10/12 18:31:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	dalloc(void **ptr, size_t cnt, size_t n)
{
	size_t	i;

	i = -1;
	*ptr = (void *)malloc(cnt * n);
	if (!*ptr)
		return (FALSE);
	while (++i < n)
		(*(unsigned char **)ptr)[i] = '\0';
	return (TRUE);
}
