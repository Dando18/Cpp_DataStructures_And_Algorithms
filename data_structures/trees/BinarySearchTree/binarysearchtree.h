#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

namespace dat {

// declaration
template <typename T>
class BinarySearchTree {
	public:
		BinarySearchTree();
		~BinarySearchTree();

	private:
		class Node {
			private:
				Node* parent;
				Node* left;
				Node* right;
				T val;
		};
		Node* sentinel;
		void delete_node(Node*);
};


// implementation
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	sentinel = new Node;
	sentinel->right = sentinel;
	sentinel->left = sentinel;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	delete_node(sentinel);
}

template <typename T>
void BinarySearchTree<T>::delete_node(Node* n) {
	if (n->right != sentinel)
		delete_node(n->right);
	if (n->left != sentinel)
		delete_node(n->left);
	delete n;
}


}

#endif
