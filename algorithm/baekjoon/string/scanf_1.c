#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
           char *p;
		   int num1,num2,total=0;
           int n;

           errno = 0;
           n = scanf("%*", &num1, &num2);
               printf("total: %d\n", num1+num2);
               printf("n: %d\n", n);
           if (n == 1) {
		   		p = &num1;
               printf("read: %s\n", p);
               free(p);
           } else if (errno != 0) {
               perror("scanf");
           } else {
               fprintf(stderr, "No matching characters\n");
           }

		   return 0;
}
