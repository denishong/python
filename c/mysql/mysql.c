//#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <mysql.h>

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;
int fields, cnt;
char query[200];

struct student
{
    int rollno;
    char name[50];
    int p_marks, c_marks;
    double per;
    char grade;
}st;


FILE* fptr;

void write_student()
{
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password","studentdb", 0, NULL, 0)) {
        printf("%s\n", mysql_error(conn));
        exit(1);
    }
    mysql_set_character_set(conn, "euckr");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf_s("%d", &st.rollno);
    getchar(); // flushing buffer
    printf("\n\nEnter The Name of student ");
    gets_s(st.name, sizeof(st.name));
    printf("\nEnter The marks in physics out of 100 : ");
    scanf_s("%d", &st.p_marks);
    printf("\nEnter The marks in chemistry out of 100 : ");
    scanf_s("%d", &st.c_marks);
    st.per = (st.p_marks + st.c_marks) / 2.0;
    if (st.per >= 60)
        st.grade = 'A';
    else if (st.per >= 50 && st.per < 60)
        st.grade = 'B';
    else if (st.per >= 33 && st.per < 50)
        st.grade = 'C';
    else
        st.grade = 'F';
   
    sprintf_s(query, "insert into student values (%d, \"%s\", %d, %d, %d, \"%s\")", st.rollno, st.name, st.p_marks, st.c_marks, st.per, st.grade);
    mysql_query(conn, query);
    mysql_close(conn);
    printf("\n\nStudent Record Has Been Created.  Press any key.... ");
    _getch();
}

void display_all()
{
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "studentdb", 0, NULL, 0)) {
        printf("%s\n", mysql_error(conn));
        exit(1);
    }
    mysql_set_character_set(conn, "euckr");
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    printf("====================================================\n");
    printf("R.No.  Name       P   C   Ave   Grade\n");
    printf("====================================================\n");
 
    if (mysql_query(conn, "SELECT * FROM student"))
    {
        printf("%s\n", mysql_error(conn));
        exit(1);

    }

    res = mysql_store_result(conn);
    fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for (cnt = 0; cnt < fields; ++cnt)
            printf("%12s ", row[cnt]);
        printf("\n");
    }
   

    mysql_free_result(res);
    mysql_close(conn);

   

    _getch();
}


void display_sp(int n)
{
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "studentdb", 0, NULL, 0)) {
        printf("%s\n", mysql_error(conn));
        exit(1);
    }
    mysql_set_character_set(conn, "euckr");
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    printf("====================================================\n");
    printf("R.No.  Name       P   C   Ave   Grade\n");
    printf("====================================================\n");
    sprintf_s(query, "select * from student where rollno = %d", n);
    mysql_query(conn, query);
    mysql_free_result(res);
    mysql_close(conn);
    _getch();
}

void modify_student()
{
    int no, found = 0, i;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "studentdb", 0, NULL, 0)) {
        printf("%s\n", mysql_error(conn));
        exit(1);
    }
    mysql_set_character_set(conn, "euckr");
    system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student");
    scanf_s("%d", &no);
   

    printf("====================================================\n");
    printf("R.No.  Name       P   C   Ave   Grade\n");
    printf("====================================================\n");
    sprintf_s(query, "select * from student where rollno = %d", no);
    mysql_query(conn, query);
    res = mysql_store_result(conn);
    fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for (cnt = 0; cnt < fields; ++cnt)
            printf("%12s ", row[cnt]);
        printf("\n");
    }


    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf_s("%d", &st.rollno);
    getchar();
            printf("\n\nEnter The Name of student ");
            gets_s(st.name, sizeof(st.name));
            printf("\nEnter The marks in physics out of 100 : ");
            scanf_s("%d", &st.p_marks);
            printf("\nEnter The marks in chemistry out of 100 : ");
            scanf_s("%d", &st.c_marks);
            st.per = (st.p_marks + st.c_marks) / 2.0;
            if (st.per >= 60)
                st.grade = 'A';
            else if (st.per >= 50 && st.per < 60)
                st.grade = 'B';
            else if (st.per >= 33 && st.per < 50)
                st.grade = 'C';
            else
                st.grade = 'F';
            sprintf_s(query, "update student set rollno = %d where rollno = %d", st.rollno, no);
            mysql_query(conn, query);
            sprintf_s(query, "update student set name =  \"%s\" where rollno = %d", st.name, no);
            mysql_query(conn, query);
            sprintf_s(query, "update student set p_marks = %d where rollno = %d", st.p_marks, no);
            mysql_query(conn, query);
            sprintf_s(query, "update student set c_marks = %d where rollno = %d", st.c_marks, no);
            mysql_query(conn, query);
            sprintf_s(query, "update student set per = %d where rollno = %d", st.per, no);
            mysql_query(conn, query);
            sprintf_s(query, "update student set grade = \"%s\" where rollno = %d", st.grade, no);
            mysql_query(conn, query);
          printf("\n\n\t Record Updated");
       

    _getch();
}


void delete_student()
{
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "studentdb", 0, NULL, 0)) {
        printf("%s\n", mysql_error(conn));
        exit(1);
    }
    mysql_set_character_set(conn, "euckr");
    int no;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf_s("%d", &no);
    sprintf_s(query, "select * from student where rollno = %d", no);
    mysql_query(conn, query);
    mysql_close(conn);
   

    printf("\n\n\tRecord Deleted ..");
    _getch();
}

void main()
{
    char ch;
    int num;
    do
    {
        system("cls");
        printf("\n\n\t1.CREATE STUDENT RECORD");
        printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
        printf("\n\n\t3.SEARCH STUDENT RECORD ");
        printf("\n\n\t4.MODIFY STUDENT RECORD");
        printf("\n\n\t5.DELETE STUDENT RECORD");
        printf("\n\n\t6.EXIT");
        printf("\n\n\tPlease Enter Your Choice (1-6) ");
        ch = _getche();
        switch (ch)
        {
        case '1': system("cls");
            write_student();
            break;
        case '2': display_all();
            break;
        case '3': system("cls");
            printf("\n\n\tPlease Enter The roll number ");
            scanf_s("%d", &num);
            display_sp(num);
            break;
        case '4': modify_student(); break;
        case '5': delete_student(); break;
        case '6': break;
        default: printf("\a");
        }
    } while (ch != '6');
}
