/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:33:05 by aybouatr          #+#    #+#             */
/*   Updated: 2024/11/14 11:55:53 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d_cpy;
	const unsigned char	*s_cpy;

	if (dst > src)
	{
		d_cpy = (unsigned char *)dst;
		s_cpy = (const unsigned char *)src;
		while (len > 0)
		{
			len--;
			d_cpy[len] = s_cpy[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
