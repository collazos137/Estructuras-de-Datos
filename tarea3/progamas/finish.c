// Juan Diego Collazos Mejia // ID: 8977837 // ferbruary 17st 2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void finish();
void read(int* arry, int nGas);
int answer(int* past, int* apn, int nGas);

int main(){
	finish();
	return 0;
}

int answer(int* past, int* apn, int nGas){
	int i = 0, j, acm, flag = 0, ans, ax, ax2;
	while(i < nGas && !flag){
		j = i;
		ax = i;
		flag = 1;
		acm = 0;
		do{
			ax2 = past[j] - apn[j];
			acm += ax2;

			if (acm < 0){
				flag = 0;
			}
			++j;
			if(j == nGas){
				j = 0;
			}

		}while(j != i && flag);
		++i;
	}
	if (flag == 0){
		ans = -1;
	}else{
		ans = ax + 1;
	}
	
	return ans;
}

void read(int* arry,int nGas){
	int j;
	for(j = 0; j < nGas; ++j){
		scanf("%d", &arry[j]);
		}
}

void finish(){
	int cases, i, nGas, j, ans, ax;
	int past[100000];
	int apn[100000];
	scanf("%d", &cases);
	for(i = 1; i <= cases; ++i){
		scanf("%d", &nGas);
		read(past, nGas);
		read(apn, nGas);

		ans = answer(past, apn, nGas);	
		if(ans == -1){
			printf("Case %d: Not possible", i);
		}else{
			printf("Case %d: Possible from station %d", i, ans);
		}
		
		printf("\n");
		
	}
}