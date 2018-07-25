#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <vector>

namespace dat
{

template <typename T>
class HashMap {
  public:
    HashMap(unsigned int);
    ~HashMap();

  private:
    void hash(const T&);

    std::vector<std::vector<T> > table;
    unsigned int _size;
};


template <typename T>
HashMap<T>::HashMap(unsigned int size) : _size(size) {
    table.resize(size);
}

template <typename T>
void HashMap<T>::hash(const T& obj) {

}

} // namespace dat

#endif