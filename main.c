#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MODE 0666
#define BUF_SIZE 8192

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Target & destination files are required\n");
        exit(1);
    }

    int src, dst, in, out;
    char buf[BUF_SIZE];

    src = open(argv[1], O_RDONLY); 
    if (src < 0)
    {
        printf("Source file doesnot exist!\n");
        exit(2);
    }

    dst = creat(argv[2], MODE);
    if (dst < 0)
    {
        printf("Something went wrong!\n");
        exit(3);
    }

    while (1)
    {
        in = read(src, buf, BUF_SIZE);
        if (in <= 0) break;
        out = write(dst, buf, in);
        if (out <= 0) break;
    }

    close(src); close(dst);
    return 0;
}