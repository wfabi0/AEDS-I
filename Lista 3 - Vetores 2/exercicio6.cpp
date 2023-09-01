// Escreva um algoritmo que receba a altura de 10 atletas. Esse algoritmo deve imprimir a altura
// daqueles atletas que tem altura maior que a média.

#include <iostream>
#include <windows.h>
#include <iomanip>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  double heights[10], media = 0;
  for(int i = 0; i < 10; i++){
    cout << "Insira a " << i << "° altura: ";
    cin >> heights[i];
    media += heights[i];
  }
  
  media = media/10;

  cout << endl << "Media: " << setprecision(3) << media << endl;

  for(int i = 0; i < 10; i++){
    if(heights[i] >= media){
        cout << "O " << i << "° atleta é maior que a media. (" << setprecision(3) << heights[i] << ")" << endl;
    }
  }
 
  cout << endl << endl;
  return 0;
}