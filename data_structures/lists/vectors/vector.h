#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace dat {

// vector declaration
template <typename T>
class vector {
   public:
    typedef T *iterator;

    vector();
    vector(unsigned int size);
    vector(unsigned int size, unsigned int initial);
    vector(const vector<T> &v);
    ~vector();

    unsigned int size() { return _size; }
    bool empty() { return _size == 0; }
    void push_back(T);
    vector<T> pop_back();

   private:
    // the number of elements currently in the vector
    unsigned int _size;
    // the max amount of memory allocated to the vector
    unsigned int _capacity;
    const double capacityGrowth = 1.6;
    char *buffer;
};

// vector definition
template <typename T>
vector<T>::vector()
    : _size(0), _capacity(1), _buffer(new char[sizeof(T) * _capacity]) {}

template <typename T>
vector<T>::vector(unsigned int size)
    : _size(size),
      _capacity(capacityGrowth * size),
      _buffer(new char[sizeof(T) * _capacity]) {}

template <typename T>
vector<T>::vector(const vector<T> &v) {
    *this = v;
}

template <typename T>
vector<T>::~vector<T>() {
    delete buffer;
}

template <typename T>
void vector<T>::push_back(T obj) {}

}  // namespace dat

#endif