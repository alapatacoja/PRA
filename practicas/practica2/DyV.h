#include<vector>

template <typename T>
int BusquedaBinaria(int X, T V[], int ini, int fin) {
    if (ini > fin) {
        return -1; 
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return BusquedaBinaria(X, V, ini, medio - 1);
    } else {
        return BusquedaBinaria(X, V, medio + 1, fin);
    }
}

template <typename T>
int BusquedaBinaria_vector(int X, std::vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1; 
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return BusquedaBinaria_vector(X, V, ini, medio - 1);
    } else {
        return BusquedaBinaria_vector(X, V, medio + 1, fin);
    }
}

template <typename T>
int BusquedaBinaria_INV(int X,  std::vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1; 
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] < X) {
        return BusquedaBinaria_INV(X, V, ini, medio - 1);
    } else {
        return BusquedaBinaria_INV(X, V, medio + 1, fin);
    }
}

template <typename T>
void QuickSort(T V[], int ini, int fin){
    if(ini<fin){
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot-1);
        QuickSort(V, pivot+1, fin);
    }
}

template <typename T>
int Partition(T V[], int ini, int fin ){
    T x = V[fin];
    int i = ini;
    for(int j = ini; j < fin; j++){
        if(V[j] <= x){
            swap(V[i], V[j]);
            i++;
        }
    }
    swap(V[i], V[fin]);
    return i;
}