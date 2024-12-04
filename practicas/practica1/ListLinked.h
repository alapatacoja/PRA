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
			throw std::out_of_range("fuera de rango");
		}

		resize(n + 1);
		
		for (int i = n; i > pos; --i) {
			arr[i] = arr[i - 1];
		}

		arr[pos] = e;
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

		T e = arr[pos];
		for (int i = pos; i < n - 1; ++i) {
			arr[i] = arr[i + 1];
		}

		--n;

		resize(n - 1);

		return e;
	}

	T get(int pos){
		return T[pos];
	}

	int search(T e){
		for (int i = 0; i < n; ++i) {
			if (arr[i] == e) {
				return i;
			}
		}
		return -1;
	}

	bool empty(){
		if(sizeof(arr)==0)
			return true;
		else 
			return false;
	}

	int size(){
		return sizeof(arr);
	}

	void resize(int new_size){
		T* new_arr = new T[new_size];

		for (int i = 0; i < n; i++) {
			new_arr[i] = arr[i];
		}

		delete[] arr;
		arr = new_arr;
		n = new_size;
	}
};