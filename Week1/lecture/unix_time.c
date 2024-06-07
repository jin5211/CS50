#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t seconds;
    seconds = time(NULL);
    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    return 0;
}