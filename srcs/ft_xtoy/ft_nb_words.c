
#include "ft_xtoy.h"

size_t		nb_words(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			s++;
			res++;
			while (*s != c && *s)
				s++;
		}
	}
	return (res);
}