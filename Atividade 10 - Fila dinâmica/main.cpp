#include <iostream>
#include <windows.h>

using namespace std;

struct Item {
  int valor;
  Item *prox;
};

struct Fila {
  Item *inicio;
  Item *fim;
};

Fila *fila = NULL;

void menu(); void inserir(); void remover(); void listar(); void limpar();
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int opcao;
  do {
    menu();
    cin >> opcao;
    switch (opcao) {
      case 1: {
        inserir();
        break;
      }
      case 2: {
        remover();
        break;
      }
      case 3: {
        listar();
        break;
      }
      case 4: {
        limpar();
        break;
      };
      default: {
        cout << "Opção inválida!" << endl;
        break;
      }
    }
  } while (opcao != 0);
 
  cout << endl << endl;
  return 0;
}

void menu() {
  cout << endl;
  cout << "1 - Inserir" << endl;
  cout << "2 - Remover" << endl;
  cout << "3 - Listar" << endl;
  cout << "4 - Limpar" << endl;
  cout << "5 - Sair" << endl;
  cout << "Opção: ";
}

void inserir() {
  Item *item = new Item;
  cout << "Digite o valor: ";
  cin >> item->valor;
  item->prox = NULL;
  if(fila == NULL) {
    fila = new Fila;
    fila->inicio = item;
    fila->fim = item;
  } else {
    fila->fim->prox = item;
    fila->fim = item;
  }
}

void remover() {
  if(fila == NULL) {
    cout << "Fila vazia."  << endl;
  }else {
    Item *item = fila->inicio;
    fila->inicio = item->prox;
    delete item;
    cout << "Item removido." << endl;
  }
}

void listar() {
  if(fila == NULL) {
    cout << "Fila vazia.";
  } else {
    Item *item = fila->inicio;
    int counter = 1;
    while(item != NULL) {
      cout << counter << "° " << item->valor << endl;
      item = item->prox;
      counter++;
    }
  }
}

void limpar() {
  if(fila == NULL) {
    cout << "Fila vazia" << endl;
  } else {
    Item *item = fila->inicio;
    while(item != NULL) {
      Item *temp = item;
      item = item->prox;
      delete temp;
    }
    delete item;
    fila = NULL;
    cout << "Fila limpa." << endl;
  }
}