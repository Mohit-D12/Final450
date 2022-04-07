#include <bits/stdc++.h>
using namespace std;

struct Node {

	int data;
	struct Node* left;
	struct Node* right;
	Node(int val) {

		data = val;
		left = right = NULL;
	}
};

Node* constructtree(string s, int& start, int& n) {
    
    // sets the start to an integer value in the string
    // returns the current root

    if(start >= n || s[start] == ')') {

        start++;
        return NULL;
    }

    int num = 0;
    while (start < s.size() && s[start] != '(' && s[start] != ')') {
        
        int num_here = s[start] - '0';
        num = num * 10 + num_here;
        start++;
    }
    
    Node* root = new Node(num);
    
    if(start >= n || s[start] == ')') {

        start++;
        return root;
    }
        
    if(s[start] == '(') {

        start++;
        root->left = constructtree(s, start, n);
    }
    if(start >= n || s[start] == ')') {

        start++;
        return root;
    }
    if(s[start] == '(') {

        start++;
        root->right = constructtree(s, start, n);
    }
    if(start >= n || s[start] == ')') {

        start++;
        return root;
    }

    return root;
}

void preorder(Node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	string s = "4(2(3)(1))(6(5))";
	int start = 0;
    int len = s.length();
	Node* root = constructtree(s, start, len);
	preorder(root);
	return 0;
}
