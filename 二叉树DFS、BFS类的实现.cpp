#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class T> class BinTree {
public:
	T value;
	BinTree* leftTree;
	BinTree* rightTree;
	BinTree() {
		leftTree = NULL;
		rightTree = NULL;
		value = 0;
	}
	BinTree(T val) :value(val){
		leftTree = NULL;
		rightTree = NULL;
	}
	void addLeftTree(BinTree* Tree){
		leftTree = Tree;
	}
	void addRightTree(BinTree* Tree){
		rightTree = Tree;
	}
	void preOrder() {
		vector<BinTree*> stack;
		BinTree* now = this;
		while (now != NULL || stack.size() != 0){
			while (now != NULL) {
				cout << now->value << endl;
				stack.push_back(now);
				now = now->leftTree;
			}
			if (stack.size() > 0) {
				BinTree* root = stack[stack.size() - 1];
				stack.pop_back();
				now = root->rightTree;
			}
			else {
				now = now->rightTree;
			}
		}
	}
	void middleOrder() {
		vector<BinTree*> stack;
		BinTree* now = this;
		while (now!=NULL || stack.size()!= 0 ) {
			while (now->leftTree != NULL) {
				stack.push_back(now);
				now = now->leftTree ;
			}
			cout << now->value << endl;
			if (stack.size() > 0) {
				BinTree* parent = stack[stack.size() - 1];
				stack.pop_back();
				cout << parent->value << endl;
				now = parent->rightTree;
			}
			else {
				now = now->rightTree;
			}
		}
	}
	void afterOrder() {
		vector<BinTree*> stack;
		BinTree *now = this , *lastOutput = this;
		while (now!=NULL || stack.size() >0) {
			while (now != NULL) {
				stack.push_back(now);
				now = now->leftTree;
			}
			now = stack[stack.size() - 1];
			if (now->rightTree == lastOutput || now->rightTree == NULL) {
				cout << now->value << endl;
				lastOutput = now;
				now = NULL;
				stack.pop_back();
			}
			else {
				now = now->rightTree;
			}
		}
	}
	void layerOrder() {
		queue<BinTree*> queue;
		cout << this->value << endl;
		if(this->leftTree != NULL)queue.push(this->leftTree);
		if (this->rightTree != NULL)queue.push(this->rightTree);
		while (queue.size() > 0) {
			BinTree* now = queue.front();
			cout << now ->value<< endl;
			queue.pop();
			if (now->leftTree != NULL)queue.push(now->leftTree);
			if (now->rightTree != NULL)queue.push(now->rightTree);
		}
	}
	void preOrderRecursion(BinTree* binTree) {
		if (binTree != NULL) {
			cout << binTree->value << endl;
			if (binTree->leftTree != NULL) 	preOrderRecursion(binTree->leftTree);
			if (binTree->rightTree != NULL) preOrderRecursion(binTree->rightTree);
		}
	}
	void middleOrderRecursion(BinTree* binTree) {
		if (binTree != NULL) {
			if (binTree->leftTree != NULL) middleOrderRecursion(binTree->leftTree);
			cout << binTree->value << endl;
			if (binTree->rightTree != NULL) middleOrderRecursion(binTree->rightTree);
		}
	}
	void afterOrderRecursion(BinTree* binTree) {
		if (binTree != NULL) {
			if (binTree->leftTree != NULL) afterOrderRecursion(binTree->leftTree);
			if (binTree->rightTree != NULL) afterOrderRecursion(binTree->rightTree);
			cout << binTree->value << endl;
		}
	}
};
int main() {
	BinTree<int>root(8);
	BinTree<int>node1(2);
	BinTree<int>node2(4);
	BinTree<int>node3(9);
	BinTree<int>node4(1);
	BinTree<int>node5(7);
	BinTree<int>node6(3);
	root.addLeftTree(&node1);
	root.addRightTree(&node2);
	node1.addLeftTree(&node3);
	node1.addRightTree(&node4);
	node2.addLeftTree(&node5);
	node2.addRightTree(&node6);
	/**
		  8
		2	4
	 9 1 7 3
	*/
	

	return 0;
}