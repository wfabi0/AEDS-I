// Tentando descobrir se um dado era viciado, um dono de cassino honesto (ha! ha! ha! ha!) o
// lançou n vezes. Dados os n resultados dos lançamentos, determinar o número de ocorrências de
// cada face.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int n, vetor[6] = { 0, 0, 0, 0, 0, 0 }, lado; 

  cout << "Digite o n° de vezes que o dado sera lançado: ";
  cin >> n;

  for(int i = 0; i < n; i++) {
    cout << "Digite a face do dado: ";
    cin >> lado;
    vetor[lado]++;
  }

  for(int i = 0; i < n; i++) {
    if(vetor[i] != 0) {
        cout << "A face " << i << " apareceu " << vetor[i] << " vezes" << endl;
    }
  }

  cout << endl << endl;
  return 0;
}