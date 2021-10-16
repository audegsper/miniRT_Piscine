#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

/*
** -----------------------------------------------------------------------------
** T Y P E _ D E F I N I T I O N S
** -----------------------------------------------------------------------------
*/

typedef int				t_bool;
# define FALSE 0
# define TRUE 1

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
** F T F U N C T I O N
** -----------------------------------------------------------------------------
*/

int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(char *s1);
t_bool		dalloc(void **ptr, size_t cnt, size_t n);
void		free_ptr(void **ptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_bool		is_blank(char c);
t_bool		ft_isdigit(int c);
t_bool		is_endl(const char *s);
void		*ft_memset(void *s, int c, size_t n);

#endif
