// Juan Diego Collazos Mejia // ID: 8977837 // ferbruary 16st 2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	int cases, x, y, ax, ay;
	int i;
	int flag = 1;
	
	while (flag){
		scanf("%d", &cases);
		if (cases == 0){
			flag = 0;
		}else{
			scanf("%d %d", &x, &y);
			for (i = 0; i < cases; ++i){
				scanf("%d %d", &ax, &ay);
				if(x == ax || y == ay){
					printf("divisa\n");
				}else if(ay > y && ax > x){
					printf("NE\n");
				}else if(ay > y && ax < x){
					printf("NO\n");
				}else if(ay < y && ax > x){
					printf("SE\n");
				}else{
					printf("SO\n");
				}
			}
		}
	}
	return 0;
}