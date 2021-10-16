/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:03:32 by dohykim           #+#    #+#             */
/*   Updated: 2021/10/15 22:07:443 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_vec3			t_point3;
typedef	struct	s_vec3			t_vec3;
typedef	struct	s_color		t_color;

typedef	struct s_ambient		t_ambient;
typedef	struct s_camera			t_camera;

typedef	struct s_light			t_light;
typedef	struct s_sphere			t_sphere;
typedef	struct s_plane			t_plane;
typedef	struct s_cylinder		t_cylinder;

/*
** -----------------------------------------------------------------------------
** I D E N T I F I E R
** -----------------------------------------------------------------------------
*/

typedef int				t_object_type;
# define BLANK 0
# define AMBIENT 1
# define CAMERA 2
# define LIGHT 3
# define SPHERE 4
# define PLANE 5
# define CYLINDER 6

/*
struct 	s_point3
{
	double		x;
	double		y;
	double		z;
};
*/
struct s_vec3
{
	double		x;
	double		y;
	double		z;
};

struct	s_color
{
	double		r;
	double		g;
	double		b;
};

struct s_camera
{
	t_point3 	p;
	t_vec3		n; //정규화된 방향벡터
	double		fov;
};

struct s_ambient
{
	double		s;
	t_color		c;
};

struct s_light
{
	t_point3	p;
	double		bright_ratio;
	t_color		c;
};

struct s_sphere
{
	t_point3	*p;
	double		r;
	t_color		c;
};

struct s_plane
{
	t_point3	p;
	t_vec3		n; //정규화된 방향벡터
	t_color		c;
};

struct s_cylinder
{
	t_point3	p;
	t_vec3		n; //정규화된 방향벡터
	double		d; //diameter(직경)
	double		h;
	t_color		c;
};

#endif
