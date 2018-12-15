#include <stdio.h>
typedef struct book{
   char name[40]; //도서명 
   char author[40]; //저자명
   char publisher[40]; //출판사
   char year_mon[20]; //발행연월
   int location; //서고위치
   char lent_check[1];   //대출여부
   char lent_day[20]; //대출일
}BOOK;

void changechar(char * str)
{
	char idx=0;

	while(str[idx] != '\0')
	{
		if(str[idx]=='.')
			str[idx]=' ';
	//	printf("%c", str[idx]);
		idx++;
	}
	return str;
}
int main(void)
{

	FILE * fp=fopen("DB.txt","rt");
	int ret,i,total;
	char type[2];	
	BOOK mybook;	
	char str[100];
	
	fgets(str, 100, fp);
	printf("%s\n", str);
	total=atoi(str);
	//printf("%d\n", total);
	for(i=0; i<1; i++)
	{
		//fgets(str, 100, fp);
		//fread((void*)&mybook,sizeof(mybook),1,fp);
		//printf("%s", mybook.book_name);
		fscanf(fp, "%s", type);
		
		switch(type[0])
		{	
		case '0': 
			fscanf(fp, "%s %s %s %s %d %s %s", mybook.name,mybook.author,mybook.publisher,mybook.year_mon,&(mybook.location),mybook.lent_check,mybook.lent_day);
			printf("%s %s %s %s %d %s %s", mybook.name,mybook.author,mybook.publisher,mybook.year_mon,mybook.location,mybook.lent_check,mybook.lent_day);
			break;
		default:
			printf("error not defined type!!\n");

		}
	//	changechar(mybook.book_name);

	//	printf("%s", mybook.book_name);
	}
	fclose(fp);

	return 0;
}
		
