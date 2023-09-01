// Escreva um algoritmo que receba dez números do usuário e armazene em um vetor a metade de cada
// número. Após isso, o algoritmo deve imprimir todos os valores armazenados.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  float numbers[10];
  for(int i = 0; i < 10; i++){
    cout << "Insira o " << i << "° numero: ";
    cin >> numbers[i];
    numbers[i] = (numbers[i]/2);
  }

  for(int i = 0; i < 10; i++) {
    cout << numbers[i] << endl;
  }
 
  cout << endl << endl;
  return 0;
}