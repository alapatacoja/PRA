#include <iostream>
#include <vector>

using namespace std;

class Ordenacion {

   private:
   //atributos
    vector<int> vec;
    int size;

    public:
    //constructor y destructor
    Ordenacion(int size){
        this->size = size;
        vec = vector<int>(size);
    }

    ~Ordenacion(){}

    //input: para proporcionar el contenido del vector
    void input(){
        for(int i = 0; i < size; i++){
            cout << "introduce un valor entero positivo: ";
            cin >> vec[i];
        }
    }

    //sort: para aplicar la red de ordenación asociada
    void sort(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - 1; j++){
                if(vec[j] > vec[j+1]){
                    swap(vec[j], vec[j+1]);
                }
            }
        }
    }


    //print: para imprimir el contenido del vector.
    void print(){
        for(int i = 0; i < size; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //swap: método que implementa un circuito de intercambio individual
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

};

int main() {
    // Ejemplo de uso de la clase Ordenacion
    int vectorSize = 5;
    Ordenacion ordenacion(vectorSize);

    ordenacion.input();

    std::cout << "antes: ";
    ordenacion.print();

    ordenacion.sort();

    std::cout << "despues: ";
    ordenacion.print();

    return 0;
}