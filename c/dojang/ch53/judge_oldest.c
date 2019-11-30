#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

int main()
{
    struct Person *p[5];

	
    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
		p[i] = malloc(sizeof(struct Person));

	scanf("%s %d %s %d %s %d %s %d %s %d",
				p[0]->name,&p[0]->age,p[1]->name,&p[1]->age,p[2]->name,&p[2]->age,
				p[3]->name,&p[3]->age,p[4]->name,&p[4]->age );

		int oldest = p[0]->age;
    for (int i = 0; i < sizeof(p) / sizeof(struct Person *)-1; i++)
		{	
		if( oldest < p[i+1]->age)
			oldest = p[i+1]->age;
		}

    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
		{
		if(oldest == p[i]->age)
			printf("%s\n", p[i]->name);
		}

    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        free(p[i]);
    }

    return 0;
}
