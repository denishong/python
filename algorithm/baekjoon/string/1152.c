#include <stdio.h>
#include <string.h>
#define MAXN ((int) 1e6)

int main()
{
	int i=0, length=0;
	char str[MAXN+10];

	scanf("%[^\n]s", str);

	while( str[i] != '\0')
	{
	//	printf(" length : %d i : %d\n", length,i);

		i++;
		if (str[0] == ' ' && str[1] == '\0')
		{
			break;
		}
		else if(i == 0 && str[0] ==' ')
		{

		}else if( str[i] == ' '){
			length++;
		}

	}

	if( str[i] == '\0' && str[i-1] != ' '){
		length++;
	} else if( str[i] =='\0' && str[i-1] == ' '){
	}

	printf("%d\n", length);

	return 0;
}
