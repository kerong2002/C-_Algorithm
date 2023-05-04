//2022/05/04 kerong
/*
    Algorithm : QuickSort
     Time complexity => O(nlogn)
    Space complexity => O(n^2)
*/
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int pIndex = start;
    for(int x=start;x<end;x++){
        if(arr[x] <= pivot){
            swap(arr[x], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex] , arr[end]);
    return pIndex;
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int parpartitionIndex = partition(arr, start , end);
        quickSort(arr, start, parpartitionIndex - 1);
        quickSort(arr, parpartitionIndex + 1 , end);
        return;
    }
    return;
}

int main(){
    vector<int> arr = {5, 9, 2, 3, 1};
    quickSort(arr, 0, arr.size()-1);
    for(int x:arr){
        cout << x << " ";
    }
    return 0;
}
