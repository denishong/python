
#include<stdio.h>

void deleteData(int *ap, int *pcount, int index);
void insertData(int *ap, int *pcount, int index, int data);
void printArray(int *ap, int cnt);
//---------------------------------------------------
int main()
{
	int num[10] = {1,2,3,4,5,6,7};
	int count=7;
	printArray(num, count);
	insertData(num, &count, 4, 9);
	printArray(num, count);

	deleteData(num, &count, 3);
	printArray(num, count);

	getchar();
	return 0;
}
//---------------------------------------------------
void insertData(int *ap, int *pcount, int index, int data)
{
	int i;
	if (index <= *pcount) {
		for (i = *pcount; i > index; i--) {
			ap[i] = ap[i - 1];
		}
		ap[index] = data;
		(*pcount)++;
	}
	else {
		return;
	}
}
//---------------------------------------------------
void deleteData(int *ap, int *pcount, int index)
{
	int i;
	if (index < *pcount) {
		(*pcount)--;
		for (i = index; i < *pcount; i++) {
			ap[i] = ap[i + 1];
		}
	}
	else {
		return;
	}
}
//---------------------------------------------------
void printArray(int *ap, int cnt)
{
	int i;
	printf("¿¿¿ :  ");
	for (i = 0; i < cnt; i++) {
		printf("%5d", *ap++);
	}
	printf("\n");
}


