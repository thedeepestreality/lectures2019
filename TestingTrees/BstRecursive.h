#pragma once
#include <iostream>
#include <queue>
#include <deque>

template <typename Type>
class BstRecursive {
	struct Node {
		Type data;
		Node* left = nullptr, * right = nullptr;
		Node(const Type& _data) : data(_data) {}
		Node* minimum() { return this->left ? this->left->minimum() : this; }
	}*_root = nullptr;
	Node* insert(Node* sub_root, const Type& val) {
		if (!sub_root) return new Node(val);
		if (val == sub_root->data) throw "already exists";
		if (val < sub_root->data) sub_root->left = insert(sub_root->left, val);
		else sub_root->right = insert(sub_root->right, val);
		return sub_root;
	}
	Node* erase(Node* sub_root, const Type& key){
		if (!sub_root) return sub_root;
		if (key < sub_root->data) sub_root->left = erase(sub_root->left, key);
		else if (key > sub_root->data) sub_root->right = erase(sub_root->right, key);
		else{
			if (!sub_root->left || !sub_root->right){
				Node* successor = sub_root->left ? sub_root->left : sub_root->right;
				delete sub_root;
				return successor;
			}
			sub_root->data = sub_root->right->minimum()->data;
			sub_root->right = erase(sub_root->right, sub_root->data);
		}
		return sub_root;
	}
	void clear(Node* sub_root){
		if (!sub_root) return;
		clear(sub_root->left);
		clear(sub_root->right);
		delete sub_root;
	}
	void inorder(Node* sub_root) const{
		if (!sub_root) return;
		inorder(sub_root->left);
		std::cout << sub_root->data << std::endl;
		inorder(sub_root->right);
	}
	Type& find(Node* sub_root, const Type& key) const {
		if (!sub_root) throw "not found";
		if (key < sub_root->data) return find(sub_root->left, key);
		if (key > sub_root->data) return find(sub_root->right, key);
		return sub_root->data;
	}
	void print_bf(std::deque<Node*>&& q) const{
		if (q.empty()) return;
		Node* x = q.front(); q.pop_front();
		if (!x) return;
		std::cout << x->data << std::endl;
		q.push_back(x->left); q.push_back(x->right);
		print_bf(std::move(q));
	}
public:
	~BstRecursive() { clear(_root); }
	void push_back(const Type& val) { _root = insert(_root, val); }
	void erase(const Type& key) { _root = erase(_root, key); }
	void print() const { inorder(_root); }
	Type& find(const Type& key) const { return find(_root, key); }

	void print_bf() const {
		std::queue<Node*> q;
		q.push(_root);
		while (!q.empty()) {
			Node* x = q.front(); q.pop();
			if (!x) continue;
			std::cout << x->data << std::endl;
			q.push(x->left); q.push(x->right);
		}
	}
	void print_bf_rec() const { print_bf(std::deque<Node*>{_root});	}
};