/*
===================================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 29st 2023
===================================================================================================================
Complejidad : O(n) 
===================================================================================================================
La complejidad de encontrar cada combinación de números es O(n) (amortizado) siendo n la cantidad de pistas. Al 
ser una solución por fuerza bruta en el peor de los casos serian 10 pistas y se encontraría una única solución o 
ninguna, por tanto se compararían 10000 números con 10 pistas lo que serian 100000 comparaciones para un solo caso.
===================================================================================================================
*/
#include <stdio.h>

int main(){
	int nCases, nGuesses;
	int guesses[10][4];
	int posAndDig[10];
	int onlyDig[10];
	int ite[4];
	int dig[10];
	int ans;
	int flag1, flag2, flag3;
	int i, j, k, p;
	int ax1, numdig, numequ, ax2;

	scanf("%d", &nCases);
	for(i = 0; i < nCases; ++i){
		ax2 = 0;
		scanf("%d", &nGuesses);
		for(j = 0; j < nGuesses; ++j){
			scanf("%d %d/%d", &ax1, &posAndDig[j], &onlyDig[j]);
			for(k = 3; k >= 0; --k){
				guesses[j][k] = ax1 % 10;
				ax1 /= 10;
			}
		}
		for(j = 0; j < 4; ++j){
			ite[j] = 0;
		}
		j = 0;
		flag1 = 1;
		while(j < 10000 && flag1){
			flag2 = 1;
			k = 0;
			while(k < nGuesses && flag2){
				numdig = 0;
			 	numequ = 0;

				for(p = 0; p < 10; ++p){
					dig[p] = 0;
				}

				for(p = 0; p < 4; ++p){
					dig[guesses[k][p]] += 1;
				}

				for(p = 0; p < 4; ++p){
					if(dig[ite[p]] != 0){
						++numdig;
						--dig[ite[p]];
					}
				}

				for(p = 0; p < 4; ++p){
					if(ite[p] == guesses[k][p]){
						--numdig;
						++numequ; 	
					}
				}
				if(!(numdig == onlyDig[k] && numequ == posAndDig[k])){
					flag2 = 0;
				}
				++k;
			}
			if(flag2){
				++ax2;
				ans = j;
				if(ax2 > 1){
					flag1 = 0;
				}
			}
			if(flag1){
				k = 3, flag3 = 1;
				while(k >= 0 && flag3){
					if(ite[k] == 9){
						ite[k] = 0;
					}else{
						ite[k]++;
						flag3 = 0;
					}
					--k;
				}	
			}
			++j;
		}
		if(ax2 == 0){
			printf("impossible");
		}else if(ax2 == 1){
			printf("%d", ans);
		}else{
			printf("indeterminate");
		}
		printf("\n");
	}
	return 0;
}