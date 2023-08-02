#include <stdio.h>
int main(){
	int a = 1;
	int i = -1;
	int sum = 0;
	while(a > 0){
		scanf("%d",&a);
		sum += a;
		i++;
	}
 
	printf("average number = %d\n",sum/i);
	return 0;
}  

