#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
        int n;

    public:

        ListLinked(){
            first = nullptr;
            n = 0;
        }

        ~ListLinked(){
            Node<T>* aux = first;
            while (aux != nullptr){
                Node<T>* next = aux->next;
                delete aux;
                aux = next;
            }
        }

        T operator[](int pos){
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("fuera de rango");
            }

            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }

            return aux->data;
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
            Node<T>* aux = list.first;
            while (aux != nullptr){
                out << aux->data << " ";
                aux = aux->next;
            }
            return out;
        }

        void insert(int pos, T e){
			if (pos < 0 || pos > n) {
				throw std::out_of_range("Position out of range");
			}

			Node<T>* newNode = new Node<T>(e);

			if (pos == 0) {
				newNode->next = first;
				first = newNode;
			} else {
				Node<T>* aux = first;
				for (int i = 0; i < pos - 1; ++i) {
					aux = aux->next;
				}
				newNode->next = aux->next;
				aux->next = newNode;
			}

			++n;
		}

	void append(T e){
		insert(n, e);
	}

	void prepend(T e){
		insert(0, e);
	}

	T remove(int pos){
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Position out of range");
		}

		Node<T>* aux = first;
		if (pos == 0) {
			first = first->next;
			T data = aux->data;
			delete aux;
			--n;
			return data;
		}

		for (int i = 0; i < pos - 1; ++i) {
			aux = aux->next;
		}

		Node<T>* toDelete = aux->next;
		aux->next = toDelete->next;
		T data = toDelete->data;
		delete toDelete;
		--n;
		return data;
	}

	T get(int pos){
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Position out of range");
		}

		Node<T>* aux = first;
		for (int i = 0; i < pos; ++i) {
			aux = aux->next;
		}

		return aux->data;
	}

	int search(T e){
		Node<T>* aux = first;
		for (int i = 0; i < n; ++i) {
			if (aux->data == e) {
				return i;
			}
			aux = aux->next;
		}
		return -1;
	}

	bool empty(){
		return n == 0;
	}

	int size(){
		return n;
	}

};