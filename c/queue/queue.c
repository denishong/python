#include <stdio.h>
#include <stdlib.h>

#define QUE_SIZE 5

/*
   큐 예제
*/
void Push(int nData);
int Pop();

int *pQue = NULL;

int main()
{
 /*
   메모리 할당
 */
pQue = (int*)malloc((sizeof(int)) * QUE_SIZE);

 /*
   초기화
 */
 for (int i = 0; i < QUE_SIZE; i++)
 {
 pQue[i] = NULL;
 }

 Push(100);
 Push(200);
 Push(300);
 Push(400);
 Push(500);
 Push(300);


 printf("%d\n", Pop());
 printf("%d\n", Pop());
 printf("%d\n", Pop());
 printf("%d\n", Pop());
 printf("%d\n", Pop());


 return 0;
}

void Push(int nData)
{
 int nCount = 0;
 for (int i = 0; i < QUE_SIZE; i++)
 {
  if (pQue[i] == NULL)
  {
	printf("Queue is full \n");
   break;
  }
  nCount++;
 }
 if (nCount != QUE_SIZE)
 {
  pQue[nCount] = nData;
 }
 
}

int Pop()
{
 int nCount = 0;
 int nResult = 0;
 for (int i = 0; i < QUE_SIZE; i++)
 {
  if (pQue[i] != NULL)
  {
   break;
  }
  nCount++;
 }
 if (nCount != QUE_SIZE)
 {
  nResult = pQue[nCount];
  pQue[nCount] = NULL;
 }

 for(int i=0; i < QUE_SIZE; i++)
 {

  pQue[i] = pQue[i+1];
 }

 pQue[QUE_SIZE-1] = NULL;

 return nResult;
}
