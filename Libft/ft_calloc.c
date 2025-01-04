/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:47:02 by aybouatr          #+#    #+#             */
/*   Updated: 2024/11/14 14:41:49 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t len)
{
	void	*res;

	if ((len) && (count > (__SIZE_MAX__ / len)))
		return (NULL);
	res = malloc(count * len);
	if (!res)
		return (NULL);
	ft_bzero(res, (count * len));
	return (res);
}
