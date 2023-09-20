// Faça um programa que dado uma matriz (5x5) de números inteiros imprima a soma
// dos elementos da diagonal principal. Considere: i(índice da linha) ej(índice da coluna)

// Os elementos da diagonal principal são os que estão coloridos
// M1,1 M2,2 M3,3 M4,4 M5,5
// O resultado soma é 74.
// Para resolver este programa verifique o que os índices tem em comum ou de diferente

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int matriz[5][5];
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cout << "Digite o valor da linha " << i + 1 << " e coluna " << j + 1 << ": ";
      cin >> matriz[i][j];
    }
  }

  system("pause");
  system("cls");

  int diagonal = 0;
  for(int i = 0; i < 5; i++) {
    diagonal += matriz[i][i];
  }

  cout << "Soma da diagonal: " << diagonal;
 
  cout << endl << endl;
  return 0;
}