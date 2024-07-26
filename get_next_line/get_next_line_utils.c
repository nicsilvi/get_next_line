/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:20:26 by smercado          #+#    #+#             */
/*   Updated: 2024/07/19 08:28:37 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

static int	ft_lenconc(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strlen(s2) + 1);
	else if (s1 && !s2)
		return (ft_strlen(s1) + 1);
	else
		return (ft_strlen(s1) + ft_strlen(s2) + 1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_lenconc(s1, s2)));
	if (!str)
		return (ft_free(&s1), NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[j + i] = s2[j];
		j++;
	}
	str[j + i] = '\0';
	return (ft_free(&s1), str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ((char)c != s[i]))
		i++;
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		pos;

	pos = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char) * (1));
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (start < ft_strlen(s) && pos < len && s[start])
		ptr[pos++] = s[start++];
	ptr[pos] = '\0';
	return (ptr);
}
