/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:24 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/27 15:00:06 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	free_line(char *str)
{
	if (str[0] == '\0')
	{
		free (str);
		return (1);
	}
	return (0);
}

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[j++] = s1[i];
	free (s1);
	i = -1;
	while (s2[++i] != '\0')
		str[j++] = s2[i];
	str[j] = '\0';
	free (s2);
	return (str);
}

char	*substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	*ft_calloc(size_t elemCount, size_t elementSize)
{
	void	*tab;
	char	*array;
	size_t	i;

	i = 0;
	tab = NULL;
	if (elemCount * elementSize == 0 || elemCount <= SIZE_MAX / elementSize)
		tab = (void *)malloc(elemCount * elementSize);
	if (!tab)
		return (NULL);
	array = (char *) tab;
	while (i < elemCount * elementSize)
	{
		array[i] = 0;
		i++;
	}
	return (tab);
}
