/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:14:38 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/13 12:35:58 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	rev_bin(char *tmp_str, char *rtn_str, int len)
{
	int	pos_from_end;
	int	pos_from_beg;

	pos_from_end = BIT_AMNT - 1;
	pos_from_beg = 0;
	while (len >= 0)
	{
		rtn_str[pos_from_end] = tmp_str[pos_from_beg];
		len --;
		pos_from_end --;
		pos_from_beg ++;
	}
}

char	*char_to_bin(int chr)
{
	char	*rtn_str;
	char	tmp_str[BIT_AMNT];
	int		a;

	ft_memset(tmp_str, 48, BIT_AMNT);
	rtn_str = malloc(sizeof(char) * BIT_AMNT + 1);
	if (rtn_str == NULL)
		return (NULL);
	ft_memset(rtn_str, 48, BIT_AMNT);
	a = 0;
	while (chr != 0)
	{
		tmp_str[a] = (chr % 2) + 48;
		chr = chr / 2;
		a++;
	}
	rev_bin(tmp_str, rtn_str, a);
	rtn_str[BIT_AMNT] = '\0';
	return (rtn_str);
}

char	*str_to_bin(char *str, char *bin_str)
{
	int		a;
	char	*bin_char;

	a = -1;
	while (str[++a] != '\0')
	{
		bin_char = char_to_bin(str[a]);
		if (bin_char == NULL)
		{
			free(bin_str);
			exit (1);
		}
		bin_str = ft_strjoinf(bin_str, bin_char);
		free(bin_char);
		if (bin_str == NULL)
			exit(EXIT_FAILURE);
	}	
	return (bin_str);
}
