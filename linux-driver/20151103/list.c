#include <stdio.h>
struct list_head {
	struct list_head *next, *prev;
};

void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

#define list_entry( ptr, type, member )             \
		((type *)((char*)ptr -  (unsigned long)&((type*)0)->member))

//--------------------------------------------------------------
struct task_struct
{
	int pid;
	struct list_head tasks;
	struct list_head children;
};  // __attribute__((packed));

void display( struct list_head *head)
{
	struct list_head *temp;
	struct task_struct *p;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head;  temp = temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printf("<->[%d]", p->pid );
	}
	printf("<->[head]\n");
	getchar();
}
int main()
{
	int i;
	struct task_struct nodes[7];
	printf("sizeof(struct task_struct)=%lu\n", sizeof(struct task_struct));
	LIST_HEAD(head);
	display( &head );
	for(i=0; i<7; i++ )
	{
		nodes[i].pid = 1000+i;
		list_add( &nodes[i].tasks, &head );
		display( &head );
	}

	return 0;
}
