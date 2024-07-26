/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:29:18 by smercado          #+#    #+#             */
/*   Updated: 2024/07/17 15:15:00 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*next_line;
	int		c;

	c = 0;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);

		next_line = get_next_line(fd);
		while (next_line != NULL)
		{
			c++;
			printf("num line: %d, line: %s", c, next_line);
			free(next_line);
			next_line = get_next_line(fd);
		}
		free(next_line);
	}
	else
	{
		printf("faltan argumento, pon un archivo");
	}
	close(fd);
	return (0);
}
