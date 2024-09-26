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
		
	}

	void append(T e){

	}

	void prepend(T e){

	}

	T remove(int pos){

	}

	T get(int pos){
		return T[pos];
	}

	int search(T e){
		
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
		arr[M]
	}

	~ListArray(){
	
	}
	
	T operator[](int pos){
	
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	
	}

	void resize(int new_size){

	}
	// miembros públicos, incluidos los heredados de List<T>
  
}
