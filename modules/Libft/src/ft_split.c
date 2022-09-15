/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:26:25 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 14:18:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_split_len(char const *s, char c);
void	**ft_split_free(char **split_all, long unsigned index);
char	**ft_split_malloc(char const *s, char c, \
		char **split_all, long unsigned int split_len);

char	**ft_split(char const *s, char c)
{
	char				**split_all;
	long unsigned int	split_len;

	if (s == NULL)
		return (NULL);
	split_len = ft_split_len(s, c);
	split_all = (char **)malloc(sizeof(char *) * (split_len + 1));
	if (split_all == NULL)
		return (NULL);
	split_all[split_len] = NULL;
	split_all = ft_split_malloc(s, c, split_all, split_len);
	return (split_all);
}

size_t	ft_split_len(char const *s, char c)
{
	size_t	split_len;
	int		flag;

	flag = 1;
	split_len = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (flag)
				split_len++;
			flag = 0;
		}
		else
			flag = 1;
		s++;
	}
	return (split_len);
}

void	**ft_split_free(char **split_all, long unsigned int index)
{
	while (index-- > 0)
		free(split_all[index]);
	free(split_all);
	return (NULL);
}

char	**ft_split_malloc(char const *s, char c, \
		char **split_all, long unsigned int split_len)
{
	char				*split_word;
	long unsigned int	split_word_len;
	long unsigned int	index;

	split_word_len = 0;
	index = 0;
	while (index < split_len)
	{
		if (s[split_word_len] == c || s[split_word_len] == '\0')
		{
			if (split_word_len > 0)
			{
				split_word = ft_calloc(split_word_len + 1, sizeof(char));
				if (split_word == NULL)
					return ((char **)ft_split_free(split_all, index));
				ft_strlcpy(split_word, s, split_word_len + 1);
				split_all[index++] = split_word;
			}
			s += split_word_len + 1;
			split_word_len = 0;
		}
		else
			split_word_len++;
	}
	return (split_all);
}
