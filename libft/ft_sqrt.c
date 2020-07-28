/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:06:43 by aenstein          #+#    #+#             */
/*   Updated: 2019/11/24 11:34:05 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(const int nb)
{
	int nb2;

	if (nb < 0)
		return (0);
	nb2 = 0;
	while (nb2 * nb2 < nb)
		nb2++;
	return (nb2);
}
