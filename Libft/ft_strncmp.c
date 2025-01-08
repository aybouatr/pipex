/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:36:16 by aybouatr          #+#    #+#             */
/*   Updated: 2024/10/22 11:36:20 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t len, int isfree)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while ((i < len) && (s1[i]) && (s1[i] == s2[i]))
		i++;
	if (isfree == 1)
		free(s1);
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
