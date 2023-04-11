#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_f(int fd);
char *create_bf(char *file);


/**
 * create_bf - Allocates 1024 bytes
 * @file: Were the filename buffer is stoed
 *
 * Return: A pointer to the newly-allocated buffer
 */
char *create_bf(char *file)
{
	char *bf;

	bf = malloc(sizeof(char) * 1024);

	if (bf == NULL){
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (bf);
}

/**
 * close_f - Close descriptors
 * @fd: The descriptor to be closed.
 */
void close_f(int fd)
{
	int c;
	c = close(fd);

	if (c == -1){
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file
 * @argc: The  of arguments to the program
 * @argv: An array of pointers
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fr, to;
    int r,w;
	char *bf;

	if (argc != 3){
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bf = create_bf(argv[2]);
	fr = open(argv[1], O_RDONLY);
	r = read(fr, bf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || r == -1){
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(bf);
			exit(98);
		}
		w = write(to, bf, r);
		if (to == -1 || w == -1){
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(bf);
			exit(99);
		}
		r = read(fr, bf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(bf);
	close_f(fr);
	close_f(to);

	return (0);
}
