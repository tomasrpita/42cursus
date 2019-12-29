#include "get_next_line.h"
#include <fcntl.h>

static char *check_remainder(char *remainder, char **line)
{
    char        *p_n;

    p_n = NULL;
    if (remainder)
    {
        if ((p_n = ft_strchr(remainder, '\n')))
        {
            *p_n = '\0';
            *line = ft_strdup(remainder);
            ft_strcpy(remainder, ++p_n);
        }
        else
        {
           *line = ft_strdup(remainder);
           ft_memset(remainder, '\0', ft_strlen(remainder));
        }
    }
    else
        *line = ft_strnew(1);
    return (p_n);
}


int get_next_line(int fd, char **line)
{
    static char *remainder;
	char        buf[BUFFER_SIZE + 1];
    ssize_t     mem_read;
    char        *p_n;

    p_n = check_remainder(remainder, line);
    while(!p_n && (mem_read = read(fd, buf, BUFFER_SIZE)))
    {
        buf[mem_read] = '\0';
        if ((p_n = ft_strchr(buf, '\n')))
        {
            *p_n = '\0';
            ++p_n;
            remainder = ft_strdup(p_n);
        }
        *line = ft_strjoin_up(*line, buf);
    }
	return ((mem_read || ft_strlen(remainder) || ft_strlen(*line)) ? 1 : 0);
}
