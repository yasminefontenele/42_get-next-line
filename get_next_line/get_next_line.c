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

#include "get_next_line.h"

char *ft_read(int fd, char *buffer)
{
	int ret_read; // return of read function into buffer (number of bytes read) 

	ret_read = read(fd, buffer, BUFFER_SIZE); // read into buffer from fd (file descriptor) 
	if (ret_read == -1)
		return(NULL);
	buffer[ret_read] = '\0';
	return(buffer);
}

char *ft_get_line(char *buffer)
{
	char *line; // pointer to the first \n in buffer
	char *tmp; // pointer to the rest of buffer after \n

	if (!buffer)
		return(NULL);
	line = ft_strchr(buffer, '\n');
	if (!line)
		return(NULL);
	tmp = ft_strdup(line + 1);
	if (!tmp)
		return(NULL);
	*line = '\0';
	return(tmp);
}	

char *ft_get_buffer(char *buffer)
{
	char *tmp; // pointer to the rest of buffer after \n

	if (!buffer)
		return(NULL);
	tmp = ft_strdup(buffer);
	if (!tmp)
		return(NULL);
	free(buffer);
	return(tmp);
}

char *get_next_line(int fd)
{
	static char *buffer; // static variable to keep the buffer between calls
	char *line; // pointer to the line to be returned
	char *tmp; // pointer to the rest of buffer after \n

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	buffer = ft_read(fd, buffer); // read into buffer from fd (file descriptor)
	if (!buffer)
		return(NULL);
	line = ft_get_line(buffer); // get the line from buffer and replace \n with \0 in buffer to get the line 
	if (!line) // if there is no \n in buffer, return the whole buffer
	{
		tmp = (char *)ft_strdup(buffer); // duplicate buffer to tmp to return it
		free(buffer); // free buffer to avoid memory leaks 
		buffer = NULL;// set buffer to NULL to avoid memory leaks
		return(tmp);
	}
	tmp = ft_get_buffer(buffer); // get the rest of buffer after \n
	buffer = NULL; // set buffer to NULL to avoid memory leaks
	return(line);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	int fd; // file descriptor
	char *line; // pointer to the line to be returned

	if (argc != 2) // check if there is only one argument
		return(0);
	fd = open(argv[1], O_RDONLY); // open the file in read only mode and get the file descriptor
	while ((line = get_next_line(fd))) // while there is a line to be returned from the file descriptor
	{
		printf("%s\n", line); // print the line
		free(line);
	}
	free(line);
	close(fd);
	return(0);
}*/

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
}*/

#include <stdio.h>
int main(void) {
    char *filename = "teste.txt";

    // Verifica se o arquivo existe e está acessível para leitura
    if (access(filename, R_OK) == 0)
        printf("O arquivo %s está acessível para leitura.\n", filename);
	else 
        printf("O arquivo %s não está acessível para leitura ou não existe.\n", filename);
    return 0;
}