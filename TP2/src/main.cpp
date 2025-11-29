#include "../include/funcoes.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    // PARTE 1: Maior triângulo possível em um muro
    // Leitura da entrada

    int nColunas, tij;
    cin >> nColunas;
    
    // Constrói o vetor 'muro' e adiciona os valores de cada coluna.

    vector<int> muro(nColunas);

    for(int i = 0; i < nColunas; i++) {
        cin >> tij;
        muro[i] = tij;
    }
  
    // Desenvolvimento da solução

    // Constroi vetores para guardar a maior escada em cada lado.
    vector<int> escadaEsquerda(nColunas);
    vector<int> escadaDireita(nColunas);

    // Escada da esquerda: maior andar de escada que pode terminar em i
    for(int i = 0; i < nColunas; i++) {
        if (i == 0) {
            escadaEsquerda[i] = 1;
        } else {
            escadaEsquerda[i] = min_((escadaEsquerda[i -1] + 1), muro[i]); 
        }
    }

    // Escada da direita: maior lance de escada que pode começar em i
    for(int i = nColunas - 1; i >= 0; i--) {
        if (i == nColunas - 1) {
            escadaDireita[i] = 1;
        } else {
            escadaDireita[i] = min_((escadaDireita[i + 1] + 1), muro[i]);
        }
    }
    
    // Escolha gulosa: encontrar a maior altura possível
    int alturaMaxima = 0;
    
    for(int i = 0; i < nColunas; i++) {
        int maximoLocal = min_(escadaEsquerda[i], escadaDireita[i]);
        alturaMaxima = max_(alturaMaxima, maximoLocal);
    }

    cout << "Parte 1: " << alturaMaxima << endl;
    
    // PARTE 2: Área ambiental preservada com menor perimetro
    // Leitura da entrada

    int nArvores;     
    cin >> nArvores;

    vector<Arvore> coordenadas(nArvores);
    int x, y;

    for(int i = 0; i < nArvores; i++) {
        cin >> x >> y;
        coordenadas[i] = {x, y, i + 1};
    }

    // Desenvolvimento da solução

    mergeSort(coordenadas, 0, nArvores - 1, 'X');

    ArvoresEscolhidas trioEscolhido = div_conq(coordenadas, 0, nArvores - 1);

    cout << fixed << setprecision(4);
    cout << "Parte 2: " << trioEscolhido.perimetro << " " << trioEscolhido.arvore1 << " " << trioEscolhido.arvore2 << " " << trioEscolhido.arvore3 << endl;

    return 0;
}

