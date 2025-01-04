/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <aybouatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:55:23 by aybouatr          #+#    #+#             */
/*   Updated: 2024/10/23 18:55:27 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter_nb(int n)
{
	long	nb;
	int		counter;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		counter++;
	}
	while (nb)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

static char	*get_zero(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*get_min(void)
{
	char	*str;
	char	*ss;
	int		i;

	ss = "-2147483648";
	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	while (ss[i])
	{
		str[i] = ss[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len_nbr;
	char	*str;

	if (n == 0)
		return (get_zero());
	if (n == -2147483648)
		return (get_min());
	len_nbr = counter_nb(n);
	str = (char *)malloc((len_nbr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len_nbr--] = '\0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n)
	{
		str[len_nbr--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
