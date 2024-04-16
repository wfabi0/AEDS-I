// Bob trabalha no OBM (Órgão Brasileiro de Meteorologia), que é a organização responsável pela
// medição dos índices pluviométricos (quantidade de chuva acumulada) em todo o país. Eles são muito
// eficientes no que fazem, mas estão com um problema: eles não sabem como proceder para calcular a
// quantidade acumulada de chuva que caiu em cada região em dois períodos consecutivos, muito embora eles
// saibam os dados de cada período separadamente.
// Como a chefia do Órgão estava muito ocupada, acabou ficando a cargo de Bob, o estagiário, a tarefa de
// implementar um programa que some, para cada região, a quantidade de chuva acumulada em dois períodos
// consecutivos.
// O mapa que o OBM usa é dividido em N×N regiões, sendo que para cada região, a cada período, é
// determinado um número inteiro indicando a quantidade de chuva acumulada. A quantidade de chuva
// acumulada total em cada região em dois períodos consecutivos é a soma das quantidades de chuva em cada
// um dos períodos.
// Mas como Bob é só um estagiário e não está acostumado a fazer nada mais do que tirar cópias de
// documentos, ele pediu sua ajuda para implementar o programa que calcula a quantidade de chuva acumulada
// total nos dois períodos para cada uma das regiões, dadas as quantidades de chuva acumulada em cada
// período para cada região.
// - Entrada -
// A primeira linha da entrada contém um inteiro N indicando a dimensão dos dois mapas que devem ser lidos.
// Nas próximas 2N linhas são dados os dois mapas, cada mapa indicando a quantidade de chuva acumulada
// nas regiões em um período. Cada mapa é descrito em N linhas consecutivas, cada linha contendo N inteiros,
// sendo que cada inteiro indica a quantidade de chuva acumulada, no período, em uma região.
// - Saída -
// A saída deverá conter N linhas, com N inteiros em cada linha, indicando a quantidade de chuva acumulada
// total em cada uma das regiões nos dois períodos considerados.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

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

  return 0;
}