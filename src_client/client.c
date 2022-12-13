/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:30:33 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/13 13:27:02 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	get_serv_pid(char *pid_str)
{
	int	pid;
	int	a;

	a = 0;
	while (pid_str[a] != '\0')
	{
		if (ft_strchr("0123456789", pid_str[a]) == NULL)
		{
			ft_printf("Unvalid char in PID\n");
			exit(EXIT_FAILURE);
		}
		a++;
	}
	pid = ft_atoi(pid_str);
	if (pid == -1 || pid == 0)
	{
		ft_printf("-1 and 0 are not valid PIDs in the scope of this project\n");
		exit(EXIT_FAILURE);
	}	
	return (pid);
}

void	check_params(int argc)
{
	if (argc != 3)
	{
		ft_printf("Wrong amount of params sent\n");
		exit(EXIT_FAILURE);
	}
}

void	sig_error(char *str)
{
	ft_printf("PID does not exist\n");
	free(str);
	exit(EXIT_FAILURE);
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		return ;
}

int	main(int argc, char **argv)
{
	t_sigaction	sa;
	int			serv_pid;
	char		*str_to_send;
	char		*init_str;
	char		*bin_str;

	sa.sa_flags = 0;
	sa.sa_handler = &signal_handler;
	check_params(argc);
	serv_pid = get_serv_pid(argv[1]);
	str_to_send = argv[2];
	init_str = malloc(sizeof(char));
	if (init_str == NULL)
		exit(EXIT_FAILURE);
	init_str[0] = '\0';
	bin_str = str_to_bin(str_to_send, init_str);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		sig_error(bin_str);
	send_sig(serv_pid, bin_str);
	free(bin_str);
}
