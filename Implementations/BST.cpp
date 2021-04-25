/*
	Unbalanced Binary search Tree(BST) implementation with the following operations:
	insert() 	- Insert element in the BST
	has()		- Check if element exists in the current BST
	erase()		- Remove element inside BST
	preOrder, inOrder and postOrder traversals
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

template <typename T>
struct BST
{
	struct node
	{
		T data;
		node* lc,* rc;	
	};
	node* root;
	BST()
	{
		root = nullptr;
	}
	~BST()
	{
		clear();
	}
	void insert(T data)
	{
		if(root == nullptr)
		{
			root = new node;
			root->data = data;
			root->lc = root->rc = nullptr;
			return ;
		}
		node* cur = root;
		node* prev;
		while(cur != nullptr)
		{
			prev = cur;
			cur = (data < cur->data ? cur->lc : cur->rc);
		}
		cur = new node;
		cur->data = data;
		cur->lc = cur->rc = nullptr;
		if(data < prev->data)
			prev->lc = cur;
		else
			prev->rc = cur;
	}
	bool has(T data)
	{
		node* cur = root;
		while(cur != nullptr && cur->data != data)
		{
			cur = (data < cur->data ? cur->lc : cur->rc);
		}
		return cur != nullptr;
	}
	void erase(T data)
	{
		node* cur = root;
		node* prev = nullptr;
		while(cur != nullptr && cur->data != data)
		{
			prev = cur;
			cur = (data < cur->data ? cur->lc : cur->rc);
		}
		if(cur == nullptr)
			return;
		if(cur->lc == nullptr && cur->rc == nullptr)
		{
			if(prev != nullptr)
			{
				if(cur->data < prev->data)
					prev->lc = nullptr;
				else
					prev->rc = nullptr;
			}
			else
			{
				root = nullptr;
			}
		}
		else if(cur->lc != nullptr && cur->rc != nullptr)
		{
			node* nc,* np;
			nc = cur->rc;
			np = cur;
			while(nc->lc != nullptr)
			{
				np = nc;
				nc = nc->lc;
			}
			if(np != cur)
				np->lc = nc->rc;
			else
				cur->rc = nc->rc;
			nc->lc = cur->lc;
			nc->rc = cur->rc;
			if(prev != nullptr)
			{
				if(cur->data < prev->data)
					prev->lc = nc;
				else
					prev->rc = nc;
			}
			else
			{
				root = nc;
			}
		}
		else
		{
			if(prev != nullptr)
			{
				if(cur->data < prev->data)
					prev->lc = (cur->lc != nullptr ? cur->lc : cur->rc);
				else
					prev->rc = (cur->lc != nullptr ? cur->lc : cur->rc);
			}
			else
			{
				root = (cur->lc != nullptr ? cur->lc : cur->rc);
			}
		}
		cur->lc = cur->rc = nullptr;
		delete cur;
		cur = nullptr;
	}
	void preOrderRec(node* cur)
	{
		if(cur == nullptr)
			return ;
		cout << ' ' << cur->data;
		preOrderRec(cur->lc);
		preOrderRec(cur->rc);
	}
	void preOrder()
	{
		printf("-----Pre Order-----\nNodes:");
		preOrderRec(root);
		cout << '\n';
	}
	void inOrderRec(node* cur)
	{
		if(cur == nullptr)
			return ;
		inOrderRec(cur->lc);
		cout << ' ' << cur->data;
		inOrderRec(cur->rc);
	}
	void inOrder()
	{
		cout << "-----In Order-----\nNodes:";
		inOrderRec(root);
		cout << '\n';
	}
	void postOrderRec(node* cur)
	{
		if(cur == nullptr)
			return ;
		postOrderRec(cur->lc);
		postOrderRec(cur->rc);
		cout << ' ' << cur->data;
	}
	void postOrder()
	{
		cout << "-----Post Order-----\nNodes:";
		postOrderRec(root);
		cout << '\n';
	}
	void clearRec(node* cur)
	{
		if(cur == nullptr)
			return;
		clearRec(cur->rc);
		clearRec(cur->lc);
		delete cur;
	}
	void clear()
	{
		clearRec(root);
		root = nullptr;
	}
};

int main() 
{
	BST<int> bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(15);
	bst.insert(20);
	bst.insert(17);
	bst.insert(18);
	bst.preOrder();
	bst.inOrder();
	bst.postOrder();
	printf("BST %s contain %d\n", bst.has(10) ? "\b" : "do not", 10);
	printf("BST %s contain %d\n", bst.has(5) ? "\b" : "do not", 5);
	printf("BST %s contain %d\n", bst.has(21) ? "\b" : "do not", 21);
	printf("BST %s contain %d\n", bst.has(1) ? "\b" : "do not", 1);
	bst.erase(10);
	bst.erase(20);
	bst.erase(3);
	bst.insert(1);
	bst.erase(15);
	bst.erase(17);
	bst.erase(5);
	bst.preOrder();
	bst.inOrder();
	bst.postOrder();
	printf("BST %s contain %d\n", bst.has(10) ? "\b" : "do not", 10);
	printf("BST %s contain %d\n", bst.has(5) ? "\b" : "do not", 5);
	printf("BST %s contain %d\n", bst.has(21) ? "\b" : "do not", 21);
	printf("BST %s contain %d\n", bst.has(1) ? "\b" : "do not", 1);
	bst.clear();
}