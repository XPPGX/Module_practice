#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define DEMO_DEV_NAME "/dev/my_demo_dev"

int main()
{
    char buffer[64];
    int fd;
    int ret;
    size_t len;
    char message[] = "Testing the virtual FIFO device";
    char *read_buffer;

    len = sizeof(message);

    //fd, is a file description and is a int.
    
    //[WRITE]
    //open device by its device file name
    fd = open(DEMO_DEV_NAME, O_RDWR);
    if(fd < 0)
    {
        printf("open device %s failed\n", DEMO_DEV_NAME);
        return -1;
    }

    //write by the module we wrote
    ret = write(fd, message, len);
    if(ret != len)
    {
        printf("cannot write on device %d, ret = %d", fd, ret);
        return -1;
    }
    close(fd);

    //[READ]
    read_buffer = malloc(2*len);
    memset(read_buffer, 0, 2*len);
    //open device by its device file name
    fd = open(DEMO_DEV_NAME, O_RDWR);
    if(fd < 0)
    {
        printf("open device %s failed\n", DEMO_DEV_NAME);
        return -1;
    }
    //read by the module we wrote
    ret = read(fd, read_buffer, 2*len);
    printf("read %d bytes\n", ret);
    printf("read buffer = %s\n", read_buffer);

    close(fd);
    return 0;
}