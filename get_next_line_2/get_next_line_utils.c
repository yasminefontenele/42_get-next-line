/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mext_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:43:41 by yfontene          #+#    #+#             */
/*   Updated: 2023/06/02 09:43:41 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char *ft_strchr(char *str, int c)
{
	size_t i;

	if (!str)
		return(NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)str);
		return(&str[i]);
	}
	i = 0;
	while(str[i])
	{
		if(str[i] == (char)c)
			return(&str[i]);
		i++;
	}
	return(NULL);
}

char *ft_strjoin(char *start, char *end)
{
	char *join;

	if (!start)
	{
		start = (char *) malloc ( 1 * sizeof(char));
		start[0] = '\0';
	}
	if (!start || !end)
		return(NULL);
	join = (char *) malloc (sizeof(char) * ft_strlen(start) + ft_strlen(end) + 1);
	if (!join)
		return(NULL);
	join = ft_join(join, start, end);
	free (start);
	return(join);
}

char *ft_join(char *dest, char *str1, char *str2)
{
	size_t i;
	size_t j;

	i = 0;
	while (str1 && str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[i])
	{
		dest[ i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
	return(dest);
}
