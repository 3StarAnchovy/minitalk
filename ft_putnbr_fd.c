/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:28:33 by jihong            #+#    #+#             */
/*   Updated: 2022/06/15 17:30:17 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	rec_nb(int div, int mod, char str, int fd)
{
	mod = div % 10;
	div /= 10;
	if (div != 0)
		rec_nb(div, mod, str, fd);
	str = '0' + mod;
	write(fd, &str, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		str = '\0';
		rec_nb(n, 0, str, fd);
	}
	else
		rec_nb(n, 0, '\0', fd);
}
