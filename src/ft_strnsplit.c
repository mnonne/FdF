/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:40:51 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/29 18:40:53 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		word_count(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (n);
}

static char		*word_fill(char const *s, char c)
{
	char	*ret;
	char	*p_s;
	char	*p_e;
	char	*p_r;

	p_s = (char *)s;
	while (*s && *s != c)
		s++;
	p_e = (char *)s;
	if (!(ret = (char *)malloc(p_e - p_s + sizeof(char))))
		return (NULL);
	p_r = ret;
	while (*p_s && *p_s != c)
		*p_r++ = *p_s++;
	*p_r = '\0';
	return (ret);
}

char			**ft_strnsplit(char const *s, char c, int *tab_s)
{
	char	**tab;
	int		i;

	if (!s || !(tab = (char **)malloc(sizeof(tab) * (word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(tab[i] = word_fill(s, c)))
			{
				free(tab);
				return (NULL);
			}
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	tab[i] = NULL;
	*tab_s = i;
	return (tab);
}
