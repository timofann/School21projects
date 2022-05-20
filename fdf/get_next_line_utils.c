/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:02:49 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/02 00:02:51 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return ((char *)(void *)0);
	while (i < start && s[i])
		i++;
	if (i != start)
		len = 0;
	i = 0;
	while (s[start + i] && i < len)
		i++;
	len = i;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (p);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char			*s2;
	unsigned long	size;

	size = 0;
	while (s1[size])
		size++;
	s2 = (char *)malloc(size + 1);
	if (s2)
	{
		size = 0;
		while (s1[size])
		{
			s2[size] = s1[size];
			size++;
		}
		s2[size] = '\0';
	}
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !s2)
		return ((char *)(void *)0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	p = (char *)malloc((i + j + 1) * sizeof(char));
	if (!p)
		return (p);
	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}
