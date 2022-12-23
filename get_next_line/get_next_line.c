/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:21:09 by psaengha          #+#    #+#             */
/*   Updated: 2022/12/23 10:49:22 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer; //word according to buffer size
	char		*line; //the entire line (answer)
	char		*next;

	if (fd < 0)
		return (NULL);
	buffer = malloc_buffer(buffer); //malloc
	if (!buffer)
		return (NULL);
	line = NULL;
	next = read_line(buffer, fd); //return with empty string('\0') , '\0' != NULL
	while (next != NULL)
	{
		if (line == NULL)
			line = next;
		else
			line = ft_strjoin_free(line, next);
		if (ft_strchr(line, '\n'))
			return (line); //return final answer
		next = read_line(buffer, fd); //call read line again until we get the entire line
	}
	buffer = free_buffer(buffer); //finish then free
	return (line);
}

char	*malloc_buffer(char *buffer)
{
	if (buffer != NULL)
		return (buffer);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer != NULL)
		*buffer = '\0';
	return (buffer);
}

char	*read_line(char *buffer, int fd)
{
	char	*line;
	char	*next;
	int		n;

	line = NULL;
	if (ft_strlen(buffer) != 0) //will go in this case after the second attempt
	{
		next = ft_strchr(buffer, '\n');
		if (next != NULL)
		{
			*next = '\0';
			line = ft_strjoin(buffer, "\n"); //add buffer to line
			next_buffer(buffer, next + 1); //word after /n til end of buffer size
			return (line);
		}
		line = ft_strjoin(buffer, ""); //line = buffer then we create new buffer
		*buffer = '\0';
	}
	n = read(fd, buffer, BUFFER_SIZE); //read the file and put it in buffer
	if (n >= 0)
		*(buffer + n) = '\0';
	if (n > 0 && line == NULL)
		line = ft_strjoin("",""); //allocate with no leak
	return (line);
}

void	next_buffer(char *buffer, char *next)
{
	while (*next != '\0')
	{
		*buffer = *next;
		buffer++;
		next++;
	}
	*buffer = '\0';
}

char	*free_buffer(void *buffer)
{
	if (buffer != NULL)
		free(buffer);
	return (NULL);
}

//tester file
/* Hello world
this is a new line */

//buffer = 10
/* Hello worl 
d\nthis is */

//Answer = Hello world
//next = this is 

//main
/* int    main(void)
{
    int		fd;
    int		size_byte;
    char	str;

    str = (char)malloc(sizeof(char) * (BUFFER_SIZE + 1));

    fd = open("test", O_RDONLY);

    for (int i = 0; i < 3; i++)
    {
        str = get_next_line(fd);
        printf("line number %dth: %s", i, str);
        free(str);
    }
    close (fd);
} */
