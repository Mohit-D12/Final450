// Rotate a matrix by 90 degree in clockwise direction without using any extra space
// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

#include<bits/stdc++.h>
using namespace std;

#define N 5

void rotateMatrix(int mat[][N])
{ 
    //REVERSE every row  
    for(int i = 0; i < N; i++)
        reverse(mat[i], mat[i] + N);
        
    // Performing Transpose
    for(int i = 0; i < N; i++)
        { 
            for(int j = i; j < N; j++)
                swap(mat[i][j], mat[j][i]);
        }
    
}