/*
==================================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 26st 2023
==================================================================================================================
Complejidad : O(n*log(n))
==================================================================================================================
La complejidad de al ordenar todos los nombre seria O(n*log(n)) (que es la complejidad del sort() de STL) siendo n
la cantidad de nombres ingresados y la complejidad de hallar la mínima palabra que separe alfabéticamente la lista
de todos lo nombres ordenados por la mitad seria O(n) siendo en n la cantidad de dígitos de la palabra mayor 
(alfabéticamente) de la mitad inferior, que en el peor de los casos es 35.
==================================================================================================================
*/
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	char ans[35];
	int nGuests;
	int i;
	int pos1, pos2, len, leng1, leng2;
	int flag1 = 1, flag2, flag3;
	vector<string> names(1000);
	string name1, name2;

	while(flag1){
		scanf("%d", &nGuests);
		if(nGuests == 0){
			flag1 = 0;
		}else{
			for(i = 0; i < nGuests; ++i){
				cin >> names[i];
			}
			
			sort(names.begin(), names.begin() + nGuests);
			
			pos1 = (nGuests/2) - 1;
			pos2 = (nGuests/2);
			flag2 = 1;
			flag3 = 0;
			i = 0;
			leng1 = names[pos1].size();
			leng2 = names[pos2].size();
			name1 = names[pos1];
			name2 = names[pos2];
			len = (leng1 <= leng2) ? leng1 : leng2;

			while(i < len && flag2){
				if(name1[i] == name2[i]){
					ans[i] = name1[i];
				}else{
					if((name1[i] + 1 != name2[i] && ( (leng2 - i - 1 != 0 && leng1 - i - 1 != 0) || leng1 - i - 1 != 0 )) || ((leng2 - i - 1 != 0 && leng1 - i - 1 != 0) && name1[i] + 1  == name2[i])){
						ans[i] = name1[i] + 1;
					}else{
						ans[i] = name1[i];
						flag3 = 1;
					}
					flag2 = 0;
				}
				++i;
			}

			if(flag3 && leng1 > leng2){
				if(leng1 - i == 1){
					ans[i] = name1[i];
					ans[i+1] = '\0';
				}else{
					if(name1[i] == 'Z'){

						while(name1[i] == 'Z'){
							ans[i] = name1[i];
							++i;
						}

						if(leng1 - i != 0){
							if(leng1 - i == 1){
								ans[i] = name1[i];
							}else{
								ans[i] = name1[i] + 1;
							}
							ans[i+1] = '\0';
						}else{
							ans[i] = '\0';
						}

					}else{
                        ans[i] = name1[i] + 1;
                        ans[i+1] = '\0';
					}	
				}
				
			}else{
				ans[i] = '\0';	
			}
			
			printf("%s\n", ans);
		}
	}
	return 0;
}