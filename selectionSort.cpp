#include <iostream>
#include <vector>

int findMin(std::vector<int>& arr, int a = 0, int b = -1) {
    if (b == -1) b = arr.size();
    int min = a;
    for (int i = a; i < b; i++) {
        min = (arr[i] < arr[min])? i : min;
    }
    return min;
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min = findMin(arr, i);
        std::swap(arr[min], arr[i]);
    }
}

int main(int argc, char** argv) {
    std::vector<int> arr = {32,42,1,24,2,323,4,2,34,5};
    selectionSort(arr);

    for (auto elm : arr) std::cout << elm << " ";
    std::cout << std::endl;

    return 0;
}
