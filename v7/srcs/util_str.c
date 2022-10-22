#include "../include/header.h"

static int	count(char const *s, char c)
{
	unsigned int	index;
	unsigned int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0')
			count++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	index;
	unsigned int	index_a;
	unsigned int	index_tab;
	char			**tab;

	index_a = 0;
	index_tab = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!(tab))
		return (NULL);
	tab[count(s, c)] = 0;
	while (*s && *s == c)
		s++;
	while (s[index_a])
	{
		index = index_a;
		while (s[index_a] && s[index_a] != c)
			index_a++;
		tab[index_tab++] = ft_substr(s, index, index_a - index);
		while (s[index_a] && s[index_a] == c)
			index_a++;
	}
	return (tab);
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

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	index_len;

	index_len = ft_strlen(s);
	index = 0;
	if (len > (index_len - start))
		len = index_len - start;
	if (start >= index_len)
	{
		sub = (char *)malloc(sizeof(*sub));
		*sub = 0;
		return (sub);
	}
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (s[start + index] != '\0' && len > 0)
	{
		sub[index] = s[start + index];
		index++;
		len--;
	}
	sub[index] = '\0';
	return (sub);
}

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
