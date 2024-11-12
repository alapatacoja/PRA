#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
		int max;
		int n;
		static const int MINSIZE;

    public:

	void insert(int pos, T e){
		if (pos < 0 || pos > n) {
			throw std::out_of_range("fuera de rango");
		}

		resize(max + 1);
		
		for (int i = n; i > pos; --i) {
			arr[i] = arr[i - 1];
		}

		arr[pos] = e;
		++n;
	}

	void append(T e){
		if (n == max) {
			resize(max + 1);
		}
		arr[n] = e;
		++n;
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
		if (n < max / 4) {
			resize(max - 1);
		}

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


	ListArray(){
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
	}

	~ListArray(){
		delete[] arr;
	}
	
	T operator[](int pos){
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("fuera de rango");
		}
		return arr[pos];
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		for (int i = 0; i < list.n; i++) {
			out << list.arr[i] << " ";
		}
		return out;
	}

	void resize(int new_size){
		T* new_arr = new T[new_size];

		for (int i = 0; i < n; i++) {
			new_arr[i] = arr[i];
		}

		delete[] arr;
		arr = new_arr;
		max = new_size;
	}
	// miembros públicos, incluidos los heredados de List<T>
};