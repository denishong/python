#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE  21
#define CORP_SIZE  31
#define TEL_SIZE   16
#define REC_SIZE   (NAME_SIZE + CORP_SIZE + TEL_SIZE)

typedef struct _card
{
    char name[NAME_SIZE];
    char corp[CORP_SIZE];
    char tel[TEL_SIZE];
    struct _card *next;
} card;

card *head, *tail;

void init_card(void)
{
    head = (card*)malloc(sizeof(card));
    tail = (card*)malloc(sizeof(card));
    head->next = tail;
    tail->next = tail;
}

void input_card(void)
{
    card *t;
    t = (card*)malloc(sizeof(card));

    printf("\nInput namecard menu : ");
    printf("\n   Input name -> ");
        fgets(t->name,21,stdin);
    printf("\n   Input corporation -> ");
        fgets(t->corp,31,stdin);
    printf("\n   Input telephone number -> ");
        fgets(t->tel,16,stdin);

    t->next = head->next;  /* insert at first */
    head->next = t;
}

void print_card(card *t, FILE *f)
{
    fprintf(f, "\n%-20s    %-30s    %-15s", t->name, t->corp, t->tel);
    printf("\n%-20s    %-30s    %-15s", t->name, t->corp, t->tel);
}

void print_header(FILE *f)
{
    fprintf(f, "\nName                    "
                 "Corporation                      "
                 "Telephone number");
    fprintf(f, "\n--------------------    "
                 "-----------------------------    "
                 "----------------");
}

void load_cards(char *s)
{
    FILE *fp;
    card *t;
    card *u;
    if ((fp = fopen(s, "rb")) == NULL)
        {
        printf("\n    Error : %s is not exist.", s);
        return;
        }
    t = head->next;
    while (t != tail)
        {
        u = t;
        t = t->next;
        free(u);
        }
    head->next = tail;
    while (1)
        {
        t = (card*)malloc(sizeof(card));
        if (!fread(t, REC_SIZE, 1, fp))   /* if file end... */
            {
            free(t);
            break;
            }
        t->next = head->next;
        head->next = t;
        }
    fclose(fp);
}

void save_cards(char *s)
{
    FILE *fp;
    card *t;
    if ((fp = fopen(s, "wb")) == NULL)
        {
        printf("\n    Error : Disk write failure.");
        return;
        }
    t = head->next;
    while (t != tail)
        {
        //fwrite(t, REC_SIZE, 1, fp);
    		fprintf(fp, "\n%-20s    %-30s    %-15s", t->name, t->corp, t->tel);
        t = t->next;
        }
    fclose(fp);
}


card *search_card(char *s)
{
    card *t;
    t = head->next;
    while (strcmp(s, t->name) !=0 && t != tail)
        t = t->next;
    if (t == tail)
        return NULL;  /* not found */
    else
        return t;
}
int main(void)
{
	char *fname = "namecard.dat";
	char name[NAME_SIZE];

	card *t = malloc(sizeof(card));

#if 0
	strcpy(t->name , "denis");
	strcpy(t->corp , "LGE");
	strcpy(t->tel , "0109999999");
#endif

	fgets(t->name, 20, stdin);
	fgets(t->corp, 20, stdin);
	fgets(t->tel, 20, stdin);
	
	print_header(stdout);


	fprintf(stdout, "\n%-20s     %-30s   %-15s \n", t->name, t->corp, t->tel);

}
