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

	void add(const T&);
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
void add(const T& obj) {
	// get appropriate entry in table
	std::vector<T> bucket = table[hash(obj) % _size];
	// return if obj is already in bucket
	for (T t : bucket)
		if (t == obj) return;
	// add obj to
	bucket.push_back(obj);
}

template <typename T>
std::size_t HashMap<T>::hash(const T& obj) {
	return std::hash<T>{}(obj);
}

} // namespace dat

#endif