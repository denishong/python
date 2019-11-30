#include <stdio.h>
struct node
{
	int a;
	int b;
	int c;
};

int main()
{
	struct node a ={ 1,2,3};
	//....
	int *p = &a.b;
	struct node *temp;
	temp = (struct node *)((char*)p -  (unsigned long)&((struct node*)0)->b) ;
	printf("%d, %d, %d\n", temp->a, temp->b, temp->c );
}
