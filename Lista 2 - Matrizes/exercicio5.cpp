// Faça um programa para preencher uma matriz (6x6) de n°s inteiros. Depois
// imprima a soma dos elementos que estão abaixo da diagonal principal, incluindo os
// elementos da diagonal principal.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int matriz[6][6];

  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++) {
        cout << "Digite o valor da linha " << i + 1 << " e coluna " << j + 1 << ": ";
        cin >> matriz[i][j];
    }
  }

  int soma = 0;
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j <= i; j++) {
        soma += matriz[i][j];
    }
  }

  cout << endl << endl << "Soma dos elementos abaixo da diagonal principal: " << soma;
 
  cout << endl << endl;
  return 0;
}