#include "string.h"
#include "../../includes/utils.h"

void	string_init(t_string *str)
{
	str->lenght = 0;
	str->size = 0;
	str->str = NULL;
}

void	string_destructor(t_string *str)
{
	str->lenght = 0;
	str->size = 0;
	if (str->str)
		free(str);
	str->str = NULL;
}


int	alloc_string(t_string *str1, size_t lenght)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (str1->lenght + lenght + 20));
	if (!str)
		return (FAILURE);
	str1->size = str1->lenght + lenght + 20;
	str1->lenght = str1->lenght + lenght;
	while (str1->str[i])
	{
		str[i] = str1->str[i];
		i++;
	}
	while (i < str1->size)
	{
		str[i++] = 0;
	}
	if (str1->str)
		free(str1->str);
	str1->str = str;
	return (SUCCESS);
}

int	append(t_string *str1, const char *str2)
{
	int		i;

	i = 0;
	if (!str2)
		return (SUCCESS);
	if (ft_strlen(str2) + str1->lenght > str1->size)
		if (alloc_string(str1, ft_strlen(str2)) == FAILURE)
			return (FAILURE);
	while (str2[i])
	{
		str1->str[++(str1->lenght)] = str2[i];
		i++;
	}
	return (SUCCESS);
}

void	reference_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	copy->lenght = to_copy.lenght;
	copy->size = to_copy.size;
	copy->str = to_copy.str;
}

int	profond_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	if (copy->append(copy, to_copy.str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int find(t_string *str, const char *str2)
{
	int	i;
	const int str2_len = ft_strlen(str2);

	if (!str->str || str2)
		return (-1);
	i = 0;
	while (i + str2_len < str->lenght)
	{
		if (ft_strncomp(&str->str[i], str2, str2_len) == 0)
		{
			str->str = &str->str[i];
			str->lenght = str->lenght - i;
			str->size = str->size - i;
			return (i);
		}
		i++;
	}
	return (-1);
}
