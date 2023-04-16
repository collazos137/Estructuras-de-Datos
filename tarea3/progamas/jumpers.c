// Juan Diego Collazos Mejia // ID: 8977837 // ferbruary 18st 2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

void jumpers();
int abs(int n);
void zero(int* arr, int size);
int same(int* arr, int size, int num);

int main(){
	jumpers();
	return 0;
}

int abs(int n){
	if(n < 0){
		n *= -1;
	}
	return n;
}

void zero(int* arr, int size){
	int i;
	for(i = 1; i < size; ++i){
		arr[i] = 0;
	}
}

int same(int* arr, int size, int num){
	int i = 1, ans = 1;
	while(i < size && ans){
		if(arr[i] != num){
			ans = 0;
		}
		++i;
	}
	return ans;
}

void jumpers(){
	int n, i, k, ax, ax2, diff, flag;
	int arr[3000];
	while(scanf("%d", &n) != EOF){
		zero(arr, n);
		i = 0, flag = 1;
		scanf("%d", &ax);
		while(i < n - 1){
			scanf("%d", &ax2);
			
			if(flag){
				diff = abs(ax - ax2);
				
				if (diff > n ){
					flag = 0;
				}else{
					arr[diff] += 1;
				}
				ax = ax2;
			}
			
			++i;
		}

		if(flag){
			flag = same(arr, n, 1);
		}

		if(flag){
			printf("Jolly\n");
		}else{
			printf("Not jolly\n");
		}
	}

}