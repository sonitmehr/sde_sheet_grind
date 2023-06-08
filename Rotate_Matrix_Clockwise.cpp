#include <bits/stdc++.h>



void shift(int &prev,int &mat){
    int t = mat;
    mat = prev;
    prev = t;
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{

    // int n = mat.size(),m = mat[0].size();
    
    int topRow = 0,leftCol = 0,rightCol = m -1,botRow = n - 1;

    int i = 0,j = 0;
    if(n == 1 || m == 1)return;
    int prev = mat[1][0];

    while(topRow < botRow && leftCol < rightCol){

        // Set prev to the topleftmost element.
        prev = mat[topRow + 1][leftCol];
        
        // Going right
        for(int i = leftCol;i<=rightCol;i++){
            shift(prev,mat[topRow][i]);
        }
        topRow++;
        // Going down

        for(int i = topRow;i<= botRow;i++){
            shift(prev,mat[i][rightCol]);
        }
        rightCol--;
        // Going left

        for(int i = rightCol;i>=leftCol;i--){
            shift(prev,mat[botRow][i]);
        }
        botRow--;
        
        // Going up
        for(int i = botRow;i>=topRow;i--){
            shift(prev,mat[i][leftCol]);
        }
        leftCol++;

    }

}
