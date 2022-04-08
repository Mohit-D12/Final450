// Unique rows in boolean matrix
// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

#include <bits/stdc++.h>
using namespace std;
#define ROW 4 
#define COL 5 

// A Trie node 
class Node 
{ 
    public:
    bool isEndOfCol; 
    Node *child[2];
} ; 

Node* newNode() 
{ 
    Node* temp = new Node(); 
    temp->isEndOfCol = 0; 
    temp->child[0] = temp->child[1] = NULL; 
    return temp; 
} 

bool insert(Node** root, int (*M)[COL], 
                int row, int col ) 
{ 
    if (*root == NULL) 
        *root = newNode(); 

    if (col < COL) 
        return insert (&((*root)->child[M[row][col]]), 
                                        M, row, col + 1); 

    else
    { 
        
        if (!((*root)->isEndOfCol)) 
            return (*root)->isEndOfCol = 1; 

        return 0; 
    } 
} 

void printRow(int(*M)[COL], int row) 
{ 
    int i; 
    for(i = 0; i < COL; ++i) 
        cout << M[row][i] << " "; 
    cout << endl;
} 

void findUniqueRows(int (*M)[COL]) 
{ 
    Node* root = NULL;
    int i; 

    for (i = 0; i < ROW; ++i) 
    
        if (insert(&root, M, i, 0))
        
            printRow(M, i); 
} 