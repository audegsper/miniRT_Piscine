
typedef struct		s_ray
{
	t_vec3		*orig;
	t_vec3		*dir;
}		t_ray;

typedef struct			s_img_data
{
	int					**img;
	int					width;
	int					height;
}						t_img_data;

typedef struct s_sky_info
{
    double  viewport_width;
    double  viewport_height;
    double  focal_length;
}       t_sky_info;


typedef struct s_sky
{
    t_img_data  *data;
    t_vec3       *horizontal;
    t_vec3       *vertical;
    t_vec3       *lower_left_corner;
    t_vec3       *origin;
}       t_sky;

typedef struct s_rt
{
    double  aspect_ratio;
     t_img_data  *img;
    t_sky_info  *info;
    t_sphere    *s;
}       t_rt;


//void show_s_sphere();
void show_s_sphere(t_rt *rt);
t_vec3		*vec_create(double x, double y, double z);
t_vec3   *vec_mul_const(t_vec3 *a, double c);
t_vec3   *vec_div_const(t_vec3 *a, double c);
t_vec3   *vec_unit(t_vec3 *a);
int     cal_sky_color(t_ray *r);
t_vec3   *vec_mul_const_apply(t_vec3 *a, double c);
t_vec3 *vec_sub_apply(t_vec3 *a, t_vec3 *b);
t_vec3 *vec_add_apply(t_vec3 *a, t_vec3 *b);
void    draw_s_sphere(t_img_data *data, t_sky_info *info, t_sphere *s);
t_vec3   *vec_sub(t_vec3 *a, t_vec3 *b);
double	vec_dot(t_vec3 *a, t_vec3 *b);
t_vec3   *vec_sub(t_vec3 *a, t_vec3 *b);
void show_s_sphere2(t_rt *rt);
void sphere_here(t_rt *rt);
t_sphere    *init_sphere(t_point3 *center, double radius);
