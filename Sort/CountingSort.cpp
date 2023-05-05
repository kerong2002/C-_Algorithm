//2022/05/05 kerong
/*
    Algorithm : CountingSort
     Time complexity => O(n + k)
    Space complexity => O(n + k)
    n is number of elements
    k is range of the elements
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int max_n = *max_element(arr.begin(), arr.end());

    vector<int> count(max_n + 1, 0);

    for (int x = 0; x < arr.size(); x++) {
        ++count[arr[x]];
    }

    for (int x = max_n, y = arr.size() - 1; x>=0; x--){
        if(count[x]){
            arr[y] = x;
            --y;
            --count[x];
        }
    }
    return;
}

int main(){
    vector<int> arr = {5, 9, 2, 3, 1};
    countingSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
