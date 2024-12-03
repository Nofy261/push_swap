#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != 32 && str[i] != 9)  && (str[i + 1] == 32 || str[i + 1] == 9 || str[i + 1] == '\0'))
				count++;
		i++;
	}
	return (count);
}

void	*free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	fill_result(char *new, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 32)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
}

void	set_mem(char **result, char *str)
{
	int	count;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[j])
	{
		count = 0;
		while (str[j + count] && str[j + count] != 32)
			count++;
		if (count > 0)
		{
			result[i] = malloc(sizeof(char) * (count + 1));
			if (!result[i])
				(free_all(result));
			fill_result(result[i], (str + j));
			i++;
			j = j + count;
		}
		else
			j++;
	}
	result[i] = 0;
}

char	**ft_split(char *s)
{
	int	words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	set_mem(result, s);
	return (result);
}
#include <stdio.h>

int main(void)
{
	char s[] = "Bonjour Les Amis";
	char **result;

	int i = 0;
	result = ft_split(s);
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);//free case par case 
		i++;
	}
	free(result);
}