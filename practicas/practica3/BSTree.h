#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
		
using namespace std;

template <typename T> 
class BSTree {
    private:
       int nelem;
       BSNode<T>* root;

       BSNode<T>* search(BSNode<T>* node, T e) const {
            if (node == nullptr) {
               throw runtime_error("Element not found");
            } else if (node->elem < e){
                return search(node->right, e);
            } else if (node->elem > e){
                return search(node->left, e);
            } else {
                return node;
            }
       }

       BSNode<T>* insert(BSNode<T>* node, T e){
            if (node == nullptr){
               nelem++;
		    return new BSNode<T>(e);
            } else if (node->elem == e){
                throw runtime_error("Ya existe el elemento");
            } else if (node->elem < e){
                node->right = insert(node->right, e);
            } else {
                node->left = insert(node->left, e);
            }
            return node;
       }

       void print_inorder(ostream &out, BSNode<T>* node) const {
            if (node != nullptr) {
                print_inorder(out, node->left);
                out << node->elem << " ";
                //for(int i = 0; i < nelem - 1; i++){
                    print_inorder(out, node->right);
		    
                //}
            }
       }

        BSNode<T>* remove(BSNode<T>* n, T e){
            if(n == nullptr)
                throw runtime_error("elemento no encontrado");
            else if(n->elem < e)
                n->right = remove(n->right, e);
            else if(n->elem > e)
                n->left = remove(n->left, e);
            else {
                if(n->left != nullptr && n->right != nullptr){
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                } else {
                    n = (n->left != nullptr) ? n-> left : n->right;
		    nelem--;
                }
            }
            return n;
        }

        T max(BSNode<T>* n) const {
		if(n == nullptr)
			throw runtime_error("elemento no encontrado");
		else if(n->right != nullptr)
			return max(n->right);
		else
			return n->elem;
        }

        BSNode<T>* remove_max(BSNode<T>* n){
		if(n->right == nullptr)
		       return n->left;
		else{
			n->right = remove_max(n->right);
			return n;
		}	
        }

	void delete_cascade(BSNode<T> *n){
		if (n != nullptr) {
      	 	 	delete_cascade(n->left); 
        		delete_cascade(n->right);
			delete n; 
    		}	
	}

    public:
        BSTree(){
		nelem = 0;
            root = nullptr;
        }

        int size() const {
            return nelem;
        }

        T search(T e) const {
            return search(root, e)->elem;
        }

        T operator[](T e) const {
            return search(e);
        }

        void insert(T e){
            root = insert(root, e);
        }

        friend ostream& operator<<(ostream &out, const BSTree<T> &bst){
            bst.print_inorder(out, bst.root);
            return out;
        }

        void remove(T e){
            root = remove(root, e);
        }
   
       ~BSTree(){
       	delete_cascade(root);
       }	


};

#endif
