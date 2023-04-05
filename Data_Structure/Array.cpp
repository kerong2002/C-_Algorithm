//2023/04/05 kerong
/*
   Data_Structure : Array
    Time complexity => O(n)
   Space complexity => O(n)
*/
#include <iostream>
#include <array>
#define MAX_SIZE 5
using namespace std;

int main(){
    int arr_1[MAX_SIZE] = {1, 3, 5, 7, 9};
    for(int x=0;x<MAX_SIZE;x++){
        cout << arr_1[x] << " ";
    }
    cout << endl;

    array<int, MAX_SIZE> arr_2 = {2, 4, 6, 8, 10};
    for(int x=0;x<arr_2.size();x++){
        cout << arr_2[x] << " ";
    }
    return 0;
}
