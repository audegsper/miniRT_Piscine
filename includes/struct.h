/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:03:32 by dohykim           #+#    #+#             */
/*   Updated: 2021/10/31 00:08:02 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_color3;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

/*
** -----------------------------------------------------------------------------
** I D E N T I F I E R
** -----------------------------------------------------------------------------
*/

# define LUMEN 3
# define EPSILON 0.0001
# define KSN 64
# define KS 0.5

typedef int					t_object_type;
# define BLANK 0
# define AMBIENT 1
# define CAMERA 2
# define LIGHT 3
# define SPHERE 4
# define PLANE 5
# define CYLINDER 6

typedef struct s_rt			t_rt;
typedef struct s_object		t_object;
typedef struct s_ray		t_ray;
typedef struct s_rec		t_rec;

struct s_object
{
	int		type;
	void	*element;
	void	*next;
};

struct s_vec3
{
	double		x;
	double		y;
	double		z;
};

struct	s_ambient
{
	double		s;
	t_color3	c;
};

struct s_camera
{
	t_point3	p;
	t_vec3		n;
	double		fov;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	t_vec3		vup;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	llc;
};

struct s_light
{
	t_point3	p;
	double		bright_ratio;
	t_color3	c;
	t_light		*next;
};

struct s_sphere
{
	t_point3	p;
	double		r;
	t_color3	c;
	t_sphere	*next;
};

struct s_plane
{
	t_point3	p;
	t_vec3		n;
	t_color3	c;
};

struct s_cylinder
{
	t_point3	p;
	t_point3	p_top;
	t_vec3		n;
	double		d;
	double		r;
	double		r2;
	double		h;
	t_color3	c;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct s_rec
{
	t_point3	p;
	double		t;
	t_vec3		n;
	double		t_max;
	double		t_min;
	t_bool		front_face;
	t_color3	albedo;
};

struct s_rt
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_camera	cam;
	t_color3	ambient;
	t_object	*light;
	t_object	*object;
};

#endif
