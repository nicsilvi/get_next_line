/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:29:18 by smercado          #+#    #+#             */
/*   Updated: 2024/07/19 08:59:13 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>


int	main(void)
{
	char	*line1;
	char	*line2;
	char	*line3;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("example.txt", O_RDONLY);
	fd2 = open("example2.txt", O_RDONLY);
	fd3 = open("example3.txt", O_RDONLY);
	i = 1;

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

	while (line3 != NULL)
	{
		printf("num line fd1 [%d]: %s\n", i, line1);
		free(line1);
		printf("num line fd2 [%d]: %s\n", i, line2);
		free(line2);
		printf("num line fd3 [%d]: %s\n", i, line3);
		free(line3);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		i++;
	}
	free(line1);
	free(line2);
	free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
