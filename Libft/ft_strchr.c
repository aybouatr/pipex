/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:30:20 by aybouatr          #+#    #+#             */
/*   Updated: 2024/10/22 10:30:24 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	while (*str)
	{
		if (*str == (char )search_str)
			return ((char *)str);
		str++;
	}
	if ((char )search_str == 0)
		return ((char *)str);
	return (NULL);
}
