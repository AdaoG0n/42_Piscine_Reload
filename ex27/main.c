/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:11:31 by adamarqu          #+#    #+#             */
/*   Updated: 2024/10/15 14:11:33 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c, int std)
{
	write(std, &c, 1);
}

void	ft_putstr(char *str, int std)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], std);
}

int	read_and_display(int fd)
{
	int		ret;
	char	temp[1];

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, temp, 1);
		if (ret == -1)
		{
			ft_putstr("Cannot read file.\n", 2);
			return (0);
		}
		if (ret > 0)
			ft_putchar(temp[0], 1);
	}
	return (1);
}

int	open_and_read_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (0);
	}
	if (!read_and_display(fd))
	{
		close(fd);
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n", 2);
	else if (argc == 2)
	{
		if (!open_and_read_file(argv[1]))
			return (0);
	}
	else
		ft_putstr("Too many arguments.\n", 2);
	return (0);
}
