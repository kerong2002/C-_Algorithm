//2023/05/14 kerong
/*
    Data_Structure : Array(STL)
     Time complexity => O(n)
    Space complexity => O(n)

    Capacity:
        size(): Returns the number of elements in the array.
        max_size(): Returns the maximum number of elements that the array can hold.
        empty(): Checks whether the array is empty, i.e., whether its size is 0.

    Element access:
        operator[]: Accesses the element at the specified position.
        at(): Accesses the element at the specified position and checks if it is valid.
        front(): Returns a reference to the first element in the array.
        back(): Returns a reference to the last element in the array.
        data(): Returns a pointer to the first element of the array.

    Modifiers:
        fill(): Assigns the given value to all the elements in the array.
        swap(): Swaps the contents of two arrays of the same size and element type.

    Iterators:
        begin(): Returns an iterator to the first element of the array.
        end(): Returns an iterator to the element following the last element of the array.
        rbegin(): Returns a reverse iterator to the last element of the array.
        rend(): Returns a reverse iterator to the element preceding the first element of the array.
        cbegin(): Returns a const iterator to the first element of the array.
        cend(): Returns a const iterator to the element following the last element of the array.
        crbegin(): Returns a const reverse iterator to the last element of the array.
        crend(): Returns a const reverse iterator to the element preceding the first element of the array.
*/
#include <iostream>
#include <array>

using namespace std;
typedef array<int, 5>::const_iterator arr_it_const; // for const_iterator
typedef array<int, 5>::reverse_iterator arr_it_r; // for reverse_iterator
typedef array<int, 5>::iterator arr_it; // for iterator

int main() {
    // Example 1: Initializing and iterating through an array
    array<int, 5> arr = {1, 2, 3, 4, 5};
    for (arr_it it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    // Example 2: Using reverse iterators to iterate through an array backwards
    for (arr_it_r it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    // Example 3: Using const iterators to iterate through a const array
    const array<int, 5> const_arr = {1, 2, 3, 4, 5};
    for (arr_it_const it = const_arr.cbegin(); it != const_arr.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    // Example 4: Accessing elements of an array using the at() function
    cout << arr.at(2) << endl; // Access the element at index 2 of the array


    // Example 5: Accessing the first and last elements of an array using front() and back()
    cout << arr.front() << endl; // Access the first element of the array
    cout << arr.back() << endl; // Access the last element of the array


    // Example 6: Filling an array with a specific value using fill()
    arr.fill(0); // Fill the array with the value 0
    for (size_t x = 0; x < arr.size(); ++x) {
        cout << arr[x] << " ";
    }
    cout << endl;



    // Example 7: Swapping the contents of two arrays using swap()
    array<int, 5> arr2 = {6, 7, 8, 9, 10};
    arr.swap(arr2);
    for (arr_it it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (arr_it it = arr2.begin(); it != arr2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;



    // Example 8: max_size()
    constexpr size_t maxArraySize = arr.max_size();
    cout << "Max array size: " << maxArraySize << endl;



     // Example 9: empty()
    bool isEmpty = arr.empty();
    cout << "Is array empty? " << (isEmpty ? "Yes" : "No") << endl;



    // Example 10: Accessing and modifying array elements using the data() function
    int* ptr = arr.data();
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}
