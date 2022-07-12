#include <iostream>
#include <fstream>

std::ofstream output_file("output.txt");

struct Node {
	int key_;
	Node* left_ = nullptr;
	Node* right_ = nullptr;

	Node() {}
	Node(int key) : key_(key) {}	
};

class BinarySearchTree
{
private:
	Node* root_;
	
	static void Clear(Node* node);
	void insert(int x, Node*& node);
	void preOrderTravers(Node* node);
	Node* RecursivelyDeleteNode(Node* node, int x);
	Node* FindMin(Node* node);

public:
	void Insert(int x);
	void PreOrderTravers();
	void DeleteNode(int x);
	BinarySearchTree();
	~BinarySearchTree();
};

void BinarySearchTree::Clear(Node* node)
{
	if (node != nullptr) {
		Clear(node->left_);
		Clear(node->right_);
		delete node;
	}
}

void BinarySearchTree::insert(int x, Node*& node)
{
	if (node == nullptr) {
		node = new Node(x);
	}
	else if(x > node->key_){
		insert(x, node->right_);
	}
	else if(x < node->key_) {
		insert(x, node->left_);
	}
}

void BinarySearchTree::preOrderTravers(Node* node) {
	if (node != nullptr) {
		output_file << node->key_ << "\n";
		preOrderTravers(node->left_);
		preOrderTravers(node->right_);
	}
}

void BinarySearchTree::Insert(int x) {
	insert(x, root_);
}

void BinarySearchTree::PreOrderTravers() {
	preOrderTravers(root_);
}

Node* BinarySearchTree::FindMin(Node* node)
{
	while (node->left_)
		node = node->left_;
	return node;
}

Node* BinarySearchTree::RecursivelyDeleteNode(Node* node, int x)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (x < node->key_) {
		node->left_ = RecursivelyDeleteNode(node->left_, x);
		return node;
	}
	else if(x > node->key_) 
	{
		node->right_ = RecursivelyDeleteNode(node->right_, x);
		return node;
	}
	if (node->right_ == nullptr)
	{
		return node->left_;
	}
	else if (node->left_ == nullptr)
	{
		return node->right_;
	}else
	{
		int min = FindMin(node->right_)->key_;
		node->key_ = min;
		node->right_ = RecursivelyDeleteNode(node->right_, min);
		return node;
	}
}

void BinarySearchTree::DeleteNode(int x)
{
	root_ = RecursivelyDeleteNode(root_, x);
}

BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	Clear(root_);
}


int main()
{
	BinarySearchTree tree;
	std::ifstream input_file("input.txt");

	int del_key;
	input_file >> del_key;
	while (!input_file.eof())
	{
		int key;
		input_file >> key;
		tree.Insert(key);
	}
	input_file.close();
	
	tree.DeleteNode(del_key);
	tree.PreOrderTravers();
	output_file.close();
}