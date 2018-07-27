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
	T get(const K&);
	bool contains(const T&);
	bool containsKey(const K&);

	T& operator[](const K&);

  private:
	struct pair {
		K key;
		T val;
	};
	pair make_pair(K key, T val) { pair p; p.key=key; p.val=val; return p; }

    std::size_t hash(const K&);

    std::vector<std::vector<pair> > table;
    unsigned int _size;		// constant size to allocate table
	unsigned int _entries;	// updated number of entries put into the table
};


template <typename K, typename T>
HashMap<K,T>::HashMap() : _size(100), _entries(0) {
	table.resize(_size);
}

template <typename K, typename T>
HashMap<K,T>::HashMap(unsigned int size) : _size(size), _entries(0) {
    table.resize(_size);
}

template <typename K, typename T>
HashMap<K,T>::~HashMap() {
	// TODO finish destructor
}

template <typename K, typename T>
void HashMap<K,T>::add(const K& key, const T& val) {
	// get appropriate entry in table
	std::vector<pair> bucket = table[hash(key) % _size];
	// check if key already exists, exit if it does
	for (pair item : bucket) 
		if (item.key == key) return;
	// add obj to bucket
	bucket.push_back(make_pair(key, val));
	// update number of entries
	_entries++;
}


template <typename K, typename T>
T HashMap<K,T>::get(const K& key) {
	// find the appropriate entry in the table
	std::vector<pair> bucket = table[hash(key) % _size];
	// search for key
	for (pair item : bucket)
		if (item.key == key)
			return item.val;
	return NULL;
}


// returns the address of the item if it is in the map,
// otherwise it returns NULL
template <typename K, typename T>
T& HashMap<K,T>::operator[](const K& key) {
	// find appropriate entry in table
	std::vector<pair> bucket = table[hash(key) % _size];
	// search to see if key is present
	for (pair item : bucket)
		if (item.key == key)
			return &item.val;
	return NULL;
}


template <typename K, typename T>
bool HashMap<K,T>::contains(const T& val) {
	for (std::vector<pair> bucket : table) {
		if (bucket.empty()) continue;
		for (pair item : bucket) {
			if (item.val == T) return true;
		}
	}
	return false;
}

template <typename K, typename T>
bool HashMap<K,T>::containsKey(const K& key) {
	// find appropriate bucket
	std::vector<pair> bucket = table[hash(key) % _size];
	// search for key in keys
	for (pair item : bucket) 
		if (item.key == key) return true;
	return false;
}


template <typename K, typename T>
std::size_t HashMap<K,T>::hash(const K& obj) {
	return std::hash<K>{}(obj);
}

} // namespace dat

#endif