#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
 
using namespace std;

const int POPULATION = 10;

struct PERSON {
  string name;
  float salary;
  int age;
  int kids;
  char gender;
};

void loadFile(PERSON search[]);
void viewData(PERSON search[], float averageSalary, float averageKids, float highestSalary, float percentageWoman);
void saveFile(PERSON search[], float averageSalary, float averageKids, float highestSalary, float percentageWoman);
void manualRegister(PERSON search[]);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  PERSON search[POPULATION];

  int option;
  do {
    cout << "Deseja inserir manualmente ou por um arquivo.txt?" << endl;
    cout << "\t0 - Arquivo.txt | 1 - Manual" << endl;
    cout << "Sua opção: ";
    cin >> option;
  } while(option != 0 && option != 1);

  switch(option) {
    case 0: {
      loadFile(search);
      break;
    }
    case 1: {
      manualRegister(search);
      break;
    }
  }

  system("pause");
  system("cls");

  float averageSalary = 0, averageKids = 0, highestSalary = search[0].salary, percentageWoman = 0, woman = 0;
  for(int i = 0; i < POPULATION; i++){
    averageSalary += search[i].salary;
    averageKids += search[i].kids;
    if(search[i].salary >= highestSalary) highestSalary = search[i].salary;
    if(search[i].gender == 'F' || search[i].gender == 'f') {
      woman++;
      if(search[i].salary > 1000) {
        percentageWoman++;
      }
    }
  }

  averageSalary /= POPULATION;
  averageKids /= POPULATION;
  percentageWoman /= woman;

  int option2;
  do {
    cout << "Deseja salvar os dados em um arquivo.txt?" << endl;
    cout << "\t0 - Não Salvar | 1 - Salvar " << endl;
    cout << "Sua opção: ";
    cin >> option;
  } while(option2 != 0 && option2 != 1);

  switch(option) {
    case 0: {
      viewData(search, averageSalary, averageKids, highestSalary, percentageWoman);
      break;
    }
    case 1: {
      saveFile(search, averageSalary, averageKids, highestSalary, percentageWoman);
      break;
    }
  }
 
  cout << endl;
  return 0;
}

void viewData(PERSON search[], float averageSalary, float averageKids, float highestSalary, float percentageWoman) {
  system("pause");
  system("cls");
  cout << "Média de salário: " << fixed << setprecision(2) << averageSalary << endl;
  cout << "Média de filhos: " << fixed << setprecision(1) << averageKids << endl;
  cout << "Média de salarial de mulheres acima de 1000 reais: " << fixed << setprecision(1) << percentageWoman << endl;
}

void loadFile(PERSON search[]) {
  ifstream file("cadastro.txt");
  if(!file.is_open()) {
    cout << "Arquivo não encontrado." << endl;
  }else {
    int i = 0;
    while (file >> search[i].name >> search[i].salary >> search[i].age >> search[i].kids >> search[i].gender){
      cout << "Lendo " << i + 1 << "° cadastro." << endl;
      i++;
      if(i >= POPULATION) break;
    }
  }
  file.close();
}

void saveFile(PERSON search[], float avarageSalary, float avarageKids, float highestSalary, float percentageWoman) {
  ofstream file("dados.txt", ios::app);
  if(file.is_open()) {
    file << "Média de salário: " << fixed << setprecision(2) << avarageSalary << endl;
    file << "Média de filhos: " << fixed << setprecision(1) << avarageKids << endl;
    file << "Média de salarial de mulheres acima de 1000 reais: " << fixed << setprecision(1) << percentageWoman << endl << endl;
    file.close();
    cout << "Calculos realizados com sucesso, dados salvos no arquivo 'dados.txt'.";
  }
}

void manualRegister(PERSON search[]) {
  system("cls");
  for(int i = 0; i < POPULATION; i++) {
      cout << i + 1 << "° usuário: " << endl;
      cout << " - Primeiro Nome: ";
      cin >> search[i].name;
      cout << " - Salário: ";
      cin >> search[i].salary;
      cout << " - Idade: ";
      cin >> search[i].age;
      cout << " - Filhos: ";
      cin >> search[i].kids;
      cout << " - Gênero (M/F): ";
      cin >> search[i].gender;
      cout << endl;
  }
}