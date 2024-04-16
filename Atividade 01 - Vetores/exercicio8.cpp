// Dados dois vetores x e y, ambos com n elementos, determinar o produto escalar desses vetores.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int n;

  cout << "Digite o número de elementos dos vetores: ";
  cin >> n;

  int x[n], y[n], produto = 0;

  cout << "Digite os elementos do vetor x: ";
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }

  cout << "Digite os elementos do vetor y: ";
  for(int i = 0; i < n; i++) {
    cin >> y[i];
  }

  for(int i = 0; i < n; i++) {
    produto += x[i] * y[i];
  }

  cout << "O produto escalar dos vetores é: " << produto;
 
  cout << endl << endl;
  return 0;
}