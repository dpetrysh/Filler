/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:32:18 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/08 16:32:19 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	get_chardig(int n, int big)
{
	if (n > 9)
	{
		if (big)
			n = n - 10 + 'A';
		else
			n = n - 10 + 'a';
		return (n);
	}
	else
	{
		n = n + '0';
		return (n);
	}
}

static	int		get_rank(long long n, int base)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while ((n = ABS(n / base)) != 0)
		i++;
	return (i);
}

char			*ft_itoa_base(long long n, int base, int big)
{
	int		rank;
	char	*str;

	rank = get_rank(n, base);
	str = (char *)ft_memalloc(sizeof(char) * (rank + 1));
	if (n < 0)
		str[0] = '-';
	str[rank] = '\0';
	while (str[--rank] != '-' && rank != -1)
	{
		str[rank] = get_chardig(ABS(n % base), big);
		n = n / base;
	}
	return (str);
}
