/*
*	---------
*	GET_LINE
*	---------
*	Extracts the line (ending in either line break and `\0` or only `\0` in EOF)
*	from static variable.
*	PARAMETERS
*	#1. The pointer to the cumulative static variable from previous runs of get_next_line.
*	RETURN VALUES
*	The string with the full line ending in a line break (`\n`) + (`\0`).
*	-------------
*	NEW_LEFT_STR
*	-------------
*	Stores in the cumulative static variable the new updated variable with whatever
*	is left from the original, minus the line extracted.
*	PARAMETERS
*	#1. The pointer to the cumulative static variable from previous runs of get_next_line.
*	RETURN VALUES
*	The new updated string with whatever is left from the original static, minus the
*	line extracted.
*/

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *temp, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!temp)
	{
		temp = (char *)malloc(1 * sizeof(char));
		temp[0] = '\0';
	}
	if (!temp || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (temp)
		while (temp[++i] != '\0')
			str[i] = temp[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(temp) + ft_strlen(buff)] = '\0';
	free(temp);
	return (str);
}
