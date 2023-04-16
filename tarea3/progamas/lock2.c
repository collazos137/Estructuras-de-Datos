// Juan Diego Collazos Mejia // ID: 8977837 // ferbruary 18st 2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lock();
int antiHours(int num1, int num2);
int hours(int num1, int num2);

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

void lock(){
	int flag = 1, ans, x1, x2, x3, x4;
	while(flag){
		scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
		if(!(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0)){
			ans = 9 * (120 + hours(x1, x2) + antiHours(x2, x3) + hours(x3, x4));
			printf("%d\n", ans);
		}else{
			flag = 0;
		}

	}
}