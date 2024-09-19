#include <1909_correcciontarea1.h>
#include <iostream>

SortNet::SortNet(int n){
    len = n;
    a = new int(len);   
}

SortNet::SortNet(int *a){
    this->len = sizeof(a)/sizeof(a[0]);
    this->a=new int(this->len);
    for(int i = 0; i<this->len;i++)
        this->a[i] = a[i];
}

SortNet::~SortNet(){
    delete[] a;
}

void SortNet::input(int *v){
    int n = sizeof(v)/sizeof(v[0]);
    if(n==len){
    for(int i = 0; i<len;i++)
        a[i] = v[i];
    }
}

void SortNet::print(){
    for(int i=0;i<len;i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

void SortNet::sort(){
    swap(0,1);
    swap(1,2);
    swap(0,2);
}

void SortNet::swap(int i, int j){
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}