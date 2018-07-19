#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

namespace dat {

template <typename T>
class LLNode {
    public:
        LLNode* left;
        LLNode* right;
        T val;
};

template <typename T>
class linkedlist {
    public:

    typedef LLNode* iterator;

    linkedlist();
    linkedlist(const linkedlist&);
    ~linkedlist();

    void push_back(const T&);
    void push_front(const T&);
    void insert_after(const T&);
    void insert_before(const T&);
    
    T pop_front();
    T pop_back();
    LLNode* find(T);

    iterator begin() { return sentinel->right; }
    iterator end() { return sentinel; }
    iterator rbegin() { return sentinel->left; }
    iterator rend() { return sentinel; }

    bool empty() { return _size == 0; }
    unsigned int size() { return _size; }

    private:
        LLNode *sentinel;
        unsigned int _size;
};

}


#endif