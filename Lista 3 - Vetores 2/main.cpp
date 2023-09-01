// Faça um algoritmo que junte todas as questões anteriores em um único programa, onde o usuário escolhe qual questão ele quer executar.
// Lembre-se de utilizar funções.

#include <iostream>
#include <windows.h>
#include <iomanip>
 
using namespace std;

void menu(), Q1(), Q2(), Q3(), Q4(), Q5(), Q6(), Q7();
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int option;

  do {
    menu();
    cout << "Insira o número da questão que deseja executar: ";
    cin >> option;
    
    switch(option) {
        default: {
            cout << "Opção não encontrada, tente novamente." << endl;
            system("pause");
            break;
        }
        case 1: {
            system("cls");
            Q1();
            break;
        }
        case 2: {
            system("cls");
            Q2();
            break;
        }
        case 3: {
            system("cls");
            Q3();
            break;
        }
        case 4: {
            system("cls");
            Q4();
            break;
        }
        case 5: {
            system("cls");
            Q5();
            break;
        }
        case 6: {
            system("cls");
            Q6();
            break;
        }
        case 7: {
            system("cls");
            Q7();
            break;
        }
        case 0: {
            cout << "Saindo..." << endl;
            break;
        }
    }
  } while(option != 0);
 
  cout << endl << endl;
  return 0;
}

void menu() {
    system("cls");
    cout << "---------------- MENU ----------------" << endl;
    cout << "1. Questão 1" << endl;
    cout << "2. Questão 2" << endl;
    cout << "3. Questão 3" << endl;
    cout << "4. Questão 4" << endl;
    cout << "5. Questão 5" << endl;
    cout << "6. Questão 6" << endl;
    cout << "7. Questão 7" << endl;
    cout << "0. Sair" << endl;
    cout << "---------------- MENU ----------------" << endl;
}

void Q1() {
  int vector[50];
  for (int i = 1; i <= 51; i++) {
    vector[i] = i;
    cout << vector[i] << "\t";
  }
  cout << endl << endl;
  system("pause");
}

void Q2() {
  int vector[100];
  for (int i = 100; i >= 0; i--) {
    vector[i] = i;
    cout << vector[i] << "\t";
  }
  cout << endl << endl;
  system("pause");
}

void Q3() {
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
    cout << impares[i] << "\t";
  }
  cout << endl << endl;
  system("pause");
}

void Q4() {
  float numbers[10];
  for(int i = 0; i < 10; i++){
    cout << "Insira o " << i << "° numero: ";
    cin >> numbers[i];
    numbers[i] = (numbers[i]/2);
  }
  for(int i = 0; i < 10; i++) {
    cout << numbers[i] << "\t";
  }
  cout << endl << endl;
  system("pause");
}

void Q5() {
  int numbers[10];
  for(int i = 0; i < 10; i++){
    cout << "Insira o " << i << "° numero: ";
    cin >> numbers[i];
    numbers[i] = numbers[i] * numbers[i];
  }
  for(int i = 0; i < 10; i++) {
    cout << numbers[i] << "\t";
  }
  cout << endl << endl;
  system("pause");
}

void Q6() {
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
  system("pause");
}

void Q7() {
  double runners[10][2];
  for(int i = 0; i < 10; i++) {
    cout << "Insira o tempo de corrida do " << i + 1 << "° corredor: ";
    cin >> runners[i][0];
    runners[i][1] = i;
  }
  double temp, temp2;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
        if(runners[i][0] < runners[j][0]) {
            temp = runners[i][0];
            runners[i][0] = runners[j][0];
            runners[j][0] = temp;
            temp2 = runners[i][1];
            runners[i][1] = runners[j][1];
            runners[j][1] = temp2;
        }
    }
  }
  cout << endl << "-------- Ranking --------" << endl;
  for(int i = 0; i < 10; i++) {
    cout << i + 1 << "° lugar - Atleta " << runners[i][1] + 1 << " - " << runners[i][0] << endl;
  }
  cout << endl << endl;
  system("pause");
}