//
// Created by Alim MINADZHIEV on 4/5/18.
//

#include "fdf.h"

int 		ft_hextoi(char *str)
{
	int 	ret;

	ret = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'F')
			ret = ret | (*str - 55);
		else if (*str >= 'a' && *str <= 'f')
			ret = ret | (*str - 87);
		else if (*str >= '0' && *str <= '9')
			ret = ret | (*str - 48);
		str++;
		if (*str)
			ret = ret << 4;
	}
	return (ret);
}
