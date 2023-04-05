//2022/04/05 kerong
/*
    Algorithm : Linear Search
     Time complexity => O(n)
    Space complexity => O(1)
*/
#include <iostream>
#define MAX_SIZE 5
using namespace std;

bool Linear_search(int arr[], int key){
    for(int x=0;x<MAX_SIZE;x++){
        if(arr[x] == key){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[MAX_SIZE] = {10, 4, 5, 8, 9};

    if(Linear_search(arr, 8)) {
        cout << 8 << " found in array" << endl;
    }
    else{
        cout << 8 << " not found in array" << endl;
    }

    if(Linear_search(arr, 2)) {
        cout << 2 << " found in array" << endl;
    }
    else{
        cout << 2 << " not found in array" << endl;
    }

    return 0;
}
