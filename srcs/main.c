/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2020/01/15 12:30:54 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#define FT(x)int main(){ /* code */ }
#include <stdio.h>

unsigned char	cypher(char *data, int index, int size)
{
	(void)size;
	return (data[index]);
}
unsigned char	uncypher(char *data, int index, int size)
{
	(void)size;
	return (data[index]);
}

void	save_data(char *data, int size)
{
	int			i;

	printf ("const unsigned char data[] = {");
	i = -1;
	while (++i < size)
	{
		if ((i % 8) == 0)
			printf ("\n\t/* %0#6x */",i);
		if (i == size - 1)
			printf ("   %0#4x", data[i]);
		else
			printf ("   %0#4x,", data[i]);
	}
	printf ("\n};\n");
}

void	save_code(char *data, int size)
{
	int			i;

	printf ("\n");
	i = -1;
	while (++i < size)
		printf ("%c", data[i]);
}

int		main(int ac, char **av)
{
	char			*data;
	int				size;

	if (ac > 1)
	{
		size = ft_get_file(av[1], &data);
		save_data(data, size);
		save_code(data, size);
	}
	return (0);
}
