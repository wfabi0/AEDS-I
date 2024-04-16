// Escreva um algoritmo que armazene em um vetor os 100 primeiros números ímpares. Após isso, o
// algoritmo deve imprimir todos os valores armazenados.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int impares[100];

  int count = 0, i = 0;
  while(i <= 100){
    if((count % 2) != 0){
      impares[i] = count;
      i++;
    }
    count++;
  }

  for(int i = 0; i < 100; i++){
    cout << impares[i] << " ";
  }
 
  cout << endl << endl;
  return 0;
}