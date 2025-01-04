/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:21:05 by aybouatr          #+#    #+#             */
/*   Updated: 2024/10/25 11:21:08 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_include(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	skiipset_atbeg(char const *set, char const *s1)
{
	int	i;

	i = 0;
	while (is_include(set, s1[i]))
		i++;
	return (i);
}

static int	skiipset_atend(char const *set, char const *s1, int index)
{
	int	i;
	int	counter;

	i = ft_strlen(s1) - 1;
	counter = 0;
	while (index < i && is_include(set, s1[i]))
	{
		i--;
		counter++;
	}
	return (counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		skiip_beg;
	int		skiip_end;
	char	*str;
	int		i;

	skiip_beg = skiipset_atbeg(set, s1);
	skiip_end = skiipset_atend(set, s1, skiip_beg);
	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	str = (char *)malloc(((ft_strlen(s1) - (skiip_beg + skiip_end)) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	while ((unsigned int)(i + skiip_beg) < ((unsigned int)(ft_strlen(s1)
			- skiip_end)))
	{
		str[i] = s1[skiip_beg + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
