#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
           char *p1,*p2;
           int n;

           errno = 0;
           n = scanf("%m[0-9] %m[0-9]", &p1, &p2);
               printf("n: %d\n", n);
           if (n == 2) {
               printf("read: %s %s\n", p1,p2);
               free(p1);
               free(p2);
           } else if (errno != 0) {
               perror("scanf");
           } else {
               fprintf(stderr, "No matching characters\n");
           }

		   return 0;
}
