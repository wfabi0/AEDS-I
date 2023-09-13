// Escreva um programa em C++ com um menu para o usuário escolher qual das funções das questões
// anteriores acessar. Caso for digitado qualquer número de 1 a 7 seu programa deverá chamar as funções das
// questões anteriores, a opção 0 deverá pedir confirmação para sair do programa e qualquer outro número
// digitado deverá apresentar uma mensagem de opção inválida. Enquanto o usuário não confirmar a saída seu
// programa deverá continuar apresentando o menu com as opções para o usuário.

#include <iostream>
#include <windows.h>
 
using namespace std;

void clear(), pause(), menu();
void question1(), question2(), question3(), question4(), question5(), question6(), question7();
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int n;

  do {
    menu();
    cin >> n;
    if(n < 0) {
        n = 10;
    }

    switch(n) {
        case 0: {
            int option;
            do {
                clear();
                cout << "Realmente deseja sair? (1 - Sim / 0 - Não)" << endl;
                cout << "Digite uma opção: ";
                cin >> option;
                if(option == 1) {
                    n = -1;
                }
            } while(option < 0 && option > 1);
            break;
        }
        case 1: {
            clear();
            question1();
            pause();
            break;
        }
        case 2: {
            clear();
            question2();
            pause();
            break;
        }
        case 3: {
            clear();
            question3();
            pause();
            break;
        }
        case 4: {
            clear();
            question4();
            pause();
            break;
        }
        case 5: {
            clear();
            question5();
            pause();
            break;
        }
        case 6: {
            clear();
            question6();
            pause();
            break;
        }
        case 7: {
            clear();
            question7();
            pause();
            break;
        }
        default: {
            clear();
            cout << "Opção inválida!" << endl << endl;
            pause();
            break;
        }
    }
  } while(n != -1);

  clear();
  cout << endl << "Obrigado por utilizar o programa! Finalizando..." << endl << endl;
 
  return 0;
}

void clear() {
  system("cls");
}

void pause() {
  system("pause");
}

void menu() {
    clear();
    cout << "1 - Mega Sena" << endl;
    cout << "2 - Chuva" << endl;
    cout << "3 - Somar coluna da matriz" << endl;
    cout << "4 - Somar linha da matriz" << endl;
    cout << "5 - Somar diagona" << endl;
    cout << "6 - Quadrado Mágico" << endl;
    cout << "7 - Imprima um número" << endl;
    cout << "0 - Sair" << endl;
    cout << "Digite uma opção: ";
}

void question1() {
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
}

void question2() {
  int N;
  cin >> N;

  int map[N][N];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  int regionMap[N][N];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        int valor;
        cin >> valor;
        regionMap[i][j] = map[i][j] + valor;
    }
  }

  cout << endl << endl;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        cout << regionMap[i][j] << " ";        
    }
    cout << endl;
  }
}

void question3() {
  int matrix[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cin >> matrix[i][j];
    }
  }

  for(int j = 0; j < 3; j++) {
    int coluna = 0;
    for(int i = 0; i < 3; i++) {
        coluna += matrix[i][j];
    }
    cout << "Coluna " << j << ": " << coluna << endl;
  }
}

void question4() {
  int matrix[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cin >> matrix[i][j];
    }
  }

  for(int i = 0; i < 3; i++) {
    int linha = 0;
    for(int j = 0; j < 3; j++) {
        linha += matrix[i][j];
    }
    cout << "Linha " << i << ": " << linha << endl;
  }
}

void question5() {
  int matrix[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cin >> matrix[i][j];
    }
  }

  int diagonalPrimary = 0, diagonalSecundary = 0;
  for(int i = 0; i < 3; i++) {
    diagonalPrimary += matrix[i][i];
    diagonalSecundary += matrix[i][3 - 1 - i];
  }

  cout << endl << "Diagonal principal: " << diagonalPrimary << endl;
  cout << "Diagonal secundaria: " << diagonalSecundary << endl;
}

void question6() {
  int matrix[3][3];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cin >> matrix[i][j];
    }
  }

  int sum = 0, diagonalPrimary = 0, diagonalSecundary = 0;
  bool isMagic = true;

  for(int i = 0; i < 3; i++) {
    sum += matrix[0][i];
    diagonalPrimary += matrix[i][i];
    diagonalSecundary += matrix[i][3 - 1 - i];
  }

  for(int i = 0; i < 3; i++) {
    int sumRow = 0, sumColumn = 0;
    for(int j = 0; j < 3; j++) {
      sumRow += matrix[i][j];
      sumColumn += matrix[j][i];
    }
    if(sumRow != sum || sumColumn != sum) {
      isMagic = false;
      break;
    }
  }

  if(diagonalPrimary != sum || diagonalSecundary != sum) {
    isMagic = false;
  }

  cout << endl << (isMagic ? "SIM" : "NAO") << endl;
}

void question7() {
  int n;
  cin >> n;

  while(n < 0 || n > 9) {
    cout << "Número inválido. Por favor, insira um número de 0 a 9." << endl << "Numero: ";
    cin >> n;
  }

  char matrix[4][5];
  char x = 'X', space = ' ';

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++) {
        matrix[i][j] = space;
    }
  }

  switch(n) {
    case 0: {
      for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j] = x;
        }
      }
      matrix[1][1] = space;
      matrix[1][2] = space;
      matrix[2][1] = space;
      matrix[2][2] = space;
      matrix[3][1] = space;
      matrix[3][2] = space;
      break;
    }
    case 1: {
      matrix[0][2] = x;
      matrix[1][2] = x;
      matrix[2][2] = x;
      matrix[3][2] = x;
      matrix[4][2] = x;
      break;
    }
    case 2: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][0] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 3: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 4: {
      matrix[0][0] = x;
      matrix[0][3] = x;
      matrix[1][0] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][3] = x;
      break;
    }
    case 5: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][0] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 6: {
      matrix[0][3] = x;
      matrix[0][2] = x;
      matrix[0][1] = x;
      matrix[0][0] = x;
      matrix[1][0] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][0] = x;
      matrix[3][3] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 7: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][3] = x;
      matrix[2][2] = x;
      matrix[3][1] = x;
      matrix[4][0] = x;
      break;
    }
    case 8: {
      for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j] = x;
        }
      }
      matrix[1][1] = space;
      matrix[1][2] = space;
      matrix[3][1] = space;
      matrix[3][2] = space;
      break;
    }
    case 9: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][0] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][3] = x;
      break;
    }
    default: {
      break;
    }
  }

  cout << endl << endl;

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++) {
        cout << matrix[i][j];
    }
    cout << endl;
  }
}