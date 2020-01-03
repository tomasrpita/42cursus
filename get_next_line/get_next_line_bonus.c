#include "get_next_line_bonus.h"
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
    char        *tmp;

    p_n = check_remainder(remainder, line);
    if (read(fd, NULL, 0) < 0)
     return (-1);
    mem_read = 1; 
    while(!p_n && (mem_read = read(fd, buf, BUFFER_SIZE)))
    {
        buf[mem_read] = '\0';
        if ((p_n = ft_strchr(buf, '\n')))
        {
            *p_n = '\0';
            ++p_n;
            if (fd != 0)
                remainder = ft_strdup(p_n);
        }
        tmp = *line;
        *line = ft_strjoin_up(*line, buf);
        free(tmp);
    }
	return ((mem_read || (ft_strlen(*line) && ft_strlen(remainder))) ? 1 : 0);
}

int main ()
{
    int fd;
    char *line;
    int    i;
    int j;
    
    line = 0;
    j = 1;
    fd = open("alphabet", O_RDONLY);
    while ((i = get_next_line(fd, &line)) > 0)
    {
        printf("|%s\n", line);
        ++j;
    }
    printf("|%s\n", line);
    printf("%d", j);
    free(line);
    close(fd);
    return (0);
}