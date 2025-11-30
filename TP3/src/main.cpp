#include <iostream>
#include <vector>
#include "../include/natal.hpp"

using namespace std;

const max_duendes = 41;
bool matriz_relacoes[max_duendes][max_duendes];

int main() {

    int duendes, brigas;
    cin >> duendes >> brigas;

    // preenche a matriz completa com 'true', indicando que aquele par de duendes tem boa relação
    memset(matriz_relacoes, true, sizeof(matriz_relacoes));
    int brigao1, brigao2;
    
    for(int i = 0; i < brigas; i++) {
        
        cin >> brigao1 >> brigao2;
        matriz_relacoes[brigao1][brigao2] = false;
        matriz_relacoes[brigao2][brigao1] = false; 

    }

    int meio = (duendes - 1) / 2;

    int grupo1 = meio + 1;
    int grupo2 = duendes - grupo1; 
    
    
    vector<int> equipe_parcial;
    vector<vector<int>> equipe1, equipe2;

    conjunto_independente(0, grupo1, equipe_parcial, matriz_relacoes, equipe1);
    conjunto_independente(grupo1, duendes, equipe_parcial, matriz_relacoes, equipe2);

    int totalEquipe;
    vector<int> resultado;

    cout << totalEquipe << "\n" << endl;
    for(int i = 0; i < totalEquipe; i++) {
        cout << resultado[i] << " " <<endl;
    }
}