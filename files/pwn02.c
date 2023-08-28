#include <stdio.h>
#include <stdlib.h>

int main()
{
        long int passw;
        long int passw_ = 0x9999dead9999;
        scanf("%ld", &passw);
        if(passw == passw_)
        {
                printf("Parabens, pegue sua flag: ");
                printf("ALQ{?}\n");
        }
        return 0;
}
