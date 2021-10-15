#ifndef PARSE_H
# define PARSE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

typedef int	t_bool;

/*
** -----------------------------------------------------------------------------
** G N L _ M A C R O S
** -----------------------------------------------------------------------------
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

/*
** -----------------------------------------------------------------------------
** M A C R O S
** -----------------------------------------------------------------------------
*/

# define ERROR -1
# define SUCCESS 1
# define END 0
# define TRUE 1
# define FALSE 0
# define VALID 0
# define INVALID 1

/*
** -----------------------------------------------------------------------------
** I D E N T I F I E R
** -----------------------------------------------------------------------------
*/
# define BLANK 0
# define AMBIENT 1
# define CAMERA 2
# define LIGHT 3
# define SPHERE 4
# define PLANE 5
# define CYLINDER 6

/*
** -----------------------------------------------------------------------------
** F T F U N C T I O N
** -----------------------------------------------------------------------------
*/

int			get_next_line(int fd, char **line);
size_t			ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(char *s1);
t_bool		dalloc(void **ptr, size_t cnt, size_t n);
void		free_ptr(void **ptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** -----------------------------------------------------------------------------
** P A R S E
** -----------------------------------------------------------------------------
*/

t_bool		parse(char *line, int fd);
int			identifier(char *line);

/*
** -----------------------------------------------------------------------------
** E R R O R
** -----------------------------------------------------------------------------
*/

void		e_file_param(void);
void		e_file_open(void);
void		e_file_read(int fd);
void		e_identifier(void **ptr, int fd);

#endif
