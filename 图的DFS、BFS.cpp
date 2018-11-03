#include<iostream>
#include<vector>
#include<queue>
#define MAX_GRAPH 100
using namespace std;
class Edge {
public:
	int edgeX;
	int edgeY;
	Edge() {
		edgeX = 0;
		edgeY = 0;
	}
	Edge(int X, int Y) {
		edgeX = X;
		edgeY = Y;
	}
	void reverse() {
		int edgeT = this->edgeX;
		this->edgeY = this->edgeX;
		this->edgeX = edgeT;
	}
};
class Graph {
public:
	int edge[MAX_GRAPH][MAX_GRAPH];
	int vertex[MAX_GRAPH];
	int len;
	Graph() {	
		len = 0;
		for (int i = 0; i < MAX_GRAPH; i++) {
			vertex[i] = 0;
			for (int m = 0; m < MAX_GRAPH; m++)
				edge[i][m] = 0;
		}
	}
	void outputGraph() {
		for (int i = 0; i < len; i++) {
			cout << vertex[i] << '\t';
		}
		cout << endl<<endl;
		for (int i = 0; i < len; i++) {
			for (int m = 0; m < len; m++) {
				cout << edge[i][m] << '\t';
			}
			cout << endl;
		}
	}
	int createVertex(int val) {
		vertex[len] = val;
		len++;
		return len - 1;
	}
	Edge createEdge(Edge in) {
		int a = in.edgeX, b = in.edgeY;
		edge[a][b] = 1;
		return Edge(a,b);
	}
	Edge createEdge(int a,int b) {
		edge[a][b] = 1;
		return Edge(a, b);
	}
	void deleteEdge(Edge in) {
		int a = in.edgeX, b = in.edgeY;
		edge[a][b] = 0;
	}
	void deleteEdge(int a,int b) {
		edge[a][b] = 0;
	}
	Edge createEdgeDouble(Edge in) {
		int a = in.edgeX, b = in.edgeY;
		edge[a][b] = 1;
		edge[b][a] = 1;
		return Edge(a,b);
	}
	Edge createEdgeDouble(int a , int b) {
		edge[a][b] = 1;
		edge[b][a] = 1;
		return Edge(a, b);
	}
	void deleteEdgeDouble(Edge in) {
		int a = in.edgeX, b = in.edgeY;
		edge[a][b] = 0;
		edge[b][a] = 0;
	}
	void deleteEdgeDouble(int a,int b) {
		edge[a][b] = 0;
		edge[b][a] = 0;
	}
	Edge findFirstEdge(int edgeX) {
		int rtn = -1;
		for (int i = 0; i < len; i++) {
			if (edge[edgeX][i] == 1) {
				rtn = i; break;
			}
		}
		return Edge(edgeX,rtn);
	}
	Edge findNextEdge(int edgeX,int edgeY) {
		int rtn = -1;
		for (int i = edgeY; i < len; i++) {
			if (edge[edgeX][i] == 1) {
				rtn = i; break;
			}
		}
		return Edge(edgeX,rtn);
	}
	void BFS(int begin) {
		int* visited = new int[len + 1];
		for (int i = 0; i < len + 1; i++) visited[i] = 0; // init
		queue<int> que;
		que.push(begin);
		while (que.size() != 0) {
			int index = que.front();
			cout << vertex[index] << endl;
			visited[index] = 1;
			que.pop();
			for (int i = 0; i < len; i++) {
				if (edge[index][i] == 1 && visited[i]!=1) {
					visited[i] = 1;
					que.push(i);
				}
			}
		}
		delete[] visited;
	}
	void DFS(int begin) {
		int* visited = new int[len + 1];
		for (int i = 0; i < len + 1; i++) visited[i] = 0; // init
		vector<int> stack;
		stack.push_back(begin);
		visited[begin] = 1;
		while (stack.size() != 0) {
			int now = stack[stack.size() - 1];
			int flag = 0;
			for (int i = 0; i < len; i++) {
				if (visited[i] != 1 && edge[now][i] == 1) {
					stack.push_back(i);
					visited[i] = 1;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << vertex[now] << endl;
				stack.pop_back();
			}
		}
		delete[] visited;
	}
};
int main() {
	Graph* gp = new Graph;
	int index1 = gp->createVertex(1);
	int index2 = gp->createVertex(2);
	int index3 = gp->createVertex(3);
	int index4 = gp->createVertex(4);
	int index5 = gp->createVertex(5);
	/** Edge e1(index1,index3);
	gp->createEdge(e1);  */
	
	gp->createEdge(index1, index2);
	gp->createEdge(index2, index3);
	gp->createEdge(index2, index5);
	gp->createEdge(index4, index2);
	gp->createEdge(index4, index1);
	gp->createEdge(index4, index5);
	gp->createEdge(index5, index3);
	gp->createEdge(index3, index3);
	gp->DFS(index1);
	return 0;
}