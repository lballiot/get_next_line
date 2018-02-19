/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:30:23 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/19 15:46:32 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <assert.h>
#include <libc.h>
#include "libft/libft.h"

/*
** MAIN
*/

/////////////////////////
// MY MAIN             //
/////////////////////////

int main(int ac, char **av)
{
	int i;
    char *line;
    int fd;
	
    (void) ac;
    fd = open(av[1], O_RDONLY);
    line = ft_strnew(120);
    while (get_next_line(fd, &line) == 1)
    {
		if (line)
			ft_putendl(line);
        line = ft_strnew(900);
    }
    return (0);
}
