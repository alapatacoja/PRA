#include <vector>
#include "DyV.h"

int main(){
    std::vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> V_INV = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int X = 5;
    int ini = 0;
    int fin = V.size() - 1;
    int result = BusquedaBinaria_vector(X, V, ini, fin);
    int result_INV = BusquedaBinaria_INV(X, V_INV, ini, fin);
    return 0;
}