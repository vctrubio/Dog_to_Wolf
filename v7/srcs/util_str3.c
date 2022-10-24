#include "../include/header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] == s2[index] && index < n - 1 && s1[index] != '\0')
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int		my_strnstr(char *str, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		while (str[i])
		{
			if (str[i] == '.')
				return (i);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				return (i);
			i++;
		}
	}
	return (0);
}

int		ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	i_l;

	index = 0;
	i_l = 0;
	while (big[index] && index < len)
	{
		i_l = 0;
		while (big[index + i_l] == little[i_l] && (index + i_l) < len)
		{
			if (little[i_l + 1] == '\0')
				return (index);
			i_l++;
		}
		index++;
	}
	return (0);
}
