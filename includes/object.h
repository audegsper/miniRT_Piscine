#ifndef OBJECT_H
# define OBJECT_H

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