/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:54 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 15:57:49 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	index_s1;
	size_t	s1_leng;	
	char	*ptr_str;

	index_s1 = 0;
	s1_leng = ft_strlen(s1) + 1;
	ptr_str = malloc(sizeof(char) * (s1_leng));
	if (ptr_str == NULL)
		return (NULL);
	while (s1[index_s1])
	{
		ptr_str[index_s1] = s1[index_s1];
		index_s1++;
	}
	ptr_str[index_s1] = '\0';
	return (ptr_str);
}

static size_t	check_max_length(char const *org_str,
								unsigned int start, size_t len)
{
	if (len >= ft_strlen(org_str + start))
		return (ft_strlen(org_str + start));
	else
		return (len);
}

char	*ft_substr(char const *org_str, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub_string;

	if (org_str == NULL)
		return (NULL);
	index = 0;
	if (start >= ft_strlen(org_str))
		return (ft_strdup(""));
	len = check_max_length(org_str, start, len);
	sub_string = malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	while (index < len && org_str[index + start])
	{
		if (org_str[index + start] == '\'')
		{
			start++;
			continue ;
		}
		sub_string[index] = org_str[index + start];
		index++;
	}
	sub_string[index] = '\0';
	return (sub_string);
}

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (char)(c))
			return ((char *)(s + index));
		index--;
	}
	return (NULL);
}
