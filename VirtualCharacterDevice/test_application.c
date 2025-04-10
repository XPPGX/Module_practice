#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEMO_DEV_NAME "/dev/my_demo_dev"

int main()
{
    char buffer[64];
    int fd;

    //"open" function will return the file control code, and return -1 if it failed
    fd = open(DEMO_DEV_NAME, O_RDONLY); 
    if(fd < 0)
    {
        printf("open device %s failed\n", DEMO_DEV_NAME);
        return -1;
    }

    read(fd, buffer, 64);
    close(fd);

    return 0;
}