#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_read_to_temp(int fd, char *temp);
char	*ft_get_line(char *temp);
char	*ft_new_temp(char *temp);

#endif
