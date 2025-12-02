#include <iostream>
#include <vector>
#include "../include/natal.hpp"

using namespace std;

int main() {

    int duendes, brigas;
    cin >> duendes >> brigas;

    vector <vector<bool>> relacoes(duendes, vector<bool>(duendes, true)); 

    int brigao1, brigao2;
/*
    cout << "Momento 1: " << endl;

    for(int i = 0; i < duendes; i++) {
        for(int j = 0; j < duendes; j++) {
            cout << "[" << i << j << "]: " << relacoes[i][j] << " " ;
        }
    }
    cout << " " << endl;
*/    
    
    for(int i = 0; i < brigas; i++) {
        
        cin >> brigao1 >> brigao2;
        relacoes[brigao1][brigao2] = false;
        relacoes[brigao2][brigao1] = false; 

    }

/*
    cout << "Matriz 2: " << endl;
    for(int i = 0 ; i < duendes; i++) {
        for(int j = 0; j < duendes; j++) {
            cout << "[" << i << j << "]: " << relacoes[i][j] << " " ;
        }
    }
*/

    int meio = (duendes - 1) / 2;

    int grupo1 = meio + 1;
    
    vector<int> equipe_parcial;
    vector<vector<int>> equipe1, equipe2;

    conjunto_independente(0, grupo1, equipe_parcial, relacoes, equipe1);
    conjunto_independente(grupo1 + 1, duendes, equipe_parcial, relacoes, equipe2);

    int totalEquipe = 0;
    vector<int> resultado;

    cout << totalEquipe << endl;
    for(int i = 0; i < totalEquipe; i++) {
        cout << resultado[i] << " " <<endl;
    }

    
    
}