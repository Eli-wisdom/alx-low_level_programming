#include "main.h"

/**
 * create_file - Create a file.
 * @filename: Name of the file to create.
 * @text_content: String to write to the file.
 *
 * Return: fail -1.
 *         Otherwise 1.
 */
int create_file(const char *filename, char *text_content)
{
	int o, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(o, text_content, len);

	if (o == -1 || wr == -1)
		return (-1);

	close(o);

	return (1);
}

