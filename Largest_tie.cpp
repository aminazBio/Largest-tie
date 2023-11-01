#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

struct Node 
{
	int leaf;
	Node* left;
	Node* right;
};

struct Node* newNode(int value)
{
	Node* x = new Node;
	x -> leaf = value;
	x -> left = NULL;
	x -> right = NULL;
	return x;
};

struct Node* Insert(struct Node* root, int value, queue < Node * > & q)
{
	Node* node = newNode(value);
	if (root == NULL)
		root = node;
	else if (q.front() -> left == NULL)
		q.front() -> left = node;
	else 
	{
		q.front() -> right = node;
		q.pop();
	}

	q.push(node);

	return root;
}

Node* CreateTree(int arr[], int n)
{
	Node* root = NULL;
	queue<Node*> q;
	for (int i = 0; i < round(pow(2,n))-1; i++)
		root = Insert(root, arr[i], q);
	return root;
}

void Find(vector<int> & res, Node* root, int d)
{
	if (!root)
		return;
	if (d == res.size())
		res.push_back(root -> leaf);
	else
		res[d] = max(res[d], root -> leaf);

	Find(res, root -> left, d + 1);
	Find(res, root -> right, d + 1);
}

vector<int> LargestValues(Node* root)
{
	vector<int> res;
	Find(res, root, 0);
	return res;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

	int a;
	a = round(pow(2,n))-1;
    int arr[a];

    for(int i = 0; i < a; i++)
    {	
		cin >> arr[i];
        cin.ignore();
    }

	Node* root = CreateTree(arr, n);
    
    vector<int> res = LargestValues(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
    return 0;
}    




