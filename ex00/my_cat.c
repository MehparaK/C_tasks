#include <unistd.h>
#include <fcntl.h>
#define Buffer_size 4096

int main(int argc, char **argv)
{
    int fd;
    ssize_t bytes_read;
    char buffer[Buffer_size];

    for (int i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            continue;
        }

        while ((bytes_read = read(fd, buffer, Buffer_size)) > 0)
        {
            write(STDOUT_FILENO, buffer, bytes_read);
        }

        close(fd);
    }
    return 0;
}