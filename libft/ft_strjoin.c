/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.luanda>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:17:15 by jmiguel           #+#    #+#             */
/*   Updated: 2024/05/16 14:33:01 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		tam;

	if (s1 && s2)
		tam = (size_t)ft_strlen(s1) + ft_strlen(s2);
	else if (s1)
		tam = (size_t)ft_strlen(s1);
	else if (s2)
		tam = (size_t)ft_strlen(s2);
	else
		return (NULL);
	result = (char *)malloc((tam + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1)
		result = ft_strcpy(result, (char *)s1);
	else
		result = ft_strcpy(result, (char *)s2);
	if (s1 && s2)
		result = ft_strcat(result, (char *)s2);
	return (result);
}
