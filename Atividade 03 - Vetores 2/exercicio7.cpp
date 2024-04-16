// Numa corrida há 10 corredores, de número de inscrição de 1 a 10. Faça um algoritmo que leia os
// valores do número do corredor e o seu respectivo tempo na corrida. Além disso, o programa deve
// imprimir a qualificação e o tempo de corrida, do primeiro ao décimo colocado, identificando o
// número de inscrição do corredor referente àquela colocação. Suponha que não há tempos iguais.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  double runners[10][2];
  for(int i = 0; i < 10; i++) {
    cout << "Insira o tempo de corrida do " << i + 1 << "° corredor: ";
    cin >> runners[i][0];
    runners[i][1] = i;
  }

  double temp, temp2;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
        if(runners[i][0] < runners[j][0]) {
            temp = runners[i][0];
            runners[i][0] = runners[j][0];
            runners[j][0] = temp;
            temp2 = runners[i][1];
            runners[i][1] = runners[j][1];
            runners[j][1] = temp2;
        }
    }
  }

  cout << endl << "-------- Ranking --------" << endl;
  for(int i = 0; i < 10; i++) {
    cout << i + 1 << "° lugar - Atleta " << runners[i][1] + 1 << " - " << runners[i][0] << endl;
  }
 
  cout << endl << endl;
  return 0;
}