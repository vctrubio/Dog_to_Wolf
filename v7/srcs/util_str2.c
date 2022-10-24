#include "../include/header.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	index;

	index = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (index < ft_strlen(s))
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index;
	unsigned int	index_b;
	char			*str;

	index = 0;
	index_b = 0;
	str = (char *)malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (str == NULL)
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (s2[index_b])
	{
		str[index + index_b] = s2[index_b];
		index_b++;
	}
	str[index + index_b] = '\0';
	return (str);
}

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	unsigned int	index;

	res = 0;
	sign = 1;
	index = 0;
	while (str[index] && ((str[index] >= 9 && str[index] <= 13)
			|| (str[index] == 32)))
		index++;
	if (str[index] == '-')
	{
		if (str[index + 1] == '-' || str[index + 1] == '+')
			return (0);
		sign = -1;
		index++;
	}
	if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	return ((int)(res * sign));
}