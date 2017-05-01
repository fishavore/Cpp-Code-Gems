#pragma once

template<class T>
class RedBlackTree
{
private:
	typedef enum { RED, BLACK } COLOR;

	template<class T> class Node
	{
	public:
		int key;
		T value;
		Node* left;
		Node* right;
		Node* parent;
		COLOR color;

		Node(T item, int key)
		{
			this->key = key;
			this->value = item;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
			this->color = BLACK;
		};
		~Node() {};
	};

	Node<T>* mRoot;
	void Free(Node<T>* x);

public:
	RedBlackTree() { this->mRoot = nullptr; };
	~RedBlackTree() { Free(this->mRoot); };
public:
	void insert(T item, int key);
	void printInOrder();
	bool remove(int key);
	void deleteNodes();

private:
	void insertFixup(Node<T>* input);
	void leftRotate(Node<T>* x);
	void rightRotate(Node<T>* x);
	void transplant(Node<T>* left, Node<T>* right);
	void inOrderCout(Node<T>* x);
	//returns node ptr which match key.
	Node<T>* treeSearch(int key)
	{
		Node<T>* node = mRoot;
		while ((node != nullptr) && key != node->key)
		{
			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		return node;
	};
	Node<T>* treeMinimum(Node<T>* node)
	{
		while (node->left != nullptr)
			node = node->left;
		return node;
	};
	Node<T>* treeMaximum(Node<T>* node)
	{
		while (node->right != nullptr)
			node = node->right;
		return node;
	};
	void deleteFixup(Node<T>* input);
};


template <class T>
void RedBlackTree<T>::Free(Node<T>* x)
{
	if (x == nullptr)
	{
		return;
	}
	if (x->left != nullptr)
	{
		free(x->left);
	}
	if (x->right != nullptr)
	{
		free(x->right);
	}

	delete x;
}

template <class T>
void RedBlackTree<T>::insert(T item, int key)
{
	Node<T>* node_z = new Node<T>(item, key);
	Node<T>* node_y = nullptr;
	Node<T>* node_x = this->mRoot;

	if (!this->mRoot)
	{
		this->mRoot = node_z;
		return;
	}

	while (node_x) {
		node_y = node_x;
		if (node_z->key < node_x->key)
			node_x = node_x->left;
		else
			node_x = node_x->right;
	}
	node_z->parent = node_y;

	if (!node_y)
		this->mRoot = node_z;
	else if (node_z->key < node_y->key)
		node_y->left = node_z;
	else
		node_y->right = node_z;

	node_z->left = nullptr;
	node_z->right = nullptr;
	node_z->color = RED;

	insertFixup(node_z);
}

template <class T>
void RedBlackTree<T>::insertFixup(Node<T>* node_z)
{
	while ((node_z->parent) && (RED == node_z->parent->color)) {
		if (node_z->parent == node_z->parent->parent->left) {
			Node<T>* node_y = node_z->parent->parent->right;
			if (node_y && (RED == node_y->color)) {
				node_z->parent->color = BLACK;
				node_y->color = BLACK;
				node_z->parent->parent->color = RED;
				node_z = node_z->parent->parent;
			}
			else if (node_z == node_z->parent->right) {
				node_z = node_z->parent;
				leftRotate(node_z);
			}
			else {
				node_z->parent->color = BLACK;
				node_z->parent->parent->color = RED;
				rightRotate(node_z->parent->parent);
			}
		}
		else if (node_z->parent == node_z->parent->parent->right) {
			Node<T>* node_y = node_z->parent->parent->left;
			if (node_y && (RED == node_y->color)) {
				node_z->parent->color = BLACK;
				node_y->color = BLACK;
				node_z->parent->parent->color = RED;
				node_z = node_z->parent->parent;
			}
			else if (node_z == node_z->parent->right) {
				node_z = node_z->parent;
				leftRotate(node_z);
			}
			else {
				node_z->parent->color = BLACK;
				node_z->parent->parent->color = RED;
				rightRotate(node_z->parent->parent);
			}
		}
	}
	this->mRoot->color = BLACK;
}

template <class T>
void RedBlackTree<T>::leftRotate(Node<T>* node_x)
{
	Node<T>* node_y = node_x->right;

	if (node_y)
	{
		node_x->right = node_y->left;
		if (node_y->left != nullptr)
			node_y->left->parent = node_x;
		node_y->parent = node_x->parent;

		if (node_x->parent == nullptr)
			this->mRoot = node_y;
		else if (node_x == node_x->parent->left)
			node_x->parent->left = node_y;
		else
			node_x->parent->right = node_y;

		node_y->left = node_x;
		node_x->parent = node_y;
	}
}

template <class T>
void RedBlackTree<T>::rightRotate(Node<T>* node_y)
{
	Node<T>* node_x = node_y->left;

	if (node_x)
	{
		node_y->left = node_x->right;
		if (node_x->right != nullptr)
			node_x->right->parent = node_y;
		node_x->parent = node_y->parent;
		if (node_y->parent == nullptr)
			this->mRoot = node_x;
		else if (node_y == node_y->parent->right)
			node_y->parent->right = node_x;
		else
			node_y->parent->left = node_x;

		node_x->right = node_y;
		node_y->parent = node_x;
	}
}

template <class T>
void RedBlackTree<T>::transplant(Node<T>* node_u, Node<T>* node_v)
{
	if (!node_u->parent)
		this->mRoot = node_v;
	else if (node_u == node_u->parent->left)
		node_u->parent->left = node_v;
	else
		node_u->parent->right = node_v;

	if(node_v)
		node_v->parent = node_u->parent;
}

template <class T>
bool RedBlackTree<T>::remove(int key)
{
	//page: 324.
	Node<T>* node_z = treeSearch(key);
	if (!node_z)
	{
		return false; //failed to find key to remove.
	}

	// Delete operation
	Node<T>* node_y = node_z;
	COLOR y_original_color = node_y->color;

	Node<T>* node_x = nullptr;
	if (node_z->left == nullptr) {
		node_x = node_z->right;
		transplant(node_z, node_z->right);
	}
	else if (node_z->right == nullptr) {
		node_x = node_z->left;
		transplant(node_z, node_z->left);
	}
	else {
		node_y = treeMinimum(node_z->right);
		y_original_color = node_y->color;
		node_x = node_y->right;
		if ((node_x) && (node_x->parent) && (node_y->parent == node_z))
			node_x->parent = node_y;
		else {
			transplant(node_y, node_y->right);
			node_y->right = node_z->right;
			if(node_y->right)
				node_y->right->parent = node_y;
		}

		transplant(node_z, node_y);
		node_y->left = node_z->left;
		node_y->left->parent = node_y;
		node_y->color = node_z->color;
	}

	if (y_original_color == BLACK)
		deleteFixup(node_x);


	delete node_z;

	return true;
}

template<class T>
void RedBlackTree<T>::deleteFixup(Node<T>* node_x)
{
	while ((node_x) && (node_x != this->mRoot) && (BLACK == node_x->color)) {
		if (node_x == node_x->parent->left) {
			Node<T>* node_w = node_x->parent->right;
			if ((node_w) && (RED == node_w->color)) {
				node_w->color = BLACK;
				node_x->parent->color = RED;
				leftRotate(node_x->parent);
				node_w = node_x->parent->right;
			}
			else if ((node_w) && (node_w->right) && (node_w->left) && (BLACK == node_w->left->color) && (BLACK == node_w->right->color)) {
				node_w->color = RED;
				node_x = node_x->parent;
			}
			else if ((node_w) && (node_w->right) && (BLACK == node_w->right->color)) {
				if(node_w->left)
					node_w->left->color = BLACK;
				node_w->color = RED;
				rightRotate(node_w);
				node_w = node_x->parent->right;
			}
			else {
				if(node_w)
					node_w->color = node_x->parent->color;
				node_x->parent->color = BLACK;
				if((node_w) && node_w->right)
					node_w->right->color = BLACK;
				leftRotate(node_x->parent);
				node_x = this->mRoot;
			}
		}
		else if (node_x == node_x->parent->right) {
			Node<T>* node_w = node_x->parent->left;
			if ((node_w) && RED == node_w->color) {
				node_w->color = BLACK;
				node_x->parent->color = RED;
				leftRotate(node_x->parent);
				node_w = node_x->parent->right;
			}
			else if ((node_w) && (node_w->left) && (node_w->right) && (BLACK == node_w->left->color) && BLACK == node_w->right->color) {
				node_w->color = RED;
				node_x = node_x->parent;
			}
			else if ((node_w) &&  (node_w->right) && (BLACK == node_w->right->color)) {
				if(node_w->left)
					node_w->left->color = BLACK;
				node_w->color = RED;
				rightRotate(node_w);
				node_w = node_x->parent->right;
			}
			else {
				if(node_w)
					node_w->color = node_x->parent->color;
				node_x->parent->color = BLACK;
				if((node_w) && node_w->right)
					node_w->right->color = BLACK;
				leftRotate(node_x->parent);
				node_x = this->mRoot;
			}
		}
	}
	if(node_x)
		node_x->color = BLACK;
}

template <class T>
void RedBlackTree<T>::deleteNodes()
{
	free(this->mRoot);
}

template <class T>
void RedBlackTree<T>::inOrderCout(Node<T>* x)
{
	if (x != nullptr)
	{
		inOrderCout(x->left);
		std::cout << x->key << ", ";
		inOrderCout(x->right);
	}
}

template <class T>
void RedBlackTree<T>::printInOrder()
{
	std::cout << "Printing list in order:" << std::endl;
	inOrderCout(this->mRoot);
	std::cout << std::endl;
}