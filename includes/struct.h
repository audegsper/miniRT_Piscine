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

typedef	int		t_bool;

typedef	struct	s_point3		t_point3;
typedef	struct	s_vec3			t_vec3;
typedef	struct	s_color			t_color;
typedef	struct	s_ray			t_ray;
typedef	struct s_hit_record		t_hit_record;

typedef struct	s_scene			t_scene;
typedef	struct s_canvas			t_canvas;
typedef	struct s_camera			t_camera;
typedef	struct s_ambient		t_ambient;

typedef	struct s_object			t_object;
typedef	struct s_light			t_light;
typedef	struct s_sphere			t_sphere;
typedef	struct s_plane			t_plane;
typedef	struct s_cylinder		t_cylinder;

typedef int				t_object_type;
# define SP 0
# define LIGHT_POINT 1
# define PL 2
# define CY 3


struct 	s_point3
{
	double		x;
	double		y;
	double		z;
};

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

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_bool		front_face;
	double		tmin;
	double		tmax;
	double		t;
	t_color	albedo;
};

struct s_camera
{
	t_point3 	p;
	t_vec3		n; //정규화된 방향벡터
	double		fov;
};

struct	s_canvas
{
	int		width; //canvas width
	int		height; //canvas height;
	double	aspect_ratio; //종횡비
};

struct			s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_hit_record	rec;
};

struct s_ambient
{
	double		s;
	t_color		c;
};

struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color		albedo;
};

struct s_light
{
	t_point3	p;
	double		bright_ratio;
	t_color		c;
};

struct s_sphere
{
	t_point3	p;
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
