#include <iostream>
#include <vector>

std::vector<int> quicksort(std::vector<int>& arr) {
    if (arr.size() < 2) {
        return arr;
    }
    int pivot = arr[0];
    std::vector<int> smaller, bigger;
    for (int i = 1; i < arr.size(); i++){
        int elm = arr[i];
        if (elm <= pivot) smaller.push_back(elm);
        else bigger.push_back(elm);
    }
    smaller = quicksort(smaller);
    bigger = quicksort(bigger);

    smaller.push_back(pivot);
    smaller.insert(smaller.end(),bigger.begin(),bigger.end());
    return smaller;
}

int main() {
    std::vector<int> arr = {32,42,1,24,2,323,4,2,34,5};
    std::vector<int> result = quicksort(arr);

    for (auto elm : result) std::cout << elm << " ";
    std::cout << std::endl;

    return 0;
}
