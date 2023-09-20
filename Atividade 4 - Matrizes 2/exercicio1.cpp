// Escreva um função em C++ para ler um vetor A de 6 elementos contendo o gabarito da Mega Sena. A
// seguir, ler um vetor B de 10 elementos contendo uma aposta. Escrever quantos pontos fez o apostador, e se
// ele fez a sena (6 acertos), a quina (5 acertos) ou a quadra (4 acertos).

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  cout << "Mega Sena - Números sorteados" << endl;
  int vectorA[6];
  for(int i = 0; i < 6; i++) {
    cin >> vectorA[i];
  }

  cout << endl << "Gabarito do Usuário" << endl;
  int vectorB[10];
  for(int i = 0; i < 10; i++) {
    cin >> vectorB[i];
  }

  system("pause");
  system("cls");

  int successes = 0;

  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 10; j++) {
        if(vectorA[i] == vectorB[j]) {
            cout << "O número " << vectorA[i] << " foi sorteado!" << endl;
            successes++;
        }
    }
  }

  cout << endl << successes << " pontos" << endl;
 
  return 0;
}