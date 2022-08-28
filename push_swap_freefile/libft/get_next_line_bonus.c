/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:40:19 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 17:53:25 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newmem(char *mem)
{
	char	*newmem;
	size_t	i;
	int		j;

	i = 0;
	while (mem[i] != '\0' && mem[i] != '\n')
		i++;
	if (mem[i] == '\0')
	{
		free(mem);
		return (NULL);
	}
	newmem = (char *)malloc(sizeof(char) * (ft_strlen_g(mem) - i + 1));
	if (newmem == NULL)
		return (NULL);
	i++;
	j = 0;
	while (mem[i] != '\0')
		newmem[j++] = mem[i++];
	newmem[j] = '\0';
	free(mem);
	return (newmem);
}

char	*ft_gnl(char *mem)
{
	char	*line;
	int		i;

	i = 0;
	if (mem[i] == '\0')
		return (NULL);
	while (mem[i] != '\0' && mem[i] != '\n')
		i++;
	if (mem[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\0' && mem[i] != '\n')
	{
		line[i] = mem[i];
		i++;
	}
	if (mem[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_readjoin(int fd, char *mem)
{
	char	*buff;
	int		readnew;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	readnew = 1;
	while (readnew != 0 && !(ft_strchr_g(mem, '\n')))
	{
		readnew = read(fd, buff, BUFFER_SIZE);
		if (readnew == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readnew] = '\0';
		mem = ft_strjoin_g(mem, buff);
	}
	free(buff);
	return (mem);
}

int	get_next_line(int fd, char **line)
{
	static char	*mem[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	mem[fd] = ft_readjoin(fd, mem[fd]);
	if (mem[fd] == NULL)
		return (0);
	*line = ft_gnl(mem[fd]);
	mem[fd] = ft_newmem(mem[fd]);
	if (*line == NULL)
		return (0);
	return (1);
}
