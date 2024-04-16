// Escreva um algoritmo que armazene em um vetor todos os números inteiros de 1 a 50. Após isso, o
// algoritmo deve imprimir todos os valores armazenados.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int vector[50];
  for (int i = 1; i <= 51; i++) {
    vector[i] = i;
    cout << vector[i] << " ";
  }
  
  cout << endl << endl;
  return 0;
} 