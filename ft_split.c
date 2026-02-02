/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:17:04 by adrvarga          #+#    #+#             */
/*   Updated: 2026/01/28 16:06:58 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static int	ft_count_words(const char *s, char c)
{
	int	q;
	int	i;

	q = 0;
	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[0] != c)
	{
		q = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			q++;
		i++;
	}
	return (q);
}

static int	ft_gimmi_all(const char *s, char c, int i, size_t *len)
{
	int	a;
	int	j;

	a = -1;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (s[j] != c)
		{
			a++;
			if (a == i)
			{
				while (s[j + *len] != 0 && s[j + *len] != c)
					(*len)++;
				return (j);
			}
			while (s[j] != '\0' && s[j] != c)
				j++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**omg;
	int		i;
	int		j;
	size_t	len;

	n = ft_count_words(s, c);
	i = 0;
	omg = malloc(sizeof(char *) * (n + 1));
	if (!omg)
		return (0);
	while (i < n)
	{
		len = 0;
		j = ft_gimmi_all(s, c, i, &len);
		omg[i] = ft_substr(s, j, len);
		if (!omg[i])
		{
			(ft_free_all(omg, i));
			return (NULL);
		}
		i++;
	}
	omg[i] = NULL;
	return (omg);
}
