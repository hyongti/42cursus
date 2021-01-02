/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:43:42 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/31 16:57:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t		ft_strlen(const char *s)
// {
// 	int		i;

// 	i = 0;
// 	while (*s)
// 	{
// 		i++;
// 		++s;
// 	}
// 	return (i);
// }

// char		*ft_strchr(const char *s, int c)
// {
// 	int		idx;

// 	idx = 0;
// 	while (s[idx])
// 	{
// 		if ((s[idx] == (char)c))
// 			return ((char *)(s + idx));
// 		idx++;
// 	}
// 	if (c == 0)
// 		return ((char *)(s + idx));
// 	return (NULL);
// }

char		*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (s[idx] && idx < n)
	{
		result[idx] = s[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

// char		*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	idx1;
// 	size_t	idx2;
// 	size_t	len;
// 	char	*result;

// 	idx1 = 0;
// 	idx2 = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
// 		return (NULL);
// 	while (s1[idx1])
// 	{
// 		result[idx1] = s1[idx1];
// 		idx1++;
// 	}
// 	while (s2[idx2])
// 	{
// 		result[idx1 + idx2] = s2[idx2];
// 		idx2++;
// 	}
// 	result[idx1 + idx2] = '\0';
// 	return (result);
// }
