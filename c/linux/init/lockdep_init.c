#include <stdio.h>

#define MAX_LOCKDEP_KEYS_BITS  13
#define CLASSHASH_BITS      (MAX_LOCKDEP_KEYS_BITS - 1)
#define CLASSHASH_SIZE      (1UL << CLASSHASH_BITS)

int main()
{
 	int i = CLASSHASH_SIZE;
 printf("%d\n", i); 

return 0;
}
