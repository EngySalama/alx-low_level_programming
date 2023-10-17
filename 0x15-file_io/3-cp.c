#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void exit_with_error(int code, const char *message) {
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(code);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        exit_with_error(97, "Usage: cp file_from file_to");
    }

    const char *file_from = argv[1];
    const char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        exit_with_error(98, "Can't read from file");
    }

    int fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        exit_with_error(99, "Can't write to file");
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_to, buffer, bytes_read) == -1) {
            exit_with_error(99, "Can't write to file");
        }
    }

    if (bytes_read == -1) {
        exit_with_error(98, "Can't read from file");
    }

    if (close(fd_from) == -1) {
        exit_with_error(100, "Can't close fd");
    }

    if (close(fd_to) == -1) {
        exit_with_error(100, "Can't close fd");
    }

    return 0;
}

