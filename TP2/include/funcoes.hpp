#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <utility>
#include <vector>

// PARTE 1: Declarações das funções min e max
int min_(int a, int b);
int max_(int a, int b);

// PARTE 2: Declarações das estruturas e funções para o cálculo do menor perímetro

struct Arvore {
    int eixo_X;
    int eixo_Y;
    int indiceEntrada;

};

struct ArvoresEscolhidas {
    double perimetro = 1e18;
    int arvore1 = -1;
    int arvore2 = -1;
    int arvore3 = -1;

    void ordenaArvore();
};

double distanciaEuclidiana(Arvore pontoA, Arvore pontoB);
double perimetro3Pontos (Arvore a, Arvore b, Arvore c);
ArvoresEscolhidas menorPerimetro(ArvoresEscolhidas a, ArvoresEscolhidas b);
ArvoresEscolhidas casoBase(std::vector<Arvore>& pontos, int inicio, int fim);
ArvoresEscolhidas div_conq(std::vector<Arvore>& pontos, int inicio, int fim);

// Implementação do MergeSort 
void merge(std::vector<Arvore>& pontos, int esquerda, int meio, int direita, char eixo);
void mergeSort(std::vector<Arvore>& pontos, int inicio, int fim, char eixo);

#endif // FUNCOES_HPP