#include<iostream>
using namespace std;
class BinSearchTree {
public:
	int value;
	BinSearchTree* leftTree;
	BinSearchTree* rightTree;
	BinSearchTree* parentTree;
	BinSearchTree() {
		this->value = 0;
		this->leftTree = NULL;
		this->rightTree = NULL;
		this->parentTree = NULL;
	}
	BinSearchTree(int val) : value(val) {
		this->leftTree = NULL;
		this->rightTree = NULL;
		this->parentTree = NULL;
	}
	void emptyTree(BinSearchTree* tree) {
		if(tree){
			emptyTree(tree->leftTree);
			emptyTree(tree->rightTree);
			delete tree;
		}
		tree = NULL;
	}
	void setLeftTree(BinSearchTree* bst) {
		this->leftTree = bst;
		bst->parentTree = this;
	}
	void setRightTree(BinSearchTree* bst) {
		this->rightTree = bst;
		bst->parentTree = this;
	}
	BinSearchTree* findTreeRecursion(int key,BinSearchTree* now,BinSearchTree* previous) {
		if (now == NULL) {
			return previous;
		}
		if (key < now->value) findTreeRecursion(key,now->leftTree,now);
		else if (key > now->value) findTreeRecursion(key,now->rightTree,now);
		else return now;
	}
	BinSearchTree* findTree(int key) {
		// have: key=value 
		//don't have: key=nearest value
		BinSearchTree* now = this  ,*lastTree = this;
		while (now!=NULL) {
			if (key == now->value) return now;
			else if (key < now->value) now = now->leftTree;
			else if (key > now->value) now = now->rightTree;
			if(now!= NULL) lastTree = now;
		}
		return lastTree;
	}
	BinSearchTree* insertTree(int key) {
		BinSearchTree* result = findTree(key);
		if (result->value == key) return NULL;
		BinSearchTree* item = new BinSearchTree(key);
		if (key < result->value) result->setLeftTree(item);
		else result->setRightTree(item);
		return item;
	}
	bool deleteTree(int Key) {
		BinSearchTree* tree = findTree(Key);
		if (tree->value != Key) return false;
		if (!tree->leftTree && !tree->rightTree) {
			if (tree->parentTree->leftTree == tree) tree->parentTree->setLeftTree(NULL);
			if (tree->parentTree->rightTree == tree) tree->parentTree->setRightTree(NULL);
			delete tree;
		}
		else if(tree->leftTree && !tree->rightTree) {
			if (tree->parentTree->leftTree == tree) tree->parentTree->setLeftTree(tree->leftTree);
			if (tree->parentTree->rightTree == tree) tree->parentTree->setRightTree(tree->leftTree);
			delete tree;
		}
		else if (!tree->leftTree && tree->rightTree) {
			if (tree->parentTree->leftTree == tree) tree->parentTree->setLeftTree(tree->rightTree);
			if (tree->parentTree->rightTree == tree) tree->parentTree->setRightTree(tree->rightTree);
			delete tree;
		}
		else {
			BinSearchTree* now = tree->rightTree;
			while (now->leftTree && now->value > Key) {
				now = now->leftTree;
			}
			int t = now->value;
			now->value = tree->value;
			tree->value = t;
			deleteTree(Key);
		}
		return true;
	}
};
int main() {
	BinSearchTree root(8);
	int Keys[] = {4,9,3,7,6,5};
	for (int _key : Keys) root.insertTree(_key);

	int findKey = 7;
	auto a = root.findTree(findKey);
	if (a->value == findKey) cout << "Found!" << endl;
	else cout << "Didn't Found!" << endl;

	auto b = root.insertTree(1);

	root.deleteTree(4);
	return 0;
}