//2023/05/14 kerong
/*
    Data_Structure : Array(STL)
     Time complexity => O(n)
    Space complexity => O(n)

    // Capacity:
    // size(): Returns the number of elements in the vector.
    // max_size(): Returns the maximum number of elements that the vector can hold.
    // resize(): Changes the size of the vector.
    // capacity(): Returns the size of the allocated storage capacity.
    // empty(): Checks whether the vector is empty, i.e., whether its size is 0.
    // reserve(): Requests a change in the capacity of the vector.
    // shrink_to_fit(): Shrinks the capacity of the vector to fit its size.

    // Element access:
    // operator[]: Accesses the element at the specified position.
    // at(): Accesses the element at the specified position and checks if it is valid.
    // front(): Returns a reference to the first element in the vector.
    // back(): Returns a reference to the last element in the vector.
    // data(): Returns a pointer to the first element of the vector.

    // Modifiers:
    // assign(): Assigns new contents to the vector.
    // push_back(): Adds an element at the end of the vector.
    // pop_back(): Removes the last element from the vector.
    // insert(): Inserts elements into the vector.
    // erase(): Erases elements from the vector.
    // swap(): Swaps the contents of two vectors of the same size and element type.
    // clear(): Clears the contents of the vector.
    // emplace(): Constructs and inserts an element into the vector.
    // emplace_back(): Constructs and adds an element at the end of the vector.

    // Iterators:
    // begin(): Returns an iterator to the first element of the vector.
    // end(): Returns an iterator to the element following the last element of the vector.
    // rbegin(): Returns a reverse iterator to the last element of the vector.
    // rend(): Returns a reverse iterator to the element preceding the first element of the vector.
    // cbegin(): Returns a const iterator to the first element of the vector.
    // cend(): Returns a const iterator to the element following the last element of the vector.
    // crbegin(): Returns a const reverse iterator to the last element of the vector.
    // crend(): Returns a const reverse iterator to the element preceding the first element of the vector.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};

    // Capacity
    cout << "Size: " << myVector.size() << endl;
    cout << "Max Size: " << myVector.max_size() << endl;

    myVector.resize(10);
    cout << "Size after resize: " << myVector.size() << endl;
    cout << "Capacity: " << myVector.capacity() << endl;
    cout << "Is Empty? " << (myVector.empty() ? "Yes" : "No") << endl;

    myVector.reserve(20);
    cout << "Capacity after reserve: " << myVector.capacity() << endl;

    myVector.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << myVector.capacity() << endl;

    // Element Access
    cout << "First Element: " << myVector.front() << endl;
    cout << "Last Element: " << myVector.back() << endl;
    cout << "Element at Index 2: " << myVector.at(2) << endl;

    // Accessing data using data()
    int* dataPtr = myVector.data();

    // Printing the elements using the data pointer
    for (size_t i = 0; i < myVector.size(); i++) {
        cout << *(dataPtr + i) << " ";
    }
    cout << endl;


    // Modifiers

    vector<int> otherVector = {1, 2, 3, 4, 5};
    myVector.assign(otherVector.begin(), otherVector.end());
    cout << "Assign: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    myVector.push_back(6);
    cout << "Push_back: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    myVector.pop_back();
    cout << "Pop_back: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    myVector.insert(myVector.begin() + 2, 10);
    cout << "Insert: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    myVector.erase(myVector.begin() + 1);
    cout << "Erase: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> anotherVector = {7, 8, 9};
    myVector.swap(anotherVector);
    cout << "Swap: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    otherVector.clear();
    cout << "Clear: ";
    for (int num : otherVector) {
        cout << num << " ";
    }
    cout << endl;

    myVector.emplace(myVector.begin() + 1, 20);
    cout << "Emplace: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    myVector.emplace_back(30);
    cout << "Emplace_back: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;


    // Iterators
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (vector<int>::reverse_iterator rit = myVector.rbegin(); rit != myVector.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    for (vector<int>::const_iterator cit = myVector.cbegin(); cit != myVector.cend(); ++cit) {
        cout << *cit << " ";
    }
    cout << endl;

    for (vector<int>::const_reverse_iterator crit = myVector.crbegin(); crit != myVector.crend(); ++crit) {
        cout << *crit << " ";
    }
    cout << endl;



    return 0;
}
