//2022/04/01 kerong
/*
    Algorithm : Bubble Sort
     Time complexity => O(n^2)
    Space complexity => O(1)
*/
#include <iostream>
#define MAX_SIZE 5
using namespace std;

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int arr[MAX_SIZE] = {5, 3, 8, 0, 4};
    for(int y=0;y<MAX_SIZE-1;y++){
        for(int x=y+1;x<MAX_SIZE;x++){
            if(arr[y]>arr[x]){
                swap(arr[y], arr[x]);
            }
        }
    }

    for(int x=0;x<MAX_SIZE;x++){
        cout << arr[x] << " ";
    }
    return 0;
}
