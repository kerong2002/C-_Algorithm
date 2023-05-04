//2022/05/04 kerong
/*
    Algorithm : MergeSort
     Time complexity => O(nlogn)
    Space complexity => O(n)
*/
#include <iostream>
#include <vector>


using namespace std;

void merge(vector<int> &arr, int front, int mid, int end) {
    int L = front;
    int R = mid + 1;
    vector<int> temp;
    while (L <= mid && R <= end) {
        if (arr[L] <= arr[R]) {
            temp.push_back(arr[L++]);
        }
        else {
            temp.push_back(arr[R++]);
        }
    }

    while (L <= mid) {
        temp.push_back(arr[L++]);
    }

    while (R <= end) {
        temp.push_back(arr[R++]);
    }

    for (int t = front; t <= end; ++t) {
        arr[t] = temp[t - front];
    }

}

void mergeSort(vector<int> &arr, int front, int end) {
    if (front < end) {
        int mid = (front + end ) / 2;
        mergeSort(arr, front, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, front, mid, end);
    }

}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
