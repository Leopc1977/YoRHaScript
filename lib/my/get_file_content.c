#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

long long get_file_size(char const *filepath)
{
    struct stat *st = malloc(sizeof(struct stat));
    if (st == NULL) return (-1);

    long long size = (-1);
    if (stat(filepath, st) == 0) size = st->st_size;

    free(st);

    return (size);
}

char *get_file_content(char const *filepath)
{
    long long size = get_file_size(filepath);
    char *buffer = malloc(get_file_size(filepath) + 1);
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) return (NULL);

    read(fd, buffer, size);
    buffer[size] = '\0';

    close(fd);

    return (buffer);
}
