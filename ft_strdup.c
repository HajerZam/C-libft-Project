/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:00:53 by halzamma          #+#    #+#             */
/*   Updated: 2024/12/19 14:00:53 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	copy = (char *)malloc(len + 1);
	i = 0;
	if (!copy)
		return (NULL);
	while (i < len)
		copy[i] = s1[i];
	copy[len] = '\0';
	return (copy);
}
