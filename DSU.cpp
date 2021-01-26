#include <iostream>

#define MAX_SIZE 10000
using namespace std;

class DSU {
private: 
	int *parent;
	int *size;
public:
	int count;
	DSU() {
		count = 0;
		parent = new int[MAX_SIZE];
		size = new int[MAX_SIZE];
	}
	
	void makeSet(int v) {
		count++;
		parent[v] = v;
		size[v] = 1;
	}
	
	int findSet(int v) {
		
		if(v != parent[v])
			return parent[v] = findSet(parent[v]);
		return v;
	}
	
	void addToSet(int s, int v) {
		parent[v] = s;
		size[v] = 1;
		size[s]++;
	}
	
	void unionSets(int a, int b) {
		
		a = findSet(a);
		b = findSet(b);
		if(size[a] >= size[b]) {
			parent[b] = a;
			size[a] += size[b];
		}
		else {
			parent[a] = b;
			size[b] += size[a];
		}
		count--;
		return;
	}
	
	~DSU() {
		delete(parent);
		delete(size);
	}
	

};

int main() {
	DSU hehe;
	hehe.makeSet(1);
	cout<<hehe.findSet(1)<<endl;
	hehe.makeSet(2);
	hehe.addToSet(2, 3);
	hehe.unionSets(1, 2);
	cout<<hehe.findSet(1)<<endl;
	return 0;
}
