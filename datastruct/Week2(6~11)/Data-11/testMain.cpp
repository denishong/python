#include <stdio.h>
#include <string.h>
#include "singlyLinkedlist.h"
BOOL dataFileLoad(List *lp); // 데이터 파일내의 데이터를 리스트에 저장
/*----------------------------------------------------------------------------------
  함수명 : main()
----------------------------------------------------------------------------------*/
int main()
{
	// TODO

	getchar();
	return 0;
}

/*----------------------------------------------------------------------------------
  함수명 : dataFileLoad()
----------------------------------------------------------------------------------*/
BOOL dataFileLoad(List *lp) // 데이터 파일내의 데이터를 리스트에 저장
{
	FILE *fp;
	char word[80];
	Node *resp;

	fp=fopen("d:\\data\\flower.txt", "rt");
	if(fp==NULL)
		return FALSE;

	while(fscanf(fp, "%s", word)!=EOF)
	{
		resp=searchNode(lp, word);  // 링크드리스트 내에 해당 단어가 있는 가 검사
		if(resp == NULL)     // 검사한 단어가 링크드리스트 내에 없으면 단어 새로 등록
			addLast(lp, word);
	}
	fclose(fp);
	return TRUE;
}
