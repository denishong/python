#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define LEFT '4'
#define RIGHT '6'
#define UP  '8'
#define DOWN '2'
#define ENTER '5'

void gotoxy(int x, int y);

int xy[16][16];
int x=1, y=1, x2 = 2;

void input(int *p) {
   char c;
    int z=1;
   
    while(z){
      
      c = getch();
   switch(c)
   {
      case RIGHT:{
         ++x,x2 += 2;
         if(x >= 15) --x, x2 -=2;
         gotoxy(x2,y);
         break;
               }

      case LEFT: {
         --x, x2 -=2;
         if(x <= 0 ) ++x, x2+=2;
         gotoxy(x2,y);
         break;
               }
      case UP: {
         --y;
         if(y <= 0 ) ++y;
         gotoxy(x2,y);
         break;
             }
      case DOWN: {
         ++y;
         if(y >= 15 ) --y;
         gotoxy(x2,y);
         break;
               }


      case ENTER:{
         if(xy[y][x] != 0 ) break;
         if(*p == 2 ) {
            xy[y][x] = 2;
                  }
          else {
            xy[y][x] = 1;
            
         }
         z = 0;
         }
   
      
   }
   }
}
                        
   void screen(){
      
        system("cls");
      int j,k;

      for(j=0;j<16;j++) {
         for(k=0;k<16;k++) {
            if(xy[j][k] == 1) printf("○");
            else if(xy[j][k] == 2 ) printf("●");
            else if(xy[j][k] == 0 ) printf("┼");
         }
         
         printf("\n");
      }
      gotoxy(0,21);
      printf("UP:8  DOWN:2  LEFT:4  RIGHT:6  ENTER:5"); 
      
   }


int check(int *p)
{
   int j,sum = 0;

   for(j=-5;j<=5;j++){
      if(x+j <= 0 && x+j >=16) continue;
      if(xy[y][x+j] == *p){
         sum++;
         if(sum == 5) return 0;
      }
      else sum = 0;
      
   }

   for(j=-5;j<=5;j++) {
      if(y+j <= 0 && y+j >=16) continue;
      if(xy[y+j][x] == *p) {
         sum++;
         if(sum == 5) return 0;
      }
      else sum = 0;
   }

   for(j=-5;j<=5;j++) {
      if(y+j <= 0 && y+j >=16) continue;
      if(x+j <= 0 && x+j >=16) continue;
      if(xy[y+j][x+j] == *p) {
         sum++;
         if(sum == 5) return 0;
      }
      else sum = 0;
   }
   for(j=-5;j<=5;j++) {
      if(y+j <= 0 && y+j >=16) continue;
      if(x-j <= 0 && x-j >=16) continue;
      if(xy[y+j][x-j] == *p) {
         sum++;
         if(sum == 5) return 0;
      }
      else sum = 0;
   }
   

   return 1;
}



void main() {
   int a=1,z=1;
    int j,k;


   for(j=0;j<16;j++) {
      for(k=0;k<6;k++) {
         xy[k][j] =0;
   }}

   screen();
   while(z){
      
      gotoxy(0,20);
      printf("%d 님 번째 차례",a);
      input(&a);
      screen();
      z = check(&a);
      if(a == 1) a = 2;
       else a =1;
       
      
   }
   gotoxy(0,20);
   printf("%d님의 승리",a);

   
}

void gotoxy(int x , int y)
{
   COORD Pos = { x , y};
   SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), Pos);
}

