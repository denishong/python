#include <stdio.h>
#include <stdlib.h>

typedef struct _card{
	int key;
	struct _card *next;
}card;

card *head, *tail;

void init_card()
{
	head = (card *)malloc(sizeof(card));
	tail = (card *)malloc(sizeof(card));

	head->next = tail;
	tail->next = tail;
}

void insert_card(int key)
{
	card *t;
	t = (card *)malloc(sizeof(card *));

	t->key = key;

	t->next = head->next;
	head->next = t;
}

void list_card()
{
	card *p;
	
	p = head->next;

	while( p != tail)
	{
		printf("card list :%d \n", p->key);
		p = p->next;
	}
}

int main()
{
	init_card();
	insert_card(7);	
	insert_card(6);	
	insert_card(1);	
	insert_card(9);	
	insert_card(4);	
	insert_card(0);	
	insert_card(222);	

	list_card();
	return 0;
}
