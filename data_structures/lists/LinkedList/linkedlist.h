#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

namespace dat {

template <typename T>
class linkedlist {
   private:
    class Node {
       public:
        Node* left;
        Node* right;
        T val;
    };

    unsigned int _size;
    Node* sentinel;

    Node* find(const T& val);

   public:
    typedef Node* iterator;

    linkedlist();
    linkedlist(const linkedlist&);
    ~linkedlist();
    linkedlist<T>& operator=(const linkedlist&);

    void push_back(const T&);
    void push_front(const T&);
    void insert_after(const T&, const T&);
    void insert_before(const T&, const T&);

    T pop_front();
    T pop_back();

    iterator begin() { return sentinel->right; }
    iterator end() { return sentinel; }
    iterator rbegin() { return sentinel->left; }
    iterator rend() { return sentinel; }

    bool empty() { return _size == 0; }
    unsigned int size() { return _size; }
};

// implementation
template <typename T>
linkedlist<T>::linkedlist() : _size(0), sentinel(new Node) {
    sentinel->right = sentinel;
    sentinel->left = sentinel;
}

template <typename T>
linkedlist<T>::linkedlist(const linkedlist<T>& copy) : _size(copy.size()) {
    // TODO finish copy constructor
}

template <typename T>
linkedlist<T>& linkedlist<T>::operator=(const linkedlist<T>& val) {
    // TODO finish copy operator
    return NULL;
}

template <typename T>
linkedlist<T>::~linkedlist() {
    for (iterator i = begin(); i != end(); i = i->right) delete i;
    delete sentinel;
}

template <typename T>
void linkedlist<T>::push_back(const T& val) {
    // create the new node with the given value
    Node* n = new Node;
    n->val = val;

    // attach new node to right of previous back
    Node* back = sentinel->left;
    back->right = n;
    n->left = back;

    // attach new node to front of sentinel
    n->right = sentinel;
    sentinel->left = n;
    _size++;
}

template <typename T>
void linkedlist<T>::push_front(const T& val) {
    // create the node with the given value
    Node* n = new Node;
    n->val = val;

    // attach new node to left of previous front
    Node* front = sentinel->right;
    front->left = n;
    n->right = front;

    // attach new node to right of sentinel
    n->left = sentinel;
    sentinel->right = n;
    _size++;
}

template <typename T>
T linkedlist<T>::pop_back() {
    Node* popped = sentinel->left;

    // connect sentinel with new back
    popped->left->right = sentinel;
    sentinel->left = popped->left;

    // delete node as it is being removed
    T val = popped->val;
    delete popped;

    return val;
}

template <typename T>
T linkedlist<T>::pop_front() {
    Node* popped = sentinel->right;

    // connect sentinel with new front
    popped->right->left = sentinel;
    sentinel->right = popped->right;

    // delete node as it is being removed
    T val = popped->val;
    delete popped;

    return val;
}

template <typename T>
void linkedlist<T>::insert_after(const T& newVal, const T& leftVal) {
    Node* ins = new Node;
    ins->val = newVal;
    Node* left = find(leftVal);

    ins->right = left->right;
    left->right = ins;
    ins->left = left;
}

template <typename T>
void linkedlist<T>::insert_before(const T& newVal, const T& rightVal) {
    Node* ins = new Node;
    ins->val = rightVal;
    Node* right = find(rightVal);

    ins->left = right->left;
    right->left = ins;
    ins->right = right;
}

template <typename T>
typename linkedlist<T>::Node* linkedlist<T>::find(const T& val) {
    for (iterator i = begin(); i != end(); i = i->right)
        if (i->val == val) return val;
    return NULL;
}

}  // namespace dat

#endif