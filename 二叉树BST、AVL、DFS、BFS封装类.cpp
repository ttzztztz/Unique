#include<iostream>
#include<vector>
#include<queue>

// Author : Yang Ziyue
// Finished : 20181102
using namespace std;
class TreeNode {
public:
	TreeNode* leftTree;
	TreeNode* rightTree;
	int value;
	TreeNode() {
		leftTree = NULL;
		rightTree = NULL;
		value = 0;
	}
	TreeNode(int val) :value(val){
		leftTree = NULL;
		rightTree = NULL;
	}
};
class BinTree {
public:
	void preOutputRecursive(TreeNode* root) {
		cout << root->value << endl;
		if(root->leftTree!=NULL) preOutputRecursive(root->leftTree);
		if (root->rightTree != NULL)preOutputRecursive(root->rightTree);
	}
	void middleOutputRecursive(TreeNode* root) {
		if (root->leftTree != NULL)middleOutputRecursive(root->leftTree);
		cout << root->value << endl;
		if (root->rightTree != NULL)middleOutputRecursive(root->rightTree);
	}
	void afterOutputRecursive(TreeNode* root) {
		if (root->leftTree != NULL)afterOutputRecursive(root->leftTree);
		if (root->rightTree != NULL)afterOutputRecursive(root->rightTree);
		cout << root->value << endl;
	}
	void layerOutput(TreeNode* root) {
		cout << root->value << endl;
		queue<TreeNode*> que;
		if(root->leftTree!=NULL) que.push(root->leftTree);
		if (root->rightTree != NULL) que.push(root->rightTree);
		while (que.size() != 0) {
			TreeNode* now = que.front();
			cout << now->value << endl;
			que.pop();
			if (now->leftTree != NULL) que.push(now->leftTree);
			if (now->rightTree != NULL) que.push(now->rightTree);
		}
	}
	void preOutput(TreeNode* root) {
		TreeNode* now = root;
		vector<TreeNode*>stack;
		while (now != NULL || stack.size() != 0) {
			while (now != NULL) {
				cout << now->value;
				now = now->leftTree;
				stack.push_back(now);
			}
			if (stack.size() > 0) {
				now = stack[stack.size() - 1]->rightTree;
				stack.pop_back();
			}
			else now = now->rightTree;
		}
	}
	void middleOutput(TreeNode* root) {
		TreeNode* now = root;
		vector<TreeNode*>stack;
		while (now != NULL || stack.size() != 0 ) {
			while (now != NULL) {
				stack.push_back(now);
				now = now->leftTree;
			}
			if (stack.size() > 0) {
				TreeNode* last = stack[stack.size() - 1];
				cout << last->value << endl;
				stack.pop_back();
				now = last->rightTree;
			}
			else now = now->rightTree;
		}
	}
	void afterOutput(TreeNode* root) {
		TreeNode *now = root , *lastOutput = NULL;
		vector<TreeNode*>stack;
		while (now != NULL || stack.size() != 0) {
			while (now != NULL) {
				stack.push_back(now);
				now = now->leftTree;
			}
			now = stack[stack.size() - 1];
			if (now->rightTree == lastOutput || now->rightTree == NULL) {
				cout << now->value << endl;
				stack.pop_back();
				lastOutput = now;
				now = NULL;
			} 
			else now = now->rightTree;
		}
	}
};
class BinSearchTree :public BinTree {
public:
	TreeNode* findTree(TreeNode* root , int val) {
		TreeNode *now = root , *rtn = root;
		while (now != NULL) {
			if (val > now->value) now = now->rightTree;
			else if (val < now->value) now = now->leftTree;
			else return now;
			if (now != NULL) rtn = now;
		}
		return rtn;
	}
	virtual TreeNode* insertTree(TreeNode* root, int val) {
		if (root == NULL) {
			TreeNode* _new = new TreeNode(val);
			return _new;
		}
		if (val < root->value) {
			root->leftTree = insertTree(root->leftTree , val);
		}
		else if(val >= root->value) {
			root->rightTree = insertTree(root->rightTree , val);
		}
		return root;
	}
	virtual TreeNode* deleteTree(TreeNode* root, int val) {
		if (root == NULL) return NULL;
		if (val > root->value) {
			root->rightTree = deleteTree(root->rightTree, val);
		}
		else if (val < root->value) {
			root->leftTree = deleteTree(root->leftTree, val);
		}
		else if (val == root->value) {
			if (root->leftTree == NULL && root->rightTree == NULL) {
				root = NULL;
			}
			else if (root->leftTree && root->rightTree == NULL) {
				root = root->leftTree;
			}
			else if (root->leftTree == NULL && root->rightTree) {
				root = root->rightTree;
			}
			else {
				TreeNode* current = root->rightTree;
				while (current->leftTree != NULL) {
					current = current->leftTree;
				}
				root->value = current->value;
				root->rightTree = deleteTree(root->rightTree, current->value);
			}
		}
		return root;
	}
};
class AVLTree : public BinSearchTree {
private:
	int max(int a,int b) {
		return a > b ? a : b;
	}
public:
	virtual TreeNode* insertTree(TreeNode* root, int val) {
		if (root == NULL) {
			TreeNode* _new = new TreeNode(val);
			return _new;
		}
		if (val < root->value) {
			root->leftTree = insertTree(root->leftTree, val);
			root = balanceTree(root);
		}
		else if (val > root->value) {
			root->rightTree = insertTree(root->rightTree, val);
			root = balanceTree(root);
		}
		return root;
	}
	virtual TreeNode* deleteTree(TreeNode* root, int val) {
		if (root == NULL) return NULL;
		if (val < root->value) deleteTree(root->rightTree,val);
		else if (val > root->value) deleteTree(root->leftTree,val);
		else {
			if (root->leftTree == NULL && root->rightTree == NULL) {
				root = NULL;
				delete root;
			}
			else if (root->leftTree && root->rightTree == NULL) {
				root->value = root->leftTree->value;
				root->leftTree = NULL;
				delete root->leftTree;
			}
			else if (root->rightTree && root->leftTree == NULL) {
				root->value = root->rightTree->value;
				root->rightTree = NULL;
				delete root->rightTree;
			}
			else {
				TreeNode* currentNode = root->rightTree;
				while (currentNode->leftTree != NULL) {
					currentNode = currentNode->leftTree;
				}
				root->value = currentNode->value;
				root->rightTree = deleteTree(root->rightTree,currentNode->value);
			}
		}
		if (root == NULL) return root;
		root = balanceTree(root);
		return root;
	}
	int countHeight(TreeNode* root) {
		if (root == NULL) return 0;
		return max(countHeight(root->leftTree), countHeight(root->rightTree)) + 1;
	}
	int countBalance(TreeNode* root) {
		return countHeight(root->leftTree) - countHeight(root->rightTree);
	}
	TreeNode* leftRotate(TreeNode* root) {
		TreeNode* child = root->rightTree;
		root->rightTree = child->leftTree;
		child->leftTree = root;
		return child;
	}
	TreeNode* rightRotate(TreeNode* root) {
		TreeNode* child = root->leftTree;
		root->leftTree = child->rightTree;
		child->rightTree = root;
		return child;
	}
	TreeNode* balanceTree(TreeNode* root) {
		int balance = countBalance(root);
		if (balance >1) {
			if (countBalance(root->leftTree) > 0) {
				root = rightRotate(root);
			}
			else {
				root->leftTree = leftRotate(root->leftTree);
				root = rightRotate(root);
			}
		}
		else if (balance<-1) {
			if (countBalance(root->rightTree) <= 0) {
				root = leftRotate(root);
			}
			else {
				root->rightTree = rightRotate(root->rightTree);
				root = leftRotate(root);
			}
		}
		return root;
	}
};
int main() {
	//examples given to test features
	TreeNode* root = new TreeNode(8);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(9);
	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(7);
	TreeNode* node6 = new TreeNode(3);

	root->leftTree = node1;
	root->rightTree = node2;
	node1->leftTree = node3;
	node1->rightTree = node4;
	node2->leftTree = node5;
	node2->rightTree = node6;
	
	AVLTree* bst = new AVLTree;
	vector<TreeNode*> v;
	TreeNode* root2 = new TreeNode(8);
	int arr[] = {8,4,9,3,7,6,5};
	for (int _i : arr) 
		root2 = bst->insertTree(root2,_i);
	root2 = bst->deleteTree(root2,7);
	bst->layerOutput(root2);
	return 0;
}