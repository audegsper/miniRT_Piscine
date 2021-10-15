/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:19:28 by hyson             #+#    #+#             */
/*   Updated: 2021/10/14 15:18:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** -----------------------------------------------------------------------------
** D E P E N D E N C Y
** -----------------------------------------------------------------------------
*/

# include <stdlib.h>
# include "mlx.h"
# include "parse.h"

int		read_file(int argc, char **argv);
int     mlx_show();
/*
** -----------------------------------------------------------------------------
** T Y P E _ D E F I N I T I O N S
** -----------------------------------------------------------------------------
*/

typedef	int		t_bool;

typedef	struct 	s_point3
{
	double		x;
	double		y;
	double		z;
}				t_point3;

typedef	struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef	struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef	struct s_ambient
{
	double		s;
	t_color		c;
}				t_ambient;

typedef	struct s_camera
{
	t_point3 	p;
	t_vec3		n; //정규화된 방향벡터
	double		fov;
}				t_camera;

typedef	struct s_light
{
	t_point3	p;
	double		bright_ratio;
	t_color		c;
}				t_light;

typedef	struct s_sphere
{
	t_point3	p;
	double		r;
	t_color		c;
}				t_sphere;

typedef	struct s_plane
{
	t_point3	p;
	t_vec3		n; //정규화된 방향벡터
	t_color		c;
}				t_plane;

typedef	struct s_cylinder
{
	t_point3	p;
	t_vec3		n; //정규화된 방향벡터
	double		d; //diameter(직경)
	double		h;
	t_color		c;
}				t_cylinder;

#endif
