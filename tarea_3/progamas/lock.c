// Juan Diego Collazos Mejia // ID: 8977837 // ferbruary 16st 2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lock();
int antiHours(int num1, int num2);
int hours(int num1, int num2);
void read(int* arry, int size);
int sameArry(int* arry, int size, int num);

int main(){
	lock();
	return 0;
}

int antiHours(int num1, int num2){
	int ans;
	if(num1 <= num2){
		ans = num2 - num1;
	}else{
		ans = 40 - num1 + num2;
	}
	return ans;
}

int hours(int num1, int num2){
	int ans;
	if(num1 >= num2){
		ans = num1 - num2;
	}else{
		ans = 40 + num1 - num2;
	}
	return ans;
}

void read(int* arry, int size){
	int i;
	for(i = 0; i < size; ++i){
		scanf("%d",&arry[i]);
	}
}

int sameArry(int* arry, int size, int num){
	int ans = 1, i = 0;
	while (i < size && ans){
		if (arry[i] != num){
			ans = 0;
		}
		++i;
	}
	return ans;
}

void lock(){
	int flag = 1, ans;
	int ax[4];
	while (flag){
		read(ax, 4);
		if(!sameArry(ax, 4, 0)){
			ans = 9 * (120 + hours(ax[0], ax[1]) + antiHours(ax[1],ax[2]) + hours(ax[2], ax[3]));
			printf("%d\n", ans);
		}else{
			flag = 0;
		}
	}
}