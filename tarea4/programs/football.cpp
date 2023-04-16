/*
========================================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 30st 2023
========================================================================================================================
Complejidad : O(n*log(n)) 
========================================================================================================================
La complejidad de organizar todos los equipos con los respectivos criterios seria O(n*log(n)) (que es la complejidad
del sort() de STL) siendo n la cantidad de equipos ingresados. Por otro lado, la complejidad de procesar cada partido
seria O(n)(amortizado) (que es la complejidad del find() de STL) siendo n la cantidad de equipos ingresados, cada vez
que se ingrese un partido de deberá buscar dentro del vector los equipos correspondientes para actualizar su información.
========================================================================================================================= 
*/
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool alfa(string name1, string name2);

class Team{
  public:
	string name;
	int nPoints;
	int nPlayed;
	int nScoreG;
	int nSufferedG;

  Team(string nom){
    name = nom;
    nPoints = 0;
    nPlayed = 0;
    nScoreG = 0;
    nSufferedG = 0;
  }

  Team(){
    name = "";
    nPoints = 0;
    nPlayed = 0;
    nScoreG = 0;
    nSufferedG = 0;
  }

  bool operator <(const Team& tem){
    bool ans;
    if(nPoints != tem.nPoints){
    	ans = nPoints > tem.nPoints;
    }else if(nScoreG - nSufferedG != tem.nScoreG - tem.nSufferedG){
    	ans = nScoreG - nSufferedG > tem.nScoreG - tem.nSufferedG;
    }else if(nScoreG != tem.nScoreG){
    	ans = nScoreG > tem.nScoreG;
    }else{
    	if(alfa(name, tem.name)){
    		ans = true;
    	}else{
    		ans = false;
    	}
    }
    return ans;
  }

  bool operator ==(const Team& tem){
    bool ans = name == tem.name;
    return ans;
  }
};

bool alfa(string name1, string name2){
	int ans = false;
	int flag1 = 1, i = 0;
	int l = (name1.size() <= name2.size()) ? name1.size() : name2.size();
	while(i < l && flag1){
			name1[i] -= (name1[i] > 'Z') ? 32 : 0;
			name2[i] -= (name2[i] > 'Z') ? 32 : 0;
		if(name1[i] != name2[i]){
			flag1 = 0;
			if(name1[i] < name2[i])
				ans = true;
		}
		++i;
	}
	if(flag1){
		ans = name1.size() < name2.size();
	}
	return ans;
}

int main(){
	vector<Team> teams(99, Team());
	vector<Team>::iterator ax1;
	vector<Team>::iterator ax2;
	char team1[16], team2[16];
	int nteams, ngames;
	int goals1, goals2;
	int flag = 1, flag2, flag3 = 0;
	int i;
	while(flag){
		
		scanf("%d %d", &nteams, &ngames);
		if(nteams == 0 && ngames == 0){
			flag = 0;
		}else{
			if(flag3){
				printf("\n");
			}
			flag3 = 1;

			for(i = 0; i < nteams; ++i){
				cin >> teams[i].name;
				teams[i].nPoints = 0;
				teams[i].nPlayed = 0;
				teams[i].nScoreG = 0;
				teams[i].nSufferedG = 0;
			}

			for(i = 0; i < ngames; ++i){
				scanf("%s %d - %d %s", &team1, &goals1, &goals2, &team2);
				ax1 = find(teams.begin(), teams.begin() + nteams, Team(team1));
				ax2 = find(teams.begin(), teams.begin() + nteams, Team(team2));
				ax1 -> nPlayed += 1;
				ax2 -> nPlayed += 1;
				ax1 -> nScoreG += goals1;
				ax2 -> nScoreG += goals2;
				ax1 -> nSufferedG += goals2;
				ax2 -> nSufferedG += goals1;
				if(goals1 > goals2){
					ax1 -> nPoints += 3;
				}else if(goals1 < goals2){
					ax2 -> nPoints += 3;
				}else{
					ax1 -> nPoints += 1;
					ax2 -> nPoints += 1;
				}
			}

			sort(teams.begin(), teams.begin() + nteams);

			for(i = 0; i < nteams; ++i){
				flag2 = 0;
				if(i != 0){
					if(teams[i].nPoints == teams[i - 1].nPoints && (teams[i].nScoreG - teams[i].nSufferedG) == (teams[i - 1].nScoreG - teams[i - 1].nSufferedG) && teams[i].nScoreG == teams[i - 1].nScoreG){
						flag2 = 1;
					}
				}
				if(flag2){
					printf("   ");
				}else{
					printf("%2d.", i+1);
				}

				printf(" %15s %3d %3d %3d %3d %3d", teams[i].name.c_str(), teams[i].nPoints, teams[i].nPlayed, teams[i].nScoreG, teams[i].nSufferedG, teams[i].nScoreG - teams[i].nSufferedG);

				if(teams[i].nPlayed != 0){
					printf(" %6.2f",(float(teams[i].nPoints) / (teams[i].nPlayed*3))*100);
				}else{
					printf("%7s", "N/A");
				}
				printf("\n");
			}
		}
	}
	return 0;
}