#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../practica1/ListLinked.h"  
template <typename V>
class HashTable: public Dict<V> {
private:
    int n;
    int max;
    ListLinked<TableEntry<V>>* table;

    int h(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return (sum % max + max) % max;
    }

public:
    HashTable(int size) {
        if (size <= 0) throw std::invalid_argument("Tamaño inválido");
        table = new ListLinked<TableEntry<V>>[size];
        max = size;
        n = 0;
    }

    ~HashTable() {
        delete[] table;
    }

    int capacity() {
        return max;
    }

    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& th) {
        for (int i = 0; i < th.max; i++) {
            out << i << ": " << th.table[i] << std::endl;
        }
        return out;
    }

    V operator[](std::string key) {
    int temp = h(key);
    for (int i = 0; i < table[temp].size(); i++) {
        if (table[temp][i].key == key) {
            return table[temp][i].value;
        }
    }
    throw std::runtime_error("Key does not exist");
}


    void insert(const std::string key, const V val) {
    int temp = h(key);
    // Busca si ya existe una entrada con la misma clave
    for (int i = 0; i < table[temp].size(); i++) {
        if (table[temp][i].key == key) {
            throw std::runtime_error("Key already exists");
        }
    }
    // Inserta la nueva clave-valor
    TableEntry<V> entry(key, val);
    table[temp].insert(0, entry);
    n++;
}


    V search(const std::string& key) {
        int temp = h(key);
        if (table[temp].empty()) {
            throw std::runtime_error("No se encontró la clave");
        }

        for (int i = 0; i < table[temp].size(); i++) {
            if (table[temp][i].key == key) {
                return table[temp][i].value;
            }
        }
        throw std::runtime_error("No se encontró la clave");
    }

    V remove(const std::string& key) {
        int temp = h(key);
        if (table[temp].empty()) {
            throw std::runtime_error("No se encontró la clave");
        }

        for (int i = 0; i < table[temp].size(); i++) {
            if (table[temp][i].key == key) {
                V val = table[temp][i].value;
                table[temp].remove(i);
                n--;
                return val;
            }
        }
        throw std::runtime_error("No se encontró la clave");
    }

    int entries() {
        return n;
    }
};

#endif // HASHTABLE_H
