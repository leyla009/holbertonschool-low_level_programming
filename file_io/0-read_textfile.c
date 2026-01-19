#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_wrote;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* 1. Open the file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* 2. Allocate buffer memory */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	/* 3. Read the file content */
	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 4. Write to standard output (STDOUT_FILENO is 1) */
	n_wrote = write(STDOUT_FILENO, buffer, n_read);

	/* 5. Handle write errors or partial writes */
	if (n_wrote == -1 || n_wrote != n_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 6. Cleanup and return success */
	free(buffer);
	close(fd);

	return (n_wrote);
}
