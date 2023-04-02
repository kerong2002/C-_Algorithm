# C++_Algorithm
<details> 
<summary><h2><b>Matrix</b></h2></summary> 

| 矩陣類型 | 特點 |
| --- | --- |
| 普通矩陣（Matrix） | 元素沒有限制，一般使用二維數組（vector）存儲 |
| [稀疏矩陣（Sparse Matrix）](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/SparseMatrix.cpp) | 元素中大部分為0，通常使用壓縮存儲方式，可以節省空間 |
| 動態矩陣（Dynamic Matrix） | 可以動態調整大小的矩陣，通常使用vector<vector<T>>來實現 |
| 對稱矩陣（Symmetric Matrix） | 矩陣的上下三角形元素相等，可以使用一維數組（vector）存儲，以節省空間 |
| 上三角矩陣（Upper Triangular Matrix） | 矩陣的下三角形元素均為0，可以使用一維數組（vector）存儲，以節省空間 |
| 下三角矩陣（Lower Triangular Matrix） | 矩陣的上三角形元素均為0，可以使用一維數組（vector）存儲，以節省空間 | 
| 布爾矩陣（Boolean Matrix） | 矩陣元素只包含0和1，通常用於表示邏輯運算表。 |
| 前綴和矩陣（Prefix Sum Matrix） | 計算矩陣中某一子矩陣的和，可以使用前綴和矩陣來優化計算速度。 |
| 循環矩陣（Circular Matrix） | 矩陣中每一行的最後一個元素與下一行的第一個元素相鄰，可以用一維數組（vector）或二維數組（vector）存儲。 |
| Toeplitz矩陣（Toeplitz Matrix） | 矩陣中每一條對角線上的元素相等，可以使用一維數組（vector）存儲，以節省空間。 |
    
</details>
<details> 
<summary><h2><b>Search</b></h2></summary> 

 
| 演算法 | 時間複雜度 | 空間複雜度 |
| :-: | :-: | :-: |
| [Binary Search](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/BinarySearch.cpp) | O(log n) | O(1) |
| Linear Search | O(n) | O(1) |
| Jump Search | O(√n) | O(1) |
    
</details>

<details> 
 <summary><h2><b>Sort</b></h2></summary>  
 
| 排序演算法 | 時間複雜度（平均） | 時間複雜度（最壞） | 空間複雜度 |
| :--: | :--: | :--: | :-: |
| Bubble Sort | O(n^2) | O(n^2) | O(1) |
| Insertion Sort | O(n^2) | O(n^2) | O(1) |
| [Selection Sort](https://github.com/kerong2002/CPlusPlus_Algorithm/blob/main/SelectionSort.cpp) | O(n^2) | O(n^2) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n^2) | O(log n) |
| Heap Sort | O(n log n) | O(n log n) | O(1) |
| Counting Sort | O(n + k) | O(n + k) | O(k) |
| Radix Sort | O(d(n+k)) | O(d(n+k)) | O(n+k) |
    
</details>
