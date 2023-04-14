//2022/04/14 kerong
/*
    Algorithm : Jump Search
     Time complexity => O(sqrt(n))
    Space complexity => O(1)
*/
#include <iostream>
#include <cmath>
using namespace std;

int JumpSearch(int arr[], int find, int max_size){
	int jump = static_cast<int> (sqrt(max_size));
	int step = jump;
	int index = 0;

	while(arr[min(step, max_size) - 1] < find){
		index = step;
		step += jump;
		if(index >= max_size){
			return -1;
		}
	}

	while(arr[index] < find){
		index++;
		if(index == min(step, max_size)){
			return -1;
		}
	}

	if(arr[index] == find){
		return index;
	}
	else{
		return -1;
	}
}
int main(){
	int arr[] = {1, 3, 4, 6, 8, 9, 10, 11, 14};
	int index = JumpSearch(arr, 8, sizeof(arr) / sizeof(arr[0]));

	if(index == -1){
		cout << "Element not found" << endl;
	}
	else{
		cout << "Element found at index " << index << endl;
	}
	return 0;
}
