#include <iostream>
#include <vector>

using namespace std;

const max_duendes = 41;
bool matriz_relacoes[max_duendes][max_duendes];

int main() {

    int duendes, brigas;
    cin >> duendes >> brigas;

    memset(matriz_relacoes, true, sizeof(matriz_relacoes));
    int brigao1, brigao2;
    
    for(int i = 0; i < brigas; i++) {
        
        cin >> brigao1 >> brigao2;
        matriz_relacoes[brigao1][brigao2] = false;
        matriz_relacoes[brigao2][brigao1] = false; 

    }

    int totalEquipe;
    vetor<int> equipe;

    cout << totalEquipe << "\n" << endl;
    for(int i = 0; i < totalEquipe, i++) {
        cout << equipe[i] << " " <<endl;
    }
}