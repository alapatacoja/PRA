#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
       int nelem;
       BSNode<T>* root;

       BSNode<T>* search(BSNode<T>* node, T e) const {
            if (node == nullptr) {
               throw std::runtime_error("Element not found");
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
                return new BSNode<T>(e);
            } else if (node->elem == e){
                throw std::runtime_error("Ya existe el elemento");
            } else if (node->elem < e){
                node->right = insert(node->right, e);
            } else {
                node->left = insert(node->left, e);
            }
            return node;
       }

       void print_inorder(std::ostream &out, BSNode<T>* node) const {
            if (node != nullptr) {
                print_inorder(out, node->left);
                out << node->elem << " ";
                for(int i = 0; i < nelem - 1; i++){
                    print_inorder(out, i);
                }
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

        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
            out << bst.root;
            return out;
        }
    
};

#endif