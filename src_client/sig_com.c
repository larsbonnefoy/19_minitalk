/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:01:11 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/13 13:03:21 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	kill_error(char *bin_str)
{
	ft_printf("Signal could not be sent to server\n");
	free(bin_str);
	exit(EXIT_FAILURE);
}

void	send_eol(int pid, char *bin_str)
{
	int	a;

	a = 0;
	while (a < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			kill_error(bin_str);
		pause();
		a++;
	}
}

void	send_sig(int pid, char *bin_str)
{
	int	a;

	a = 0;
	while (bin_str[a] != '\0')
	{
		if (bin_str[a] == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
				kill_error(bin_str);
		}
		else
		{	
			if (kill(pid, SIGUSR2) == -1)
				kill_error(bin_str);
		}
		a++;
		pause();
	}
	send_eol(pid, bin_str);
}
