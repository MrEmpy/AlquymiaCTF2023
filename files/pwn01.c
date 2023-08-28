#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[32];

int main()
{
        int fd;
        int len = 0;
        int num;
        scanf("%d", &num);
        fd = num - 0xcafe;
        len = read(fd, buf, 32);
        if(!strcmp("ALQUYMIA\n", buf))
        {
                printf("Parabens, pegue sua flag: ");
                printf("ALQ{?}\n");
        }
        return 0;

}