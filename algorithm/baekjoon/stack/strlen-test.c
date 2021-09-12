#include <stdio.h>
#include <string.h>
#define MAX_NAME_LEN 50
int main()
{
    char name[MAX_NAME_LEN+1] = "hello";
    printf("%s 길이: %ld\n",name, strlen(name));
    return 0;
}
