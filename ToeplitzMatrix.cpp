//2023/04/02 kerong
/*
    Algorithm : Checking if a matrix is Toeplitz
     Time complexity => O(mn)
    Space complexity => O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> check(row+col, -1);
    for(int y=0;y<row;y++){
        for(int x=0;x<col;x++){
            if(check[x-y+row-1]==-1){
                check[x-y+row-1] = matrix[y][x];
            }
            else{
                if(check[x-y+row-1]!=matrix[y][x]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,1,2,3},
        {9,5,1,2}
    };
    bool is_toeplitz = isToeplitzMatrix(matrix);
    if (is_toeplitz) {
        cout << "The matrix is a Toeplitz matrix." << endl;
    } else {
        cout << "The matrix is not a Toeplitz matrix." << endl;
    }
    return 0;
}
