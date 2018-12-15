#include <stdio.h>

int days_in_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int days_in_month_yoon[12]={31,29,31,30,31,30,31,31,30,31,30,31};

int month_Head_print(int year,int month)
{
	printf("                    %d.   %d.\n",year,month);
	printf("---------------------------------------------------\n");
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	printf("---------------------------------------------------\n");

	return 0;
}

void print_calendar(int start_date, int days)
{
	int d,c,dtd;

   for(d=1; d<=days; d++)
        {
            dtd+=d;
            if(d==1)
            {
                switch(dtd%7)
                {
                    case 0:
                    printf("%3d",d);
                    break;

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
	printf("---------------------------------------------------\n");
	printf("\n");
}

int yoon(int year)
{
	int leapyear=year;

	if(leapyear%4==0)
	{
    if(leapyear%100==0)
    {
        if(leapyear%400==0)
        {
           // printf("윤년 입니다");
				return 366;
        }
        else
        {
          //  printf("윤년이 아닙니다.");
				return 365;
        }
    }
    else
    {
        	//printf("윤년 입니다.");
			return 366;
    }
	}
	else
	{
    	//printf("윤년이 아닙니다.");
		return 365;
	}
	return 0;
}

int calc_start_date(int year, int month)
{
	int i,j, date=0,sum_days=0;

	for(i=1; i<year; i++)
		sum_days+=yoon(i);	
	for(j=1; j<month; j++)
	{
		if(yoon(year)==365)
		sum_days+=days_in_month[j-1];
		else
		sum_days+=days_in_month_yoon[j-1];
	}	
	date=sum_days%7;
	
	return date;
}

int main(void)
{

	int year,month,days,start_date,days_in_year;

	while(1)
	{
start:

/*Input*/
	printf("To terminate this program, enter 0,0.\n");

	printf("Year:");
	scanf("%d", &year);
	printf("Month:");
	scanf("%d", &month);

/*Input check*/
	if(year==0 && month==0)
	return 0;
	
	if(year<0)
	{
	printf("Year should be larger than 0.\n");
	goto start;
	}
	if(month<1 || month>12)
	{
	printf("Month should be between 1 and 12.\n");
	goto start;
	}
		
/*Output*/
	month_Head_print(year,month);
	days_in_year=yoon(year);	

	if(days_in_year==366)
	{
		days=days_in_month_yoon[month-1];
	}else
	{
		days=days_in_month[month-1];
	}

	start_date=calc_start_date(year,month);
	print_calendar(start_date,days);

	}	
	return 0;
}
