#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::exception;

template<typename TKey, typename TValue>
class Tree
{
public:

	void Add(TKey key, TValue value);
	void Remove(TKey key);

	void Print() const;

	TKey MinKey() const;

	TValue& operator[] (TKey key);
	const TValue& operator[] (TKey key) const;

private:

	struct Node //узел дерева
	{
		Node* parent = nullptr;
		Node* left   = nullptr;
		Node* right  = nullptr;

		TKey key;
		TValue value;

		bool IsLeaf()
		{
			return left == nullptr && right == nullptr;
		}

		bool HasOnlyOneChild()
		{
			return left != nullptr && right == nullptr ||
				left == nullptr && right != nullptr;
		}

		bool HasTwoChildren()
		{
			return left != nullptr && right != nullptr;
		}
	};

	//Корень дерева, указатель на вершину 
	Node*  _root = nullptr;
	size_t _size = 0;

	//внутренние методы
	void Print(Node* node) const;
	Node* MinNode(Node* node) const
	{
		if (node == nullptr)
			return nullptr;

		Node* minNode = node;

		while (minNode->left != nullptr)
		{
			minNode = minNode->left;
		}

		return minNode;
	}
	Node* SearchNode(TKey key) const
	{
		Node* cursor = _root;
		while (cursor != nullptr)
		{
			if (key == cursor->key)
				return cursor;
			else if (key < cursor->key)
				cursor = cursor->left;
			else
				cursor = cursor->right;
		}

		return nullptr;
	}

};

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Add(TKey key, TValue value)
{
	Node* newNode = new Node;
	newNode->key = key;
	newNode->value = value;

	if (_root == nullptr)
	{
		_root = newNode;
	}
	else
	{
		Node* cursor = _root;
		Node* current = _root;

		while (cursor != nullptr)
		{
			current = cursor;
			if (key < cursor->key)
				cursor = cursor->left;
			else
				cursor = cursor->right;
		}

		newNode->parent = current;
		if (key < current->key)
			current->left = newNode;
		else
			current->right = newNode;
	}

	_size++;
}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Remove(TKey key)
{
	Node* delNode = SearchNode(key);

	if (delNode == nullptr) return;

	if (delNode->HasTwoChildren())
	{
		Node* currentNode = delNode;
		delNode = MinNode(delNode->right);
		
		currentNode->key = delNode->key;
		currentNode->value = delNode->value;
	}

	if (delNode->IsLeaf())
	{
		Node* parent = delNode->parent;
		
		if (parent == nullptr)
			_root = nullptr;
		else
		{
			if (parent->left == delNode)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}

		delete delNode;
		_size--;
	}
	else if (delNode->HasOnlyOneChild())
	{
		Node* parent = delNode->parent;
		Node* child = delNode->left != nullptr ? delNode->left : delNode->right;

		if (parent == nullptr)
		{
			_root = child;
			child->parent == nullptr;
		}
		else
		{
			if (parent->left == delNode)
				parent->left = child;
			else
				parent->right = child;

			child->parent = parent;
		}

		delete delNode;
		_size--;
	}

}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Print() const 
{
	Print(_root);
}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Print(Node* node)const
{
	if (node == nullptr)
		return;
	
	if (node->left != nullptr)
		Print(node->left);	
	
	cout << node->key << " => " << node->value << endl;

	if (node->right != nullptr)
		Print(node->right);		
	
}

template<typename TKey, typename TValue>
inline TKey Tree<TKey, TValue>::MinKey() const
{
	return MinNode(_root)->key;
}

template<typename TKey, typename TValue>
inline TValue& Tree<TKey, TValue>::operator[](TKey key)
{
	Node* node = SearchNode(key);
	if (node == nullptr)
	{
		throw exception( "Error: key not found");		
	}

	return node->value;
}

template<typename TKey, typename TValue>
inline const TValue& Tree<TKey, TValue>::operator[](TKey key) const
{
	Node* node = SearchNode(key);
	if (node == nullptr)
	{
		cerr << "Error: key not found" << endl;
	}

	return node->value;
}
