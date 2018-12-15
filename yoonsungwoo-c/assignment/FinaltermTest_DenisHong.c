#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book{
   char name[40]; //도서명 
   char author[40]; //저자명
   char publisher[40]; //출판사
   char year_mon[20]; //발행연월
   int location; //서고위치
   char lent_check[1];   //대출여부
   char lent_day[20]; //대출일
}BOOK;

typedef struct magazine{
	char name[40]; //도서명
	char type[10];//유형(life,sports,science,arts)
	char publisher[40]; //출판사
	char first_publish[40]; //최초 발행연월
	char lately_publish[40]; //최근 발행연월
	int location; //서고위치
}MAGAZINE;
 
typedef struct newspaper{
	char name[40]; //도서명
	char publisher[40]; //신문사 명
	char first_publish[40]; //최초 발행연월
	char lately_publish[40]; //최근 발행연월
	int location; //서고위치
}NEWSPAPER;

int changechar(char * str)
{
   char idx=0;
	while( str[idx] != '\0')
	{
      if(str[idx]=='.')
         str[idx]=' ';
   // printf("%c", str[idx]);
      idx++;  
   }
   return (int *)str;
}

int print_book(char *doc, BOOK book)
{
	changechar(book.name);
	changechar(book.author);
	changechar(book.publisher);
	//printf("%s %s\n", doc, book.name);
	if(!strcmp(doc,book.name))
	{
	printf("도서종류 : 책\n");
	printf("도서명 : %s\n",book.name);
	printf("저자: %s\n", book.author);
	printf("출판사: %s\n", book.publisher);
	printf("발행일: %s\n", book.year_mon);
	printf("서고위치:#%d\n", book.location);
	printf("대출여부: %s\n", book.lent_check);
	printf("대출일: %s\n", book.lent_day);
	}else{
	//printf("not completed!!!!\n");
	}
	return 0;
}

int print_magazine(char *doc, MAGAZINE magazine)
{
	changechar(magazine.name);
	changechar(magazine.publisher);
	//printf("%s %s\n", doc, magazine.name);
	if(!strcmp(doc,magazine.name))
	{
	printf("도서종류 : 잡지\n");
	printf("유형: %s\n",magazine.type);
	printf("잡지명 : %s\n",magazine.name);
	printf("출판사: %s\n", magazine.publisher);
	printf("발행일: %s\n", magazine.first_publish);
	printf("서고위치:#%d\n", magazine.location);
	}else{
	//printf("not completed!!!!\n");
	}
	return 0;
}

int print_newspaper(char *doc, NEWSPAPER newspaper)
{
	changechar(newspaper.name);
	changechar(newspaper.publisher);
	//printf("%s %s\n", doc, newspaper.name);
	if(!strcmp(doc,newspaper.name))
	{
	printf("도서종류 : 신문\n");
	printf("도서명 : %s\n",newspaper.name);
	printf("신문사명: %s\n", newspaper.publisher);
	printf("발행일: %s\n", newspaper.first_publish);
	printf("서고위치:#%d\n", newspaper.location);
	}else{
	//printf("not completed!!!!\n");
	}
	return 0;
}
int SearchDB(char * doc)
{
   FILE * fp=fopen("DB.txt","rt");
   int ret,i,total,check=0;
   char type[2];  
   BOOK mybook;   
	MAGAZINE mymagazine;
	NEWSPAPER mynewspaper;

   char str[100];
 
	/*total book number*/ 
   fgets(str, 100, fp);
   //printf("%s\n", str);
   total=atoi(str);
   
	/*searching book according to book type*/ 
	for(i=0; i<total; i++)
   {
      fscanf(fp, "%s", type);
      switch(type[0])
      {       
      case '0': 
         fscanf(fp, "%s %s %s %s %d %s %s", mybook.name,mybook.author,mybook.publisher,mybook.year_mon,&(mybook.location),mybook.lent_check,mybook.lent_day);
         print_book(doc,mybook);
         break;
      case '1': 
         fscanf(fp, "%s %s %s %s %s %d", mymagazine.name,mymagazine.type,mymagazine.publisher,mymagazine.first_publish,mymagazine.lately_publish,&(mymagazine.location));
         print_magazine(doc,mymagazine);
         break;
      case '2': 
         fscanf(fp, "%s %s %s %s %d", mynewspaper.name,mynewspaper.publisher,mynewspaper.first_publish,mynewspaper.lately_publish,&(mynewspaper.location));
        	print_newspaper(doc,mynewspaper);
         break;
      }
   }
	
	fclose(fp);
   return 0;
}

int main(void)
{
	char doc[30];

	for(int check=0; check<5; check++)
	{	
		/*input book name*/
		printf("book name?: "); 
		gets(doc);
	
		SearchDB(doc);//searching book
	}	

	return 0;
}
