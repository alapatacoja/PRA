#ifndef DICT_H
#define DICT_H
#include <string>

template <typename V> 
class Dict {
    public:
        void insert(const std::string key, const V val);

        V search(std::string key);

        V remove(std::string key);

        int entries();
};

#endif