#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "apple banana";

    fgets(str, sizeof(str), stdin); // 입력: pear(엔터)

    str[strlen(str)-1] = 'N';

    printf("%s", str);

    return 0;
}
