/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:57:33 by aybouatr          #+#    #+#             */
/*   Updated: 2024/11/14 11:53:47 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d_cpy;
	const unsigned char	*s_cpy;

	d_cpy = (unsigned char *)dst;
	s_cpy = (const unsigned char *)src;
	if (!s_cpy && !d_cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d_cpy[i] = s_cpy[i];
		i++;
	}
	return (dst);
}
