#include <stdio.h>

int main()
{
	int i,n,temp=0, max_num=0;
	int condition = 0;
	int vector[101];

	scanf("%d", &n);
	scanf("%d", &condition);

	for(i=0; i < n; i++)
		scanf("%d", &vector[i] );

 for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++ ){
            for(int k = j; k < n; k++){
                if(i == j || i == k || j == k) continue;
				//printf("vector[i] : %d, vector[j] : %d, vector[k] : %d \n", vector[i], vector[j], vector[k]);
                int temp = vector[i] + vector[j] + vector[k];
                if(temp <= condition && max_num < temp){
                    max_num = temp;
                }
            }
        }
    }

	printf("%d \n", max_num);
	return 0;
}
