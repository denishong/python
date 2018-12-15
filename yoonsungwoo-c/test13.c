#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "banana";
    char str2[] = "apple mango";

    strncpy(str2, str1, strlen(str1)+1);

    printf("%s", str2);

    return 0;
}
