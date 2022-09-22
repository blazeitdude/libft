/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:40:52 by aalien            #+#    #+#             */
/*   Updated: 2021/11/09 18:37:56 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_free(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	count(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*new_str(char const *s, char c)
{
	int		i;
	char	*dst;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, i + 1);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		strs_len;
	char	**dst;

	if (!s)
		return (NULL);
	strs_len = count(s, c);
	dst = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < strs_len)
	{
		while (s[0] == c)
			s++;
		dst[i] = new_str(s, c);
		if (!(dst[i]))
		{
			return (ft_free(dst));
		}
		s = s + ft_strlen(dst[i]);
	}
	dst[i] = 0;
	return (dst);
}

/*
static int		words(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static char		**memory_giver(char const *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	if ((res = (char **)malloc(sizeof(char*) * (words(str, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if ((res[j++] = (char *)malloc(sizeof(char) * letters + 1)) == NULL)
				return (NULL);
	}
	res[j] = 0;
	return (res);
}

char			**ft_split(char const *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		str_number;
	int		size;

	if (str == NULL)
		return (NULL);
	size = words(str, c);
	res = memory_giver(str, c);
	if (res == NULL)
		return (NULL);
	i = 0;
	str_number = 0;
	while (str_number < size)
	{
		while (str[i] == c && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i])
			res[str_number][j++] = str[i++];
		res[str_number][j] = '\0';
		str_number++;
	}
	return (res);
}*/