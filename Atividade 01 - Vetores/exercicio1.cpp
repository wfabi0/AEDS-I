// Construir um programa que gere 2 vetores de tamanho 3 e vai somar os itens o V1 com o V2 e
// jogar o resultado en um terceiro vetor V3 também de tamanho 3. Depois imprima o resultado de
// V3. Os vetores Vi e V2 serão preenchidos pelo usuário.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int v1[3], v2[3], v3[3];

  for(int i = 0; i < 3; i++) {
    cout << "Digite o " << i + 1 << "º valor do vetor 1: ";
    cin >> v1[i];
  }

  for(int i = 0; i < 3; i++) {
    cout << "Digite o " << i + 1 << "º valor do vetor 2: ";
    cin >> v2[i];
  }

  system("cls");

  cout << "Terceiro vetor: " << endl;
  for(int i = 0; i < 3; i++) {
    v3[i] = v1[i] + v2[i];
  }

  for(int i = 0; i < 3; i++) {
    cout << "\t\t" << v3[i];
  }
 
  cout << endl << endl;
  return 0;
}