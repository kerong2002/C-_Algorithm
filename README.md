# C++_Algorithm
<details> 
<summary><h2><b>Coding Style</b></h2></summary> 
<p>
<h3><b>小駝峰式命名法（lower camel case）：</b></h3>第一個單字以<b>小寫</b>字母開始；第二個單字的<b>首字母大寫</b>，例如：firstName、lastName。
<h3><b>大駝峰式命名法（upper camel case）：</b></h3>每一個單字的<b>首字</b>母都採用<b>大寫字母</b>，例如：FirstName、LastName、CamelCase，也被稱為<b>Pascal命名法</b>(英語：Pascal Case）

| 命名種類 | 命名法 | 範例 |
| :-: | :-: | :-: |
| 變數名稱 | camelCase | myVariableName |
| 函式名稱 | camelCase | myFunctionName() |
| 類別名稱 | PascalCase | MyClassName |
| 常數名稱 | 全大寫命名法 | MY\_CONSTANT\_VALUE |

</p>

<details>
<summary><h3><b>Code example</b></h3></summary>   
<p>
<a href="https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Coding_Style/Coding_Style.cpp">code link</a>
	
```c++
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

int main(int argc, char** argv) {
    
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

```
		
</p>

</details>
                       
</details> 
    
<details> 
<summary><h2><b>Pointer</b></h2></summary> 
    
| 特性 | 所有權轉移 | 引用計數 | 與裸指標互換 | 循環引用 | 空指標檢查 | 指向陣列 | 自定義刪除器 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| [unique_ptr](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Pointer/unique_ptr.cpp) | 是（move） | 否 | 支持 | 不支持 | 支持 | 支持 | 支持 |
| [shared_ptr](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Pointer/shared_ptr.cpp) | 是（copy） | 是 | 支持 | 支持 | 支持 | 支持 | 支持 |
| [weak_ptr](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Pointer/weak_ptr.cpp) | 否 | 是 | 支持 | 支持 | 支持 | 不支持 | 支持 |
	 
</details>

 <details> 
<summary><h2><b>Standard Template Library</b></h2></summary> 
    
| 容器 | 說明 |
| :-: | :-: |
| array | 固定大小的陣列 |
| deque | 雙向隊列 |
| forward_list | 單向鏈結串列 |
| list | 雙向鏈結串列 |
| vector | 可動態增減大小的陣列 |
| map | 關聯式容器，以 key-value 配對儲存 |
| set | 關聯式容器，以 key 儲存 |
| unordered_map | 關聯式容器，以 key-value 配對儲存，使用 hash table 實現 |
| unordered_set | 關聯式容器，以 key 儲存，使用 hash table 實現 |
| queue | 隊列 |

	 
</details>


<details> 
<summary><h2><b>Data Structure</b></h2></summary> 
    
| Data Structure |中文名稱| Access | Search | Insertion | Deletion | Space |
| :-: |:-: |:-: |:-: |:-: |:-: |:-: |
| [Array](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Array.cpp) |陣列 | O(1) | O(n) | O(n) | O(n) | O(n) |
| [Linked List](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Linked_List.cpp) |  連結串列 |O(n) | O(n) | O(1) | O(1) | O(n) |
| [Linked List(Plus)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Linked_List_Plus.cpp) |  連結串列 |O(n) | O(n) | O(1) | O(1) | O(n) |
| [Linked List(Circle)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Linked_List_Circle.cpp) |  連結串列 |O(n) | O(n) | O(1) | O(1) | O(n) |
| [Linked List(Sentinel)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Linked_List_Sentinel.cpp) |  連結串列 |O(n) | O(n) | O(1) | O(1) | O(n) |
| [Stack](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Stack.cpp) |堆疊 | O(n) | O(n) | O(1) | O(1) | O(n) |
| [Stack(Linked List)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Stack_Linked_List.cpp) |堆疊 | O(n) | O(n) | O(1) | O(1) | O(n) |
| [Queue](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Queue.cpp) |佇列 | O(n) | O(n) | O(1) | O(1) | O(n) |
| [Queue(Linked List)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/Queue_Linked_List.cpp) |環狀佇列 | O(1) | O(1) | O(1) | O(1) | O(n) |
| [Circular Queue](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Data_Structure/CircleQueue.cpp) |環狀佇列 | O(1) | O(1) | O(1) | O(1) | O(n) |

</details>

<details> 
<summary><h2><b>Evaluation of Expression</b></h2></summary> 


| 運算式 | 範例 | 時間複雜度 | 空間複雜度 |
| :-: |:-: | :-: | :-: |
| [Infix](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Expression/Infix.cpp)  | 2 + 3 | O(n) | O(n) |
| [Infix (Plus)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Expression/Infix_Plus.cpp)  | 2 + 3 | O(n) | O(n) |
| [Prefix](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Expression/Prefix.cpp)  | \+ 2 3 | O(n) | O(n) |
| [Postfix](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Expression/Postfix.cpp) | 2 3 + | O(n) | O(n) |

</details>


<details> 
<summary><h2><b>Matrix</b></h2></summary> 

| 矩陣類型 | 特點 |
| --- | --- |
| 普通矩陣（Matrix） | 元素沒有限制，一般使用二維數組（vector）存儲 |
| [稀疏矩陣（Sparse Matrix）](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Matrix/SparseMatrix.cpp) | 元素中大部分為0，通常使用壓縮存儲方式，可以節省空間 |
| 動態矩陣（Dynamic Matrix） | 可以動態調整大小的矩陣，通常使用vector<vector<T>>來實現 |
| 對稱矩陣（Symmetric Matrix） | 矩陣的上下三角形元素相等，可以使用一維數組（vector）存儲，以節省空間 |
| 上三角矩陣（Upper Triangular Matrix） | 矩陣的下三角形元素均為0，可以使用一維數組（vector）存儲，以節省空間 |
| 下三角矩陣（Lower Triangular Matrix） | 矩陣的上三角形元素均為0，可以使用一維數組（vector）存儲，以節省空間 | 
| 布爾矩陣（Boolean Matrix） | 矩陣元素只包含0和1，通常用於表示邏輯運算表。 |
| 前綴和矩陣（Prefix Sum Matrix） | 計算矩陣中某一子矩陣的和，可以使用前綴和矩陣來優化計算速度。 |
| 循環矩陣（Circular Matrix） | 矩陣中每一行的最後一個元素與下一行的第一個元素相鄰，可以用一維數組（vector）或二維數組（vector）存儲。 |
| [Toeplitz矩陣（Toeplitz Matrix）](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Matrix/ToeplitzMatrix.cpp) | 矩陣中每一條對角線上的元素相等，可以使用一維數組（vector）存儲，以節省空間。 |
    
</details>

<details> 
<summary><h2><b>Search</b></h2></summary> 

 
| 演算法 | 時間複雜度 | 空間複雜度 |
| :-: | :-: | :-: |
| [Binary Search](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Serach/BinarySearch.cpp)| O(log n) | O(1) |
| [Linear Search](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Serach/LinearSearch.cpp) | O(n) | O(1) |
| [Jump Search](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Serach/JumpSearch.cpp) | O(√n) | O(1) |
    
</details>

<details> 
 <summary><h2><b>Sort</b></h2></summary>  
 
| 排序演算法 | 時間複雜度（平均） | 時間複雜度（最壞） | 空間複雜度 |
| :--: | :--: | :--: | :-: |
| [Bubble Sort](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Sort/BubbleSort.cpp) | O(n^2) | O(n^2) | O(1) |
| Insertion Sort | O(n^2) | O(n^2) | O(1) |
| [Selection Sort](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Sort/SelectionSort.cpp) | O(n^2) | O(n^2) | O(1) |
| [Merge Sort](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Sort/MergeSort.cpp) | O(n log n) | O(n log n) | O(n) |
| [Quick Sort](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Sort/QuickSort.cpp) | O(n log n) | O(n^2) | O(log n) |
| Heap Sort | O(n log n) | O(n log n) | O(1) |
| [Counting Sort](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Sort/CountingSort.cpp) | O(n + k) | O(n + k) | O(k) |
| Radix Sort | O(d(n+k)) | O(d(n+k)) | O(n+k) |
    
</details>

<details> <summary><h2><b>Graph Algorithm</b></h2></summary>


| 演算法 | 時間複雜度 | 空間複雜度 | 應用 |
| :-: | :-: | :-: | :-: |
| [DFS (Depth-First Search)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Graph_Algorithm/DFS.cpp) | O(V+E) | O(V) | 遍歷整張圖，尋找連通分量，拓撲排序 |
| [BFS (Breadth-First Search)](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Graph_Algorithm/BFS.cpp) | O(V+E) | O(W) | 遍歷整張圖，最短路徑，尋找連通分量 |
| Dijkstra | O((V+E)logV) | O(V) | 求最短路徑 |
| Bellman-Ford | O(VE) | O(V) | 求最短路徑 |
| Floyd-Warshall | O(V^3) | O(V^2) | 求任意兩點之間的最短路徑 |
| Prim | O((V+E)logV) | O(V) | 求最小生成樹 |
| Kruskal | O(ElogE) | O(E) | 求最小生成樹 |
| Tarjan | O(V+E) | O(V) | 求圖中的強連通分量 |
| Kosaraju | O(V+E) | O(V) | 求圖中的強連通分量 |
| Topological Sort | O(V+E) | O(V) | 拓撲排序 |
| Bridges in a graph | O(V+E) | O(V) | 尋找橋 |
| Articulation points in a graph | O(V+E) | O(V) | 尋找割點 |

</details>


<details> 
 <summary><h2><b>String</b></h2></summary>  


| 演算法 | 時間複雜度 | 空間複雜度 |
| :---: | :------: | :------: |
| [KMP](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/Sring/KMP.cpp) | O(n+m) | O(m) |
| Boyer-Moore | O(nm) | O(m) |
| Rabin-Karp | O(nm) | O(1) |
| Z Algorithm | O(n) | O(n) |
| Suffix Array | O(nlogn) | O(n) |
| Trie | O(m*len_alph) | O(m*len_alph) |
| Aho-Corasick | O(n+m+k) | O(m\*len_alph) |
| Manacher | O(n) | O(n) |
| Longest Common Substring | O(mn) | O(mn) |
| Longest Common Subsequence | O(mn) | O(mn) |
| Edit Distance | O(mn) | O(mn) |

- n代表主字串的長度
- m代表子字串的長度
- k代表匹配次數
- len_alph代表字元集合的大小

</details>
