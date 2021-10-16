#ifndef PARSE_H
# define PARSE_H

/*
** -----------------------------------------------------------------------------
** P A R S E
** -----------------------------------------------------------------------------
*/

typedef	struct	s_object_condition
{
	t_ambient	*a;
	t_camera	*c;
	t_light		*l;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}				t_object_condition;

t_bool		parse(char *line, int fd, t_object_condition *ob);
int			identifier(char *line);
t_bool		get_ambient(t_object_condition *ob, char *line);
void		get_camera(t_object_condition **ob);
void		get_light(t_object_condition **ob);
void		get_plane(t_object_condition **ob);
void		get_sphere(t_object_condition **ob);
void		get_cylinder(t_object_condition **ob);

/*
** -----------------------------------------------------------------------------
** E R R O R
** -----------------------------------------------------------------------------
*/

void		e_file_param(void);
void		e_file_open(void);
void		e_file_read(int fd);
void		e_identifier(void **ptr, int fd);
void		e_condition_value(void **ptr,int fd);

#endif
