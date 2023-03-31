/*
================================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 25st 2023
================================================================================================================
Complegidad : O(n^2)
================================================================================================================
La complejidad de calcular los ganadores de cada sistema de puntuación es O(n^2) siendo n el número de pilotos.
En el peor de los casos serian 500 pilotos y se valoran los 500 puestos, y cada caso tiene como máximo 10 
sistemas de puntuación, por lo tanto en el peor caso posible se necesitarían del orden de 2500000 procedimientos
para dar respuesta a todos los sistemas de puntuación de un caso.
================================================================================================================
*/
#include <stdio.h>

int main(){
	int nPiots, nRaces, nScoring, maxP;
	int scorin[500], piotsScorT[500], ans[500];
	int postRaces[500][500];
	int i, j, k;
	int flag1 = 1, flag2;
	int ax, max;
	while(flag1){
		scanf("%d %d", &nRaces, &nPiots);
		if(nPiots == 0){
			flag1 = 0;
		}else{
			for(i = 0; i < nPiots; ++i){
				for(j = 0; j < nPiots; ++j){
					postRaces[i][j] = 0;
				}
			}

			for(i = 0; i < nRaces; ++i){
				for(j = 0; j < nPiots; ++j){
					scanf("%d", &ax);
					postRaces[j][ax - 1] += 1;
				}
			}

			scanf("%d", &nScoring);

			for(i = 0; i < nScoring; ++i){
				scanf("%d", &maxP);
				for(j = 0; j < maxP; ++j){
					scanf("%d", &ax);
					scorin[j] = ax;
				}

				for(j = 0; j < nPiots; ++j){
					piotsScorT[j] = 0;
				}

				for(j = 0; j < nPiots; ++j){
					k = 0;
					flag2 = 1;
					ax = 0;
					while(k < maxP && flag2){
						if(postRaces[j][k] != 0){
							piotsScorT[j] += (postRaces[j][k]*scorin[k]);
							ax += postRaces[j][k];
							if(ax == nRaces){
								flag2 = 0;
							}
						}
						++k;
					}
				}
				max = piotsScorT[0];
				ans[0] = 1;
				k = 1;

				for(j = 1; j < nPiots; ++j){
					if(piotsScorT[j] == max){
						ans[k] = j + 1;
						++k;
					}else if(piotsScorT[j] > max){
						k = 1;
						ans[0] = j + 1;
						max = piotsScorT[j];
					}
				}
				printf("%d", ans[0]);
				for(j = 1; j < k; ++j){
					printf(" %d", ans[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}