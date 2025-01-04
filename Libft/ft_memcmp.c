/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:24:29 by aybouatr          #+#    #+#             */
/*   Updated: 2024/10/22 15:24:32 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t					i;
	unsigned char			*ptr1;
	unsigned char			*ptr2;

	ptr1 = (unsigned char *)pointer1;
	ptr2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		i++;
	}
	return (0);
}
