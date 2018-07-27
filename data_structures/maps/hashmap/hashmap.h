#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <vector>
#include <functional>

namespace dat
{

template <typename K, typename T>
class HashMap {
  public:
	HashMap();
    HashMap(unsigned int);
    ~HashMap();

	void add(const K&, const T&);
	bool contains(const T&);

	T& operator[](const K&);

  private:
	struct pair {
		K key;
		T val;
	};
	pair make_pair(K key, T val) { pair p; p.key=key; p.val=val; return p; }

    std::size_t hash(const K&);

	std::vector<K> keys;
    std::vector<std::vector<pair> > table;
    unsigned int _size;
};


template <typename K, typename T>
HashMap<K,T>::HashMap() : _size(100) {
	table.resize(_size);
}

template <typename K, typename T>
HashMap<K,T>::HashMap(unsigned int size) : _size(size) {
    table.resize(_size);
}

template <typename K, typename T>
HashMap<K,T>::~HashMap() {
	// TODO finish destructor
}

template <typename K, typename T>
void HashMap<K,T>::add(const K& key, const T& val) {
	// return if we already have the key
	for (K k : keys) 
		if (k == key) return;
	keys.push_back(key);
	// get appropriate entry in table
	std::vector<T> bucket = table[hash(key) % _size];
	// add obj to
	bucket.push_back(pair {K, T});
}


// returns the address of the item if it is in the map,
// otherwise it returns NULL
template <typename K, typename T>
T& HashMap<K,T>::operator[](const K& key) {
	// find appropriate entry in table
	std::vector<T> bucket = table[hash(key) % _size];
	// search to see if key is present
	for (std::vector<pair> item : bucket)
		if (item.key == key)
			return &item.val;
	return NULL;
}


template <typename K, typename T>
std::size_t HashMap<K,T>::hash(const K& obj) {
	return std::hash<K>{}(obj);
}

} // namespace dat

#endif