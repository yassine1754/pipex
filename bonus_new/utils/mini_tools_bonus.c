/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:26:45 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 15:57:25 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*word_searsh_in_start(char *word, char **to_searsh)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(word);
	while (to_searsh[i] && ft_strncmp(word, to_searsh[i], len) != 0)
		i++;
	if (to_searsh[i] && ft_strncmp(word, to_searsh[i], len) == 0)
		return (&(to_searsh[i][len]));
	return (NULL);
}

char	**free_strings(char **strings)
{
	int	i;

	i = 0;
	if (strings == NULL)
		return (NULL);
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (NULL);
}

size_t	ft_strlcpy(char *dst,
		const char *src,
		size_t dst_size)
{
	size_t	src_ind;
	size_t	result;

	result = ft_strlen(src);
	src_ind = 0;
	if (dst_size == 0)
		return (result);
	while (src[src_ind] && (src_ind < dst_size - 1))
	{
		dst[src_ind] = src[src_ind];
		src_ind++;
	}
	dst[src_ind] = '\0';
	return (result);
}

size_t	ft_strlcat(char *dst,
					const char *src, size_t dst_size)
{
	size_t	index;
	size_t	src_ind;
	size_t	result;

	if (dst == NULL && dst_size == 0)
		return (ft_strlen(src));
	src_ind = 0;
	result = ((ft_strlen(dst) + ft_strlen(src)));
	index = ft_strlen(dst);
	if (index >= dst_size)
		return (dst_size + ft_strlen(src));
	while (((index + src_ind) < (dst_size - 1)) && src[src_ind])
	{
		dst[index + src_ind] = src[src_ind];
		src_ind++;
	}
	dst[index + src_ind] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2, char macro)
{
	size_t	total_leng;
	char	*concatenation_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	total_leng = ft_strlen(s1) + ft_strlen(s2) + 1;
	concatenation_str = malloc(total_leng * (sizeof(char)));
	if (concatenation_str == NULL)
		return (NULL);
	ft_strlcpy(concatenation_str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(concatenation_str, s2, total_leng);
	if (macro == 1)
		free((char *)(s1));
	return (concatenation_str);
}
