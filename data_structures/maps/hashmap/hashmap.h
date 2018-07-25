#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <vector>
#include <functional>

namespace dat
{

template <typename T>
class HashMap {
  public:
    HashMap(unsigned int);
    ~HashMap();

  private:
    std::size_t hash(const T&);

    std::vector<std::vector<T> > table;
    unsigned int _size;
};


template <typename T>
HashMap<T>::HashMap(unsigned int size) : _size(size) {
    table.resize(size);
}

template <typename T>
std::size_t HashMap<T>::hash(const T& obj) {
	return std::hash<T>{}(obj);
}

} // namespace dat

#endif