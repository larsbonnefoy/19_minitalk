/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:30:55 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/13 13:28:15 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	conv_to_char(char *bin_str)
{
	int	chr;
	int	a;

	chr = 0;
	a = 0;
	while (bin_str[a] != '\0')
	{
		chr = chr * 2 + (bin_str[a] - '0');
		a++;
	}
	if (chr == 0)
		ft_printf("\n");
	ft_printf("%c", chr);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	int			calling_pid;
	static char	bit_str[BIT_AMNT + 1];
	int			index;

	context = NULL;
	calling_pid = info->si_pid;
	index = ft_strlen(bit_str);
	if (sig == SIGUSR1)
		bit_str[index] = '0';
	else if (sig == SIGUSR2)
		bit_str[index] = '1';
	if (index == BIT_AMNT - 1)
	{
		conv_to_char(bit_str);
		ft_bzero(bit_str, BIT_AMNT);
	}
	if (kill(calling_pid, SIGUSR1) == -1)
	{
		ft_printf("Could not send message back to client");
		exit(EXIT_FAILURE);
	}
}

void	sig_error(void)
{
	ft_printf("signal could not be handeled on server side\n");
	exit(EXIT_FAILURE);
}

int	main(void)
{
	t_sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	ft_printf("PID: %d\n", getpid());
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		sig_error();
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		sig_error();
	while (1)
		pause();
	return (0);
}
