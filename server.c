/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:34:44 by jihong            #+#    #+#             */
/*   Updated: 2022/06/15 17:51:31 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_bit(int *bit, int *chr)
{
	*bit = 8;
	*chr = 0;
}

void	test_handler(int sig, siginfo_t *info, void *(v))
{
	static int	bit;
	static int	chr;
	static int	client_pid;

	(void)v;
	if (client_pid != info -> si_pid && bit != 8)
		init_bit(&bit, &chr);
	if (sig == SIGUSR1)
		chr += 1 << --bit;
	else if (sig == SIGUSR2)
		--bit;
	if (bit == 0)
	{
		if (chr != 0)
			write(1, &chr, 1);
		else
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR1);
		}
		init_bit(&bit, &chr);
	}
	client_pid = info -> si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_sigaction = &test_handler;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
