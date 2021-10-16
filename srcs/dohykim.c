#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data)
{
	int			width;
	int			height;
	char		*dst;
	int			next;

	width = -1;
	while ((++width) < img_data->width)
	{
		height = -1;
		while ((++height) < img_data->height)
		{
			next = (img_data->height - height - 1) * mlx_data->line_length;
			next += width * (mlx_data->bits_per_pixel / 8);
			dst = mlx_data->addr + next;
			*(unsigned int*)dst = img_data->img[width][height];
		}
	}
}

int     exit_program(void)
{
    exit(0);
    return (0);
}

int     mlx_key_handle(int  keycode)
{
    if (keycode == 53)
        return (exit_program());
    return (0);
}

void        mlx_show(t_img_data *data, char *title)
{
    t_vars      vars;
    t_mlx_data  *img;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, data->width, data->height, title);
    img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
    img->img = mlx_new_image(vars.mlx, data->width, data->height);
    img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
                                &(img->line_length), &(img->endian));
    mlx_draw_by_img_data(img, data);
    mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
    mlx_destroy_image(vars.mlx, img->img);
    mlx_hook(vars.win, 2, 1L << 0, mlx_key_handle, 0);
    mlx_hook(vars.win, 17, 1L << 17, exit_program, 0);
    mlx_loop(vars.mlx);
    free(img);
    printf("test\t");
}

void    free_sphere(t_sphere *s)
{
    free(s->p);
    free(s);
}

t_sphere    *init_sphere(t_point3 *center, double radius)
{
    t_sphere    *result;

    result = (t_sphere *)malloc(sizeof(t_sphere));
    result->p = center;
    result->r = radius;
    return (result);
}

void    free_sky(t_sky *my_sky, int is_origin_free)
{
    free(my_sky->horizontal);
    free(my_sky->vertical);
    free(my_sky->lower_left_corner);
    if (is_origin_free)
        free(my_sky->origin);
    free(my_sky);
}

void    ray_free(t_ray *ray, int is_orig_free)
{
    if (ray == NULL)
        return ;
    if (is_orig_free && ray->orig != NULL)
        free(ray->orig);
    free(ray->dir);
    free(ray);
}

int			get_color_val(t_vec3 *color)
{
	int		x;
	int		y;
	int		z;

	x = clamp(color->x, 0.0, 0.999) * 256.0;
	y = clamp(color->y, 0.0, 0.999) * 256.0;
	z = clamp(color->z, 0.0, 0.999) * 256.0;
	return (x << 16 | y << 8 | z);
}

t_vec3		*get_color(int rgb)
{
	t_vec3	*result;

	result = (t_vec3*)malloc(sizeof(t_vec3));
	result->x = (rgb & (0xFF << 16)) >> 16;
	result->y = (rgb & (0xFF << 8)) >> 8;
	result->z = rgb & 0xFF;
	return (result);
}

double	vec_length_squared(t_vec3 *a)
{
	return (pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2));
}

double  vec_length(t_vec3 *a)
{
    return (sqrt(vec_length_squared(a)));
}

double	vec_dot(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3   *vec_unit(t_vec3 *a)
{
    return (vec_div_const(a, vec_length(a)));
}

int     cal_sky_color(t_ray *r)
{
    t_vec3   *tmp;
    t_vec3   *tmp2;
    double  t;
    int     result;

    tmp = vec_unit(r->dir);
    t = 0.5 * (tmp->y + 1.0);
    free(tmp);
    tmp = vec_mul_const_apply(vec_create(1,1,1), 1.0 - t);
    tmp2 = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
    vec_add_apply(tmp, tmp2);
    free(tmp2);
    result = get_color_val(tmp);
    free(tmp);
    return (result);
}

t_ray   *ray_create(t_vec3 *origin, t_vec3 *direction)
{
    t_ray   *result;

    result = (t_ray *)malloc(sizeof(t_ray));
    result->orig = origin;
    result->dir = direction;
    return (result);
}

t_ray   *cal_sky_ray(int x, int y, t_sky *my_sky)
{
    t_ray   *r;
    t_vec3   *tmp;
    t_vec3   *tmp2;

    tmp = vec_mul_const(my_sky->horizontal,
                                (double)x / (my_sky->data->width - 1));
    tmp2 = vec_mul_const(my_sky->vertical,
                                (double)y / (my_sky->data->height - 1));
    vec_add_apply(tmp, tmp2);
    free(tmp2);
    vec_add_apply(tmp, my_sky->lower_left_corner);
    r = ray_create(my_sky->origin, vec_sub_apply(tmp, my_sky->origin));
    return (r);
}

t_vec3 *vec_add_apply(t_vec3 *a, t_vec3 *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
    return (a);
}

t_vec3 *vec_sub_apply(t_vec3 *a, t_vec3 *b)
{
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
    return (a);
}

t_vec3   *vec_div_const_apply(t_vec3 *a, double c)
{
    a->x /= c;
    a->y /= c;
    a->z /= c;
    return (a);
}

t_vec3   *vec_mul_const_apply(t_vec3 *a, double c)
{
    a->x *= c;
    a->y *= c;
    a->z *= c;
    return (a);
}

t_vec3   *vec_add(t_vec3 *a, t_vec3 *b)
{
    t_vec3   *result;

    result = (t_vec3*)malloc(sizeof(t_vec3));
    result->x = a->x + b->x;
    result->y = a->y + b->y;
    result->z = a->z + b->z;
    return (result);
}

t_vec3   *vec_sub(t_vec3 *a, t_vec3 *b)
{
    t_vec3   *result;

    result = (t_vec3*)malloc(sizeof(t_vec3));
    result->x = a->x - b->x;
    result->y = a->y - b->y;
    result->z = a->z - b->z;
    return (result);
}

t_vec3   *vec_mul_const(t_vec3 *a, double c)
{
    t_vec3   *result;

    result = (t_vec3*)malloc(sizeof(t_vec3));
    result->x = a->x * c;
    result->y = a->y * c;
    result->z = a->z * c;
    return (result);
}

t_vec3   *vec_div_const(t_vec3 *a, double c)
{
    t_vec3   *result;

    result = (t_vec3*)malloc(sizeof(t_vec3));
    result->x = a->x / c;
    result->y = a->y / c;
    result->z = a->z / c;
    return (result);
}

t_vec3		*vec_create(double x, double y, double z)
{
	t_vec3	*result;

	result = (t_vec3 *)malloc(sizeof(t_vec3));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_sky   *init_sky(t_sky_info *info, t_vec3 *origin)
{
    t_sky   *result;
    t_vec3   *tmp;
    t_vec3   *tmp2;
    t_vec3   *tmp3;

    result = (t_sky *)malloc(sizeof(t_sky));
    result->origin = origin;
    result->horizontal = vec_create(info->viewport_width, 0, 0);
    result->vertical = vec_create(0, info->viewport_height, 0);
    vec_div_const_apply(result->horizontal, 2.0);
    vec_div_const_apply(result->vertical, 2.0);
    tmp = vec_add(result->horizontal, result->vertical);
    tmp2 = vec_create(0, 0, info->focal_length);
    tmp3 = vec_add(tmp, tmp2);
    result->lower_left_corner = vec_sub(origin, tmp3);
    free(tmp);
    free(tmp2);
    free(tmp3);
    vec_mul_const_apply(result->horizontal, 2.0);
    vec_mul_const_apply(result->vertical, 2.0);
    return (result);
}

void    draw_sky(t_img_data *data, t_sky_info *info)
{
    t_sky   *my_sky;
    t_ray   *r;
    int     x;
    int     y;

    my_sky = init_sky(info, vec_create(0, 0, 0));
    my_sky->data = data;
    y = data->height;
    while (--y >= 0)
    {
        x = -1;
        while (++x < data->width)
        {
            r = cal_sky_ray(x, y, my_sky);
            data->img[x][y] = cal_sky_color(r);
            ray_free(r, FALSE);
        }
    }
    free_sky(my_sky, TRUE);
}

void    draw_s_sphere(t_img_data *data, t_sky_info *info, t_sphere *s)
{
    t_vec3   *color;
    t_sky   *my_sky;
    t_ray   *r;
    int     x;
    int     y;

    my_sky = init_sky(info, vec_create(0,0,0));
    my_sky->data = data;
    color = vec_create(1, 1, 0);
    y = data->height;
    while (--y >= 0)
    {
        x = -1;
        while (++x < data->width)
        {
            r = cal_sky_ray(x, y, my_sky);
            if (hit_s_sphere(s,r))
                data->img[x][y] = get_color_val(color);
            ray_free(r, FALSE);
        }
    }
    free(color);
    free_sky(my_sky, TRUE);
}

t_sky_info *init_sky_info(double viewport_width, double viewport_height,
                            double focal_length)
{
    t_sky_info  *result;

    result = (t_sky_info *)malloc(sizeof(t_sky_info));
    result->viewport_width = viewport_width;
    result->viewport_height = viewport_height;
    result->focal_length = focal_length;
    return (result);
}

t_img_data		*create_img_data(int width, int height)
{
	t_img_data	*result;
	int			h;
	int			w;

	result = (t_img_data *)malloc(sizeof(t_img_data));
	result->width = width;
	result->height = height;
	result->img = (int **)malloc(sizeof(int *) * width);
	w = -1;
	while ((++w) < width)
	{
		result->img[w] = (int *)malloc(sizeof(int) * height);
		h = -1;
		while ((++h) < height)
			result->img[w][h] = 0;
	}
	return (result);
}

void show_s_sphere()
{
    double  aspect_ratio;
    t_img_data  *img;
    t_sky_info  *info;
    t_sphere    *s;

    aspect_ratio = 16.0 / 9.0;
    img = create_img_data(400, (int)(400 / aspect_ratio));
    info = init_sky_info(2.0 * aspect_ratio, 2.0, 1.0);
    draw_sky(img, info);
    s = init_sphere(vec_create(0, 0, -1), 0.5);
    draw_s_sphere(img, info, s);
    mlx_show(img, "Simple sphere at Sky");
    free_sphere(s);
    free(info);
    free_img_data(img);
}
