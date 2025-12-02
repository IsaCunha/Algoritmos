#include "../include/natal.hpp"
#include <vector>

using namespace std;

void conjunto_independente(int indice, int fim, 
    vector<int>& conjunto_parcial,
    vector<vector<bool>>& matriz, 
    vector<vector<int>>& resultado) {
    

    // Caso Base: todos os duendes foram verificados.
    if (indice == fim) {
        resultado.push_back(conjunto_parcial);
        return;
    }
    
    // Passa para o próximo duende.
    conjunto_independente(indice + 1, fim, conjunto_parcial, matriz, resultado);
    
    
    // É seguro adicionar o duende ao grupo.
    if (sem_briga(indice, conjunto_parcial, matriz) == true) {
        
        // Adicionamos o duende no grupo.
        conjunto_parcial.push_back(indice);
        // Exploramos ele em outros conjuntos;
        conjunto_independente(indice + 1, fim, conjunto_parcial, matriz, resultado);
        // Backtracking
        conjunto_parcial.pop_back();
    }
    

}

bool sem_briga(int indice, const vector<int>& conjunto_parcial, vector<vector<bool>>& matriz){
    for(size_t i = 0; i < conjunto_parcial.size(); i++) {
        if(matriz[indice][conjunto_parcial[i]] == false) {
            return false; 
        }
    }
    // Se não há brigas no grupo
    return true; 
}
