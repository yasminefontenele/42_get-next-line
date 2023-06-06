/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:45:23 by yfontene          #+#    #+#             */
/*   Updated: 2023/06/02 09:45:23 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
https://github.com/angealba/get_next_line42/blob/master/get_next_line_bonus.h
#include "get_next_line.h"

char *ft_readed_line(char *text)
{
	int i;
	char *line;

	if(!text || text[0])
		return (NULL);
	i = 0;
	while(text[i] && text[i] != '\n')
		i++;
	if(text[i] == '\n')
		i++;
	line = (char *) malloc (sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char *ft_get_line (char *text)
{
	char *new_text;
	int i;
	int j;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	i += (text[i] == '\n');
	new_text = (char *) malloc (sizeof(char) * (ft_strlen(text) - i + 1));
	if (!new_text)
		return (NULL);
	j = 0;
	while (text[i + j])
	{
		new_text[j] = text[i + j];
		j++;
	}
	new_text[j] = '\0';
	free(text);
	return (new_text);
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *text;
	int bytes_read;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(text, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (ft_readed_line(text));
}

/*#include <stdio.h>
int	main(void)
{
	char	*line;
	int		i; 
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("teste", O_RDONLY);
	fd2 = open("teste2", O_RDONLY);
	fd3 = open("teste3", O_RDONLY);
	i = 1;
	while (i < 4)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

#include <stdio.h>
int main(void) {
    char *filename = "teste.txt";

    // Verifica se o arquivo existe e está acessível para leitura
    if (access(filename, R_OK) == 0)
        printf("O arquivo %s está acessível para leitura.\n", filename);

	else 
        printf("O arquivo %s não está acessível para leitura ou não existe.\n", filename);
    return 0;
}*/
