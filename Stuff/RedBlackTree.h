#pragma once

#include<cstdlib>

//TODO:
//		Add delete.

template<class T>
class RedBlackTree
{
private:
	template<class T> class Node
	{
	public:
		int key;
		T value;
		Node* left;
		Node* right;
		Node* parent;
		bool isRed;

		Node(T item, int key)
		{
			this->key = key;
			this->value = item;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
			this->isRed = false;
		};
		~Node() {};
	};

	Node<T>* mRoot;
	void Free(Node<T>* x);

public:
	RedBlackTree() { this->mRoot = nullptr; };
	~RedBlackTree() { Free(this->mRoot); };
public:
	void Insert(T item, int key);
	void PrintInOrder();
	void Delete();
	void DeleteNodes();

private:
	void InsertFixup(Node<T>* input);
	void LeftRotate(Node<T>* x);
	void RightRotate(Node<T>* x);
	void Transplant(Node<T>* left, Node<T>* right);
	void InOrderCout(Node<T>* x);
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
void RedBlackTree<T>::Insert(T item, int key)
{
	Node<T>* input = new Node<T>(item, key);

	if (this->mRoot == nullptr)
	{
		this->mRoot = input;
		input->isRed = false; //root is black.
	}
	else
	{
		Node<T>* y = nullptr;
		Node<T>* x = this->mRoot;

		//Sätt in noden som ett vanligt BST.
		//Traversera
		while (x != nullptr)
		{
			y = x;
			if (input->key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		//Ställ in parent.
		input->parent = y;
		if (input->key > y->key)
			y->right = input;
		else
			y->left = input;
		input->isRed = true;

		//Fixa till den så noden hamnar rätt.
		InsertFixup(input);
	}
}

template <class T>
void RedBlackTree<T>::InsertFixup(Node<T>* _input)
{
	bool colorTemp;

	Node<T>* parentInput;
	Node<T>* grandParentInput;

	//Iterera tills att _input noden inte är root och vars förälder är röd.
	while (
		(_input != this->mRoot) &&
		(_input->isRed != false) &&
		(_input->parent->isRed == true))
	{

		parentInput = _input->parent;
		grandParentInput = _input->parent->parent;

		
		//Steg A.
		//Parent of input is left child of grandparent of input.
		
		if (_input->parent == grandParentInput->left)
		{
			Node<T>* uncleInput = grandParentInput->right;

			//Steg 1.
			//Uncle of Input is also red.
			//Recoloring:
			
			if (uncleInput != nullptr && uncleInput->isRed == true)
			{
				grandParentInput->isRed = true;
				parentInput->isRed = false;
				uncleInput->isRed = false;
				_input = grandParentInput;
			}
			else
			{
				
				//Steg 2.
				//input is right child of its parent
				//Left Rotation:
				
				if (_input == parentInput->right)
				{
					LeftRotate(parentInput);
					_input = parentInput;
					parentInput = _input->parent;
				}
				
				//Steg 3.
				//input is left child of parent
				//Right Rotation
				
				RightRotate(grandParentInput);
				colorTemp = parentInput->isRed;
				parentInput->isRed = grandParentInput->isRed;
				grandParentInput->isRed = colorTemp;
				_input = parentInput;
			}
		}
		
		//Steg B.
		//Parent of input is right child of grand parent of input
		else
		{
			//Steg 1.
			//Uncle of input is also red.
			//Recoloring:
			
			Node<T>* uncleInput = grandParentInput->left;
			if (uncleInput != nullptr && uncleInput->isRed == true)
			{
				grandParentInput->isRed = true;
				parentInput->isRed = false;
				uncleInput->isRed = false;
				_input = grandParentInput;
			}
			else
			{
				//Steg 2.
				//input is right child of its parent
				//Right Rotation:
				if (_input == parentInput->left)
				{
					RightRotate(parentInput);
					_input = parentInput;
					parentInput = _input->parent;
				}
				
				//Steg 3.
				//input is left child of parent
				//Left Rotation
				LeftRotate(grandParentInput);
				colorTemp = parentInput->isRed;
				parentInput->isRed = grandParentInput->isRed;
				grandParentInput->isRed = colorTemp;
				_input = parentInput;
			}
		}
	}
	this->mRoot->isRed = false;
}

template <class T>
void RedBlackTree<T>::LeftRotate(Node<T>* _input)
{
	Node<T>* inputRight = _input->right;
	_input->right = inputRight->left;

	if (_input->right != nullptr)
		_input->right->parent = _input;

	inputRight->parent = _input->parent;

	if (_input->parent == nullptr)
		this->mRoot = inputRight;
	else if (_input == _input->parent->left)
		_input->parent->left = inputRight;
	else
		_input->parent->right = inputRight;

	inputRight->left = _input;
	_input->parent = inputRight;
}

template <class T>
void RedBlackTree<T>::RightRotate(Node<T>* _input)
{
	Node<T>* leftInput = _input->left;
	_input->left = leftInput->right;

	if (_input->left != nullptr)
		_input->left->parent = _input;

	leftInput->parent = _input->parent;

	if (_input->parent == nullptr)
		this->mRoot = leftInput;
	else if (_input == _input->parent->left)
		_input->parent->left = leftInput;
	else
		_input->parent->right = leftInput;
	leftInput->right = _input;
	_input->parent = leftInput;
}

template <class T>
void RedBlackTree<T>::Transplant(Node<T>* _left, Node<T>* _right)
{
	if (_left->parent == nullptr)
	{
		this->mRoot = _right;
	}
	else if (_left == _left->parent->left)
	{
		_left->parent->left = _right;
	}
	else
	{
		_left->parent->right = _right;
	}
	_right->parent = _left->parent;
}

template <class T>
void RedBlackTree<T>::Delete()
{


}


template <class T>
void RedBlackTree<T>::DeleteNodes()
{
	free(this->mRoot);
}

template <class T>
void RedBlackTree<T>::InOrderCout(Node<T>* x)
{
	if (x != nullptr)
	{
		InOrderCout(x->left);
		std::cout << x->key << ", ";
		InOrderCout(x->right);
	}
}

template <class T>
void RedBlackTree<T>::PrintInOrder()
{
	std::cout << "Printing list in order:" << std::endl;
	InOrderCout(this->mRoot);
	std::cout << std::endl;
}