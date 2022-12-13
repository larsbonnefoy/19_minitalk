/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:09:56 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/13 13:27:04 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include"../19_libft/libft.h"
# include"../19_ft_printf/ft_printf.h"
# include"signal.h"
# define BIT_AMNT 8

typedef struct sigaction	t_sigaction;
char						*str_to_bin(char *str, char *bin_str);
void						send_sig(int pid, char *bin_str);

#endif
