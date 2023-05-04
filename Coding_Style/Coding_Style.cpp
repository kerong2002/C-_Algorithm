#include <iostream>
#include <memory>
#include <vector>

#include "a.h"

#define SIZE 10
#define ROW_SIZE 2
#define COL_SIZE 3

using std::vector;
using std::unique_ptr;
using std::cout;

void myFunction(int myInt, float myFloat);
void myFunction(MyClass& myObject);
void myFunction(int* myIntPtr);
void myFunction(int** myIntPtrPtr);

int main(int argc, char **argv) {

    unique_ptr<bool[]> arr(new bool[SIZE]);

    for (int x = 0; x < SIZE; ++x) {
        if (x & 1) {
            arr[x] = true;
        }
        else {
            arr[x] = false;
        }
    }

    for (int x = 0; x < SIZE; x++) {
        cout <<  arr[x] << " ";
    }
    cout << '\n';

    vector<vector<int>> v1(ROW_SIZE, vector<int>(COL_SIZE, 0));

    for (int y = 0; y < ROW_SIZE; ++y) {
        for (int x = 0; x < COL_SIZE; ++x) {
            v1[y][x] = y * COL_SIZE + x;
        }
    }

    for (size_t i = 0; i < v1.size(); ++i){
        for (size_t j = 0; j < v1[0].size(); ++j) {
            cout << v1[i][j] << " ";
        }
        cout << '\n';
    }

    int* ptr = nullptr;
    int value = NULL;
    int& ref = value;

    for (int x = 0; x < n; ++x) {
        . . .
    }

    if (condition) {
        . . .
    }
    else if (condition) {
        . . .
    }
    else {
        . . .
    }

    while (condition) {
        . . .
    }

    do {
        . . .
    } while (condition);


    switch (val) {
        case 0:
            . . .
            break;
        case 1:
            . . .
            break;
        default:
            . . .
            break;
    }


    return 0;
}
