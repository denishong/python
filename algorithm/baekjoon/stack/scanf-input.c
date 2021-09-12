#include <stdio.h>
#include <string.h>

int main()
{
    char input[200];

    while( fgets(input, sizeof(input), stdin) != NULL)
    {
        fputs(input, stdout);
        printf( "%ld\n", strlen(input));
    }
        //printf("%s", input);

    return 0;
}
