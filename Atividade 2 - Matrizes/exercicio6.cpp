// Fazer um programa que gere uma matriz (3x3) de números inteiros:
// A) Calcular a soma dos elementos da 1° coluna.
// B) Calcular o produto dos elementos da 1ª linha.
// C) Calcular a soma de todos os elementos da matriz.
// D) Calcular a média dos elementos da matriz.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int matriz[3][3];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++){
      cout << "Digite o valor da linha " << i + 1 << " e coluna " << j + 1 << ": ";
      cin >> matriz[i][j];
    }
  }

  cout << endl << endl;

  int soma = 0;
  for(int i = 0; i < 3; i++) {
    soma += matriz[i][0];
  }

  int produto = 1;
  for(int i = 0; i < 3; i++) {
    produto = produto * matriz[0][i];
  }

  int totalSoma = 0, media;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        totalSoma += matriz[i][j];
        media = totalSoma / (3 * 3);
    }
  }

  cout << "Soma da primeira linha: " << soma << endl;
  cout << "Produto da primeira coluna: " << produto << endl;
  cout << "Soma de todos os elementos: " << totalSoma << endl;
  cout << "Média dos valores da matriz: " << media << endl;
 
  cout << endl << endl;
  return 0;
}