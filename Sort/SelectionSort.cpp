//2022/04/01 kerong
/*
    Algorithm : SelectionSort
     Time complexity => O(n^2)
    Space complexity => O(1)
*/
#include <iostream>
#define MAX_SIZE 5
using namespace std;

void SelectionSort(int arr[], int arr_size){
    int min_index = 0;
    for(int y=0;y<arr_size-1;y++){
        min_index = y;
        for(int x=y+1;x<arr_size;x++){
            if(arr[x] < arr[min_index]){
                min_index = x;
            }
        }
        swap(arr[y], arr[min_index]);
    }
}

int main(){
    int arr[MAX_SIZE] = {5, 9, 2, 3, 1};
    SelectionSort(arr, MAX_SIZE);
    for(int x:arr){
        cout << x << ",";
    }
    return 0;
}
