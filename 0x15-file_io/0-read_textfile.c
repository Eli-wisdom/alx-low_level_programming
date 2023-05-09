#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and print stdout.
 * @filename: Name of  file.
 * @letters: Function should read and print.
 *
 * Return: File fail ilename is NULL - 0.
 *         O/w -the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, wr;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buf, letters);
	wr = write(STDOUT_FILENO, buf, r);
	if (o == -1 || r == -1 || wr == -1 || wr != r)
	{
		free(buf);
		return (0);
	}
	free(buf);
	close(o);

	return (wr);
}

