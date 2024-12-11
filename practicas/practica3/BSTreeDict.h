#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

using namespace std;

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
      BSTree<TableEntry<V>> *tree;

    public:
        BSTreeDict(){
		tree = new BSTree<TableEntry<V>>();
	}

	~BSTreeDict(){
		delete tree;
	}

	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
		
		out << *bs.tree << endl;		
		return out;
	}

	V operator[](std::string key){
		return search(key);
	}

	void insert(std::string key, V value){
		TableEntry<V> entry(key, value);
		tree->insert(entry);
	}

	V search(std::string key){
		TableEntry<V> node(key);
		TableEntry<V> aux = tree->search(node);
		return aux.value;
	}

	V remove(std::string key){
		TableEntry<V> node(key);
		TableEntry<V> aux = tree->search(node);
		tree->remove(node);
		return aux.value;
	}

	int entries(){
		return tree->size();
	}
        
};

#endif
