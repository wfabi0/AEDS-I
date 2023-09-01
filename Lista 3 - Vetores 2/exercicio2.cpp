// Escreva um algoritmo que armazene em um vetor todos os números inteiros de 100 a 1 (em ordem
// decrescente). Após isso, o algoritmo deve imprimir todos os valores armazenados.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int vector[100];
  for (int i = 100; i >= 0; i--) {
    vector[i] = i;
    cout << vector[i] << " ";
  }
 
  cout << endl << endl;
  return 0;
}