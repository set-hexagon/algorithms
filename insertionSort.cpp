#include <iostream>
#include <vector>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

int main(int argc, char** argv) {
    std::vector<int> arr = {32,42,1,24,2,323,4,2,34,5};
    insertionSort(arr);

    for (auto elm : arr) std::cout << elm << " ";
    std::cout << std::endl;

    return 0;
}
