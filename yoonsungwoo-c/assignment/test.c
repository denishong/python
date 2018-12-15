#include <stdio.h>
 
int yoon(int a);
int good(int m, int x);
 
int main(void)
{
    int a,b,i,j,m,sum,dtd,c,d;
    printf("년,월을 입력하세요:");
    scanf("%d",&a);
    if(a==0)
    {
        return 0;
    }
    scanf("%d",&b);
    
    while(1)
    {
        m=0;
        sum=0;
        dtd=0;
        
        printf("   %d년 %d월\n",a,b);
        printf("================\n");
        printf("-------------------------------------------------------\n");
        printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
        printf("-------------------------------------------------------\n");
    
        for(i=1;i<a;i++)
        {m+=yoon(i);}
     
        for(j=1; j<b; j++)
        {sum+=good(j,a);}
     
        dtd=sum+m;
     
        c=good(b,a);
    
        for(d=1; d<=c; d++)
        {
            dtd+=d;
            if(d==1)
            {
                switch(dtd%7)
                {
                    case 1:
                    printf("\t%3d",d);
                    break;
                    
                    case 2:
                    printf("\t\t%3d",d);
                    break;
                    
                    case 3:
                    printf("\t\t\t%3d",d);
                    break;
                    
                    case 4:
                    printf("\t\t\t\t%3d",d);
                    break;
                    
                    case 5:
                    printf("\t\t\t\t\t%3d",d);
                    break;
                    
                    case 6:
                    printf("\t\t\t\t\t\t%3d",d);
                    break;
                 }
                 dtd-=d;
                 continue;
            }
            switch(dtd%7)
            {
                case 0:
                printf("%3d",d);
                break;
 
                case 1:
                printf("\t%3d",d);
                break;
 
                case 2:
                printf("\t%3d",d);
                break;
 
                case 3:
                printf("\t%3d",d);
                break;
 
                case 4:
                printf("\t%3d",d);
                break;
 
                case 5:
                printf("\t%3d",d);
                break;
 
                case 6:
                printf("\t%3d",d);
                break;
            }
            
            if(dtd%7==6)
            {
                printf("\n");
            }
            dtd-=d;
            
        }
    printf("\n");
    printf("년,월을 입력하세요:");
    scanf("%d",&a);
    if(a==0)
    {break;}
    scanf("%d",&b);
    }
    return 0;
}
 
int good(int m, int x)
{
    int t;
    switch(m)
    {
    case 1:
    t=31;
    break;
 
    case 2:
    if(yoon(x)==366)
        t=29;
    else
        t=28;
    break;
 
    case 3:
    t=31;
    break;
 
    case 4:
    t=30;
    break;
 
    case 5:
    t=31;
    break;
 
    case 6:
    t=30;
    break;
 
    case 7:
    t=31;
    break;
 
    case 8:
    t=31;
    break;
 
    case 9:
    t=30;
    break;
 
    case 10:
    t=31;
    break;
 
    case 11:
    t=30;
    break;
 
    case 12:
    t=31;
    break;
}
 
return t;
}
 
int yoon(int a)
{
    int s;
    
    if(a%4==0)
    {
        if(a%100==0)
        {
           if(a%400==0)
            s=366;
            else
            s=365;
        }
       else
       s=366;
    }
    else
    s=365;
      
    return s;
}
