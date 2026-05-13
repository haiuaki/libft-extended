/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juljin <juljin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:30:53 by juljin            #+#    #+#             */
/*   Updated: 2026/05/12 11:50:34 by juljin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "memory.h"

char	**ft_arraydup(char **array)
{
	char	**new_array;
	size_t	len;
	size_t	i;

	if (!array)
		return (NULL);
	len = 0;
	while (array[len])
		len++;
	new_array = ft_calloc(len + 1, sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			ft_free_array(new_array);
			return (NULL);
		}
		i++;
	}
	return (new_array);
}
