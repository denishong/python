#include <stdio.h>

void deleteData(int *ap, int *pcount, int index);

int main()
{

	
	deleteData(

	return 0;

}

void deleteData(int *ap, int *pcount, int index)
{

	int i;
	if(index < *pcount){
	(*pcount)--;
		for(i=index; i<*pcount; i++)
			ap[i]=ap[i+1];
		}else{
			return 0;
		}
}
