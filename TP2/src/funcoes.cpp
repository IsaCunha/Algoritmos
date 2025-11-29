#include "../include/funcoes.hpp"
#include <vector>
#include <cmath>
    
int min_(int a, int b) {
    if(a < b) {
        return a;
    } 
    else {
        return b;   
    }
}

int max_(int a, int b) {
    if(a > b) {
        return a;
    }
    else {
        return b;   
    }
}

double distanciaEuclidiana(Arvore pontoA, Arvore pontoB) {

    double dist_X = pontoB.eixo_X - pontoA.eixo_X;
    double dist_Y = pontoB.eixo_Y - pontoA.eixo_Y;

    return std::sqrt((dist_X * dist_X) + (dist_Y * dist_Y));
}

double perimetro3Pontos(Arvore a, Arvore b, Arvore c) {
    return distanciaEuclidiana(a, b) + distanciaEuclidiana(b, c) + distanciaEuclidiana(c, a);
}

void ArvoresEscolhidas::ordenaArvore() {
    // Ordena os índices das árvores em ordem crescente
    if (arvore1 > arvore2) std::swap(arvore1, arvore2);
    if (arvore1 > arvore3) std::swap(arvore1, arvore3);
    if (arvore2 > arvore3) std::swap(arvore2, arvore3);
}

ArvoresEscolhidas menorPerimetro(ArvoresEscolhidas a, ArvoresEscolhidas b) {
    if(a.perimetro < b.perimetro) {
        return a;
    } 
    else if(a.perimetro > b.perimetro) {
        return b;   
    }
    else { // a.perimetro == b.perimetro

        a.ordenaArvore();
        b.ordenaArvore();

        // Compara o primeiro ID:
        if (a.arvore1 < b.arvore1) return a;
        if (b.arvore1 < a.arvore1) return b;

        // Compara o segundo ID:
        if (a.arvore2 < b.arvore2) return a;
        if (b.arvore2 < a.arvore2) return b;

        // Compara o terceiro ID:
        if (a.arvore3 < b.arvore3) return a;
        
        // Se tudo for igual, retorna 'a'
        return a;
        
    }
}


ArvoresEscolhidas casoBase(std::vector<Arvore>& pontos, int inicio, int fim) {
    ArvoresEscolhidas melhorCaso;

    for(int i = inicio; i <= fim - 2; i++) {
        for(int j = i + 1; j <= fim - 1; j++) {
            for(int k = j + 1; k <= fim; k++) {
                double perimetroAtual = perimetro3Pontos(pontos[i], pontos[j], pontos[k]);
                if(perimetroAtual <= melhorCaso.perimetro) {
                    melhorCaso.perimetro = perimetroAtual;
                    melhorCaso.arvore1 = pontos[i].indiceEntrada;
                    melhorCaso.arvore2 = pontos[j].indiceEntrada;
                    melhorCaso.arvore3 = pontos[k].indiceEntrada;

                    melhorCaso.ordenaArvore();
                }
            }
        }
    }
    return melhorCaso;
}

ArvoresEscolhidas casoFaixaDivisoria(std::vector<Arvore>& pontos, ArvoresEscolhidas melhorPerimetroBloco) {
    
    ArvoresEscolhidas melhorCaso = melhorPerimetroBloco;
    double min_perimetro = melhorPerimetroBloco.perimetro;
    size_t tamanho = pontos.size();

    for (size_t i = 0; i < tamanho; i++) {
        for(size_t j = i + 1; j < tamanho; j++) {
            for(size_t k = j + 1; k < tamanho; k++) {
                if((pontos[k].eixo_Y - pontos[i].eixo_Y) >= (min_perimetro / 2)) {
                    break;
                }
                double perimetroAtual = perimetro3Pontos(pontos[i], pontos[j], pontos[k]);
                if(perimetroAtual < melhorCaso.perimetro) {
                    melhorCaso.perimetro = perimetroAtual;
                    melhorCaso.arvore1 = pontos[i].indiceEntrada;
                    melhorCaso.arvore2 = pontos[j].indiceEntrada;
                    melhorCaso.arvore3 = pontos[k].indiceEntrada;

                    min_perimetro = perimetroAtual;
                }
            }
        }
    }
    melhorCaso.ordenaArvore();
    return melhorCaso;
}

ArvoresEscolhidas div_conq(std::vector<Arvore>& pontos, int inicio, int fim) {
    int tamanho = fim - inicio + 1;

    if(tamanho <= 6) {
        return casoBase(pontos, inicio, fim);
    }

    int meio = inicio + (fim - inicio) / 2;
    Arvore pontoMedio = pontos[meio];

    ArvoresEscolhidas dl = div_conq(pontos, inicio, meio);
    ArvoresEscolhidas dr = div_conq(pontos, meio + 1, fim);

    ArvoresEscolhidas d = menorPerimetro(dl, dr);

    std::vector<Arvore> pontosDivisoria;
    for(int i = inicio; i <= fim; i++) {
        if(std::abs(pontos[i].eixo_X - pontoMedio.eixo_X) < (d.perimetro)) {
            pontosDivisoria.push_back(pontos[i]);
        }
    }

    mergeSort(pontosDivisoria, 0, (int)pontosDivisoria.size() - 1, 'Y');
    ArvoresEscolhidas d_faixa = casoFaixaDivisoria(pontosDivisoria, d);

    return menorPerimetro(d, d_faixa);
}

void merge(std::vector<Arvore>& pontos, int esquerda, int meio, int direita, char eixo) {

    int tamanhoEsq = meio - esquerda + 1;
    int tamanhoDir = direita - meio;

    std::vector<Arvore> E(tamanhoEsq);

    for(int i = 0; i < tamanhoEsq; i++) {
        E[i] = pontos[esquerda + i];
    }

    std::vector<Arvore> D(tamanhoDir);

    for(int i = 0; i < tamanhoDir; i++) {
        D[i] = pontos[meio + 1 + i];
    }

    int i = 0, j = 0;
    int k = esquerda;

    while(i < tamanhoEsq && j < tamanhoDir) {

        bool define_eixo_X;

        if (eixo == 'X') {
            if(E[i].eixo_X != D[j].eixo_X) {
                define_eixo_X = (E[i].eixo_X <= D[j].eixo_X);
            }
            else
            define_eixo_X = (E[i].eixo_Y <= D[j].eixo_Y);

        } else {
            if(E[i].eixo_Y != D[j].eixo_Y) {
                define_eixo_X = (E[i].eixo_Y <= D[j].eixo_Y);
            } 
            else {
                define_eixo_X = (E[i].eixo_X <= D[j].eixo_X);
            }
        }

        if (define_eixo_X) {
            pontos[k] = E[i];
            i++;
        } else {
            pontos[k] = D[j];
            j++;
        }
        k++;
    }

    while(i < tamanhoEsq) {
        pontos[k] = E[i];
        i++;
        k++;
    }

    while(j < tamanhoDir) {
        pontos[k] = D[j];
        j++;
        k++;
    }

}

void mergeSort(std::vector<Arvore>& pontos, int inicio, int fim, char eixo) {
    if (inicio >= fim) {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    mergeSort(pontos, inicio, meio, eixo);
    mergeSort(pontos, meio + 1, fim, eixo);
    merge(pontos, inicio, meio, fim, eixo);

}


