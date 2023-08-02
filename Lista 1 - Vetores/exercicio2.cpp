// Construir um programa que gere um vetor de 3 posições de números inteiros. Mostre a posição
// dos números que são ímpares.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int vector[3] = { 1, 2, 9 };

  cout << "Posições Impares: " << endl;

  for(int i = 0; i < 3; i++) {
    if(vector[i] % 2 != 0){
        cout << "\t\t" << i;
    }
  }
 
  cout << endl << endl;
  return 0;
}