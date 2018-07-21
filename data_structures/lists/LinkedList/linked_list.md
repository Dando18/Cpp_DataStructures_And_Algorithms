### LINKED LISTS ###
---------------------
Linked lists are unique in that elements are not stored in a numerically ordered fashion, but rather in relation to their surrouding elements. Each element, or `Node`, is stored in relation to a left link and a right link.
``` c++
class Node {
    T val;
    Node* left;
    Node* right;
}
```
This specific type of linked list is called a Doubly (or Circularly) Linked List as the links go both ways. Sometimes a Linked List might only store links in one direction; this is called a singly linked list.
