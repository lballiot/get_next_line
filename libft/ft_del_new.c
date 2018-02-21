#include "libft.h"

void ft_del_new(char **str, int i)
{
	free(*str);
	*str = ft_strnew(i);
}
