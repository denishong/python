#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//균형잡힌 세상(스택)
char stack[102] = { 0, };
int top = -1;

void init_stack() {    //스택 초기화 함수
   for (int i = 0; i < 101; i++) {
      stack[i] = 0;
   }
   top = -1;
}

void push(char data) {   //'(' 나 '[' push
   top++;
   stack[top] = data;
}

int pop(char data) {    //만약 top에 있는 괄호와 입력받은 괄호가 같으면 pop하고 1 리턴, , 아니면 0 
   if (top > -1) {
      if ((stack[top] == '[' && data == ']') || (stack[top] == '(' && data == ')')) {
         stack[top] = 0;
         top--;
         return 1;
      }
      else return 0;
   }
   else return 0;
   
   
}

int main(void) {
   while (1) {
      int result = 0;
      char arr[101] = { 0, };
      fgets(arr, sizeof(arr), stdin);   //문자열 입력
      
      if (arr[0] == '.') break;

      for (int i = 0; i < strlen(arr); i++) {    //문자열 탐색하면서 괄호 나오는지 확인할 루프
         if (arr[i] == '(' || arr[i] == '[') {
            push(arr[i]);
         }
         else if (arr[i] == ')' || arr[i] == ']') {
            if (pop(arr[i]) == 0) {    
               result++;    //이 문장이 실행되면 무조건 그냥 균형 안맞는 문장임.
            }
         }
      }
      if (top == -1 && result == 0) {
         printf("yes\n");
      }
      if (top != -1 || result != 0) {
         printf("no\n");
      }
      init_stack();    //스택 초기화
   }

   return 0;
}
