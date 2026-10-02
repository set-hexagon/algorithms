#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    for (int i = 0, j = 0; i < left.size() || j < right.size();) {
        if (i >= left.size()) {
            result.insert(result.end(), right.begin() + j, right.end());
            break;
        }
        else if (j >= right.size()) {
            result.insert(result.end(), left.begin() + i, left.end());
            break;
        }

        if (left[i] <= right[j]) result.push_back(left[i++]);
        else result.push_back(right[j++]);
    }

    return result;
}

std::vector<int> mergesort(const std::vector<int>& arr){
    int n = arr.size();
    if (n < 2) return arr;

    std::vector<int> left, right;
    for (int i = 0; i < n/2; i++) left.push_back(arr[i]);
    for (int i = n/2; i < n; i++) right.push_back(arr[i]);

    return merge(mergesort(left),mergesort(right));
}

int main() {
    std::vector<int> arr = {32,42,1,24,2,323,4,2,34,5};
    std::vector<int> result = mergesort(arr);

    for (auto elm : result) std::cout << elm << " ";
    std::cout << std::endl;

    return 0;
}
