/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:19:28 by hyson             #+#    #+#             */
/*   Updated: 2021/10/31 13:49:59 by dohykim          ###   ########.fr       */
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
# include <math.h>
# include "mlx.h"
# include "lib.h"
# include "struct.h"
# include "parse.h"
//# include "test.h"
//# include "test2.h"

t_rt		g_rt;
int			read_file(int argc, char **argv);
void		set_camera(void);
t_vec3		get_ray(double i, double j, t_camera cam);
t_ray		new_ray(t_vec3 origin, t_vec3 direction);
t_color3	get_color(void);
t_bool		hit(t_object *obj, t_ray *r, t_rec *rec);
t_bool		hit_obj(t_rec *rec, t_ray *r, t_object *obj);
int			hit_sphere(t_sphere *sp, t_rec *rec, t_ray *r);
t_point3	ray_at(t_ray *ray, double t);
void		set_face_normal(t_ray *r, t_rec *rec);
t_bool	in_shadow(t_ray *light_r);
t_color3	get_point_light(t_light *light, t_ray *r, t_rec *rec);
t_color3	get_phong(t_ray *r, t_vec3	light_dir, t_light *light, t_rec *rec);
t_color3	get_diffuse(t_vec3	light_dir, t_light *light, t_rec *rec);
t_color3	get_specular(\
			t_ray *r, t_vec3 light_dir, t_light *light, t_rec *rec);
t_color3	phong_lighting(t_ray *r, t_rec *rec);
int			color_pixel(t_vec3 color);
t_color3	trace_ray(int height, int width);
int			hit_cylinder(t_cylinder *cy, t_rec *rec, t_ray *r);
int			hit_plane(t_plane *pl, t_rec *rec, t_ray *r);

void		set_light(t_object_condition *ob);
void		set_sphere(t_object_condition *ob);
void		set_sylinder(t_object_condition *ob);
void		set_plane(t_object_condition *ob);
void		add_object(t_object **list, t_object *new);
t_object	*new_object(int type, void *element);

t_vec3		vec(double x, double y, double z);
t_point3	point(double x, double y, double z);
t_color3	color(double r, double g, double b);

t_point3	v_plus(t_point3 v1, t_point3 v2);
t_point3	v_minus(t_point3 v1, t_point3 v2);
t_point3	v_mul(double t, t_point3 v);
t_point3	v_mul2(t_point3 v1, t_point3 v2);
t_point3	v_div(t_point3 v, double t);

t_vec3		v_unit(t_vec3 v);
double		v_len(t_vec3 v);
double		v_len2(t_vec3 v);
t_point3	v_min(t_vec3 v, t_vec3 l);
double		v_dot(t_vec3 v1, t_vec3 v2);

t_vec3		v_cross(t_vec3 u, t_vec3 v);
t_vec3		reflect(t_vec3 v, t_vec3 n);
#endif
