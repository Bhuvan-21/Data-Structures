#include <bits/stdc++.h>

#define ll long long

using namespace std;

class SegTree {
public:
	int size;
	vector<ll> sums;
	
	SegTree(int n) {
		size = 1;
		while(size < n) size *= 2;
		sums.assign(2*size, 0LL);
	}
	
	void build(vector<ll> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}
	
	void build(vector<ll> &a) {
		build(a, 0, 0, size);
	}
	
	void set(int i, ll v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i < m) {
			set(i, v, 2*x+1, lx, m);
		}
		else {
			set(i, v, 2*x+2, m, rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}
 	
	void set(int i, ll v) {
		set(i, v, 0, 0, size);
	}
	
	ll sum(int l, int r, int x, int lx, int rx) {
		if(lx >= l && rx <= r) return sums[x];
		if(rx <= l || lx >= r) return 0;
		int m = (lx+rx)/2;
		return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
	}
	
	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};


int main() {
	ll n, m;
	cin >> n >> m;
	
	SegTree sg(n);
	vector<ll> a(n);
	for(ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sg.build(a);
	for(ll i = 0; i < m; i++) {
		int a;
		cin >> a;
		if(a == 1) {
			int i, v;
			cin >> i >> v;
			sg.set(i, v);
		}
		else if(a == 2) {
			int l, r;
			cin >> l >> r;
			cout << sg.sum(l, r) << "\n";
		}
	}
}
