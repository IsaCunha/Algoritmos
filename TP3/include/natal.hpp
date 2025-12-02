#ifndef NATAL_HPP
#define NATAL_HPP

#include <vector>
using namespace std;

void conjunto_independente(int indice, int fim, vector<int>& conjunto_parcial, vector<vector<bool>>& matriz, vector<vector<int>>& resultado);
bool sem_briga(int indice, const vector<int>& conjunto_parcial, vector<vector<bool>>& matriz);

#endif