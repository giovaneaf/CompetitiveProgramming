#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef struct node node;

struct node
{
	int data;
	node* right;
	node* left;
};

void insert(node** root, int num)
{
	node* newe = (node*) malloc (sizeof(node));
	newe->data = num;
	newe->left = newe->right = NULL;
	if((*root) == NULL)
		(*root) = newe;
	else
	{
		node* ant = NULL;
		node* aux = (*root);
		while(aux != NULL)
		{
			ant = aux;
			if(num < aux->data)
				aux = aux->left;
			else
				aux = aux->right;
		}
		if(num < ant->data)
			ant->left = newe;
		else
			ant->right = newe;
	}
}

void preorder(node* root)
{
	if(root != NULL)
	{
		printf(" %d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf(" %d", root->data);
		inorder(root->right);
	}
}

void postorder(node* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %d", root->data);
	}
}

void del(node* root)
{
	if(root != NULL)
	{
		del(root->left);
		del(root->right);
		free(root);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		node* root = NULL;
		int N;
		scanf("%d\n", &N);
		for(int i = 0; i < N; i++)
		{
			int a;
			scanf("%d", &a);
			insert(&root, a);
		}
		printf("Case %d:\n", t+1);
		printf("Pre.:");
		preorder(root);
		putchar('\n');
		printf("In..:");
		inorder(root);
		putchar('\n');
		printf("Post:");
		postorder(root);
		putchar('\n');
		putchar('\n');
		del(root);
	}
	return 0;
}