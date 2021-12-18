// https://www.geeksforgeeks.org/find-closest-element-binary-search-tree/

/*
	 Given a binary search tree and a target node K. The task is to find the node with minimum absolute difference with given target value K.
 */

// Recursive C++ program to find key closest to k
// in given Binary Search Tree.
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left child
	 and a pointer to right child */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* Utility that allocates a new node with the
	 given key and NULL left and right pointers. */
struct Node* newnode(int key)
{
	struct Node* node = new (struct Node);
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// Function to find node with minimum absolute
// difference with given K
// min_diff --> minimum difference till now
// min_diff_key --> node having minimum absolute
//				 difference with K
void maxDiffUtil(struct Node *ptr, int k, int &min_diff,
		int &min_diff_key)
{
	if (ptr == NULL)
		return ;

	// If k itself is present
	if (ptr->key == k)
	{
		min_diff_key = k;
		return;
	}

	// update min_diff and min_diff_key by checking
	// current node value
	if (min_diff > abs(ptr->key - k))
	{
		min_diff = abs(ptr->key - k);
		min_diff_key = ptr->key;
	}

	// if k is less than ptr->key then move in
	// left subtree else in right subtree
	if (k < ptr->key)
		maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
	else
		maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}

// Wrapper over maxDiffUtil()
int maxDiff(Node *root, int k)
{
	// Initialize minimum difference
	int min_diff = INT_MAX, min_diff_key = -1;

	// Find value of min_diff_key (Closest key
	// in tree with k)
	maxDiffUtil(root, k, min_diff, min_diff_key);

	return min_diff_key;
}

// Driver program to run the case
int main()
{
	struct Node *root = newnode(9);
	root->left = newnode(4);
	root->right = newnode(17);
	root->left->left = newnode(3);
	root->left->right = newnode(6);
	root->left->right->left = newnode(5);
	root->left->right->right = newnode(7);
	root->right->right = newnode(22);
	root->right->right->left = newnode(20);
	int k = 18;
	cout << maxDiff(root, k);
	return 0;
}


