/* 
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there's nothing more to read, it returns NULL.
*	----------------------------------------------------------------------------
*	AUXILIARY FUNCTIONS
*	-------------------
*	READ_TO_LEFT_STR
*	-----------------
*	DESCRIPTION
*	Takes the opened file descriptor and saves on a "buff" variable what readed
*	from it. Then joins it to the cumulative static variable for the persistence
*	of the information.
*	PARAMETERS
*	#1. A file descriptor.
*	#2. The pointer to the cumulative static variable from previous runs of
*	get_next_line.
*	RETURN VALUES
*	The new static variable value with buffer joined for the persistence of the info,
*	or NULL if error.
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	while (temp[i] && temp[i] != '\n')//i diventa = indice di \n
		i++;
	if (!temp[i])//se non avevo letto nulla (EOF o error) oppure in temp non c'è \n (perchè ho raggiunto EOF)
	{
		free(temp);
		return (NULL);
	}
	new_temp = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i));//devo provare a togliere il cast del malloc //tolto +1
	if (!new_temp)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		new_temp[j++] = temp[i++];
	new_temp[j] = '\0';
	free(temp);
	return (new_temp);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*line;

	i = 0;
	if (!temp[i])//se la stringa è vuota  //non serve
		return (NULL);
	while (temp[i] && temp[i] != '\n')//raggiungo \n (i diventa l'indice di \n), così so quanto deve essere lunga line
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));//alloco line. +2 perché aggingo \n e \0
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_to_temp(int fd, char *temp)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(temp, '\n') && rd_bytes != 0)//finché non incontro il \n oppure non raggiungo EOF
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)//controlli
		return (0);
	temp = ft_read_to_temp(fd, temp);//leggo e salvo ciò che ho letto diverse volte, arrivando a \n, in temp
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);//ottiene line da temp
	temp = ft_new_temp(temp);//toglie line da temp
	printf("new_temp: %s\n", temp);
	return (line);
}

/*
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	close(fd);
	return (0);
}
*/
