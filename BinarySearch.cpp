//2023/04/01 kerong
/*
    Algorithm : BinarySearch
     Time complexity => O(log n)
    Space complexity => O(1)
*/
#include <iostream>
#define MAX_SIZE 5
using namespace std;

bool BinarySearch(int arr[], int L, int R, int key){
    int mid = 0;
    while(L<=R){
        mid = (L + R) / 2;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid] > key){
            R = mid-1;
        }
        else{
            L = mid + 1;
        }
    }
    return false;
}

int main(){
    int arr[MAX_SIZE] = {1, 5, 8, 10, 15};
    int key_1 = 1;
    int key_2 = 10;
    int key_3 = 12;
    cout << BinarySearch(arr, 0, MAX_SIZE-1, key_1) << endl;
    cout << BinarySearch(arr, 0, MAX_SIZE-1, key_2) << endl;
    cout << BinarySearch(arr, 0, MAX_SIZE-1, key_3) << endl;
    return 0;
}
