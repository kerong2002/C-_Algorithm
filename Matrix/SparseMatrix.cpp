//2023/04/02 kerong
/*
    Algorithm : SparseMatrix
     Time complexity => O(k) or O(klogn)
    Space complexity => O(k)
*/
#include <iostream>
#include <fstream>
#define MAX_TERM 100
using namespace std;

struct term{
    int row;
    int col;
    int value;
};

void Print_Matrix(term m[]){
    for(int y=0;y<=m[0].value;y++){
        cout << m[y].row << "\t" << m[y].col << "\t" << m[y].value << endl;
    }
}

void Fast_Transpose(term A[], term A_trans[]){
    int RowSize[A[0].col]  = {0};
    int RowStart[A[0].col] = {0};
    A_trans[0].row   = A[0].col;
    A_trans[0].col   = A[0].row;
    A_trans[0].value = A[0].value;
    if(A[0].value>0){
        for(int y=1;y<=A[0].value;y++){
            RowSize[A[y].col] += 1;
        }
        RowStart[0] = 1;
        for(int y=1;y<A[0].col;y++){
            RowStart[y] = RowStart[y-1] + RowSize[y-1];
        }
        for(int x=1;x<=A[0].value;x++){
            int temp = RowStart[A[x].col]++;
            A_trans[temp].row = A[x].col;
            A_trans[temp].col = A[x].row;
            A_trans[temp].value = A[x].value;
        }
    }
}

int compare(int a, int b){
    if(a>b)  return -1;
    else if(a==b) return 0;
    else if(a<b)  return 1;
}

void storeSum(term ans[], int *totalID, int row, int col, int *sum){
    if(*sum){
        if(*totalID < MAX_TERM){
            (*totalID)++;
            ans[*totalID].row = row;
            ans[*totalID].col = col;
            ans[*totalID].value = *sum;
            *sum = 0;
        }
        else{
            cout << "Numbers of terms in product exceed " << MAX_TERM << endl;
            exit(1);
        }
    }
}

void mmult(term A[], term B[] , term ans[]){
    term Trans_B[MAX_TERM];
    int row = A[1].row;
    int rowBegin = 1;
    int totalID = 0;
    if(A[0].col != B[0].row){
        cerr << "Incompatible Matrix" << endl;
        exit(1);
    }
    Fast_Transpose(B, Trans_B);
    A[A[0].value+1].row = A[0].row;
    Trans_B[B[0].value+1].row = B[0].col;
    Trans_B[B[0].value+1].col = 0;
    int sum = 0;
    int column = 0;
    for(int i=1;i<=A[0].value;){
        sum = 0;
        column = Trans_B[1].row;
        for(int j=1;j<=B[0].value+1;){
            if(A[i].row!= row){
                storeSum(ans, &totalID, row, column, &sum);
                i = rowBegin;
                for(;Trans_B[j].row == column; j++);
                column = Trans_B[j].row;
            }
            else if(Trans_B[j].row != column){
                storeSum(ans, &totalID, row, column, &sum);
                i = rowBegin;
                column = Trans_B[j].row;
            }
            else{
                switch(compare(A[i].col, Trans_B[j].col)){
                    case 1:
                        i++;
                        break;
                    case -1:
                        j++;
                        break;
                    default:
                        sum += (A[i++].value * Trans_B[j++].value);
                        break;
                }
            }
        }
        for(;A[i].row == row ; i++);
        rowBegin = i;
        row = A[i].row;
    }
    ans[0].row = A[0].row;
    ans[0].col = B[0].col;
    ans[0].value = totalID;
}

int main(){
    term A[MAX_TERM], B[MAX_TERM], B_trans[MAX_TERM], ANS[MAX_TERM];
    ifstream AFile("SparseMatrix_inputA.txt");
    if(!AFile){
        cerr << "Unable to open A File";
        exit(1);
    }

    AFile >> A[0].row >> A[0].col >> A[0].value;
    for(int x=1;x<=A[0].value;x++){
        AFile >> A[x].row >> A[x].col >> A[x].value;
    }
    AFile.close();

//    Fast_Transpose(A, A_trans);
//    Print_Matrix(A);
//    cout << "Transpose matrix:" << endl;
//    Print_Matrix(A_trans);

    ifstream BFile("SparseMatrix_inputB.txt");
    if(!BFile){
        cerr << "Unable to open B File";
        exit(1);
    }

    BFile >> B[0].row >> B[0].col >> B[0].value;
    for(int x=1;x<=B[0].value;x++){
        BFile >> B[x].row >> B[x].col >> B[x].value;
    }
    BFile.close();
    cout << "=======<Matrix A>========" << endl;
    Print_Matrix(A);
    cout << "=======<Matrix B>========" << endl;
    Print_Matrix(B);
    cout << "======<Matrix AB>========" << endl;
    mmult(A, B, ANS);

    Print_Matrix(ANS);
    return 0;
}
