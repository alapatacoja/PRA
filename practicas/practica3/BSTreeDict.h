#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

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
		tree->print_inorder(out, dict.tree->root);
		return out;
	}

	V operator[](std::string key){
		return search(key);
	}

	void insert(std::string key, V value){
		TableEntry<V> entry(key, value);
		if(tree->search(key))
			throw std::runtime_error("la clave ya existe");
		tree->insert(entry);
	}

	V search(std::string key){
		BSNode<TableEntry<V>> *node = tree->search(root, TableEntry<V>(key,V()));
		if(node == nullptr)
			throw std::runtime_error("clave no encontrada");
		return node->elem.value;
	}

	V remove(std::string key){
			TableEntry<V> entry = tree->remove(key);
			if(entry.key.empty())
				throw std::runtime_error("clave no encontrada");
			return entry.value;
	}

	int entries(){
		return tree->size();
	}
        
};

#endif
