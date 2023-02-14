#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2) {
    vector<int> results;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr2[j] > arr1[i]) {
            results.push_back(arr1[i]);
            i++;
        } else {
            results.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        results.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        results.push_back(arr2[j]);
        j++;
    }
    return results;
}

vector<int> mergeSort(vector<int> arr) {
    if (arr.size() <= 1) return arr;
    int mid = arr.size() / 2;
    vector<int> left = mergeSort(vector<int>(arr.begin(), arr.begin() + mid));
    vector<int> right = mergeSort(vector<int>(arr.begin() + mid, arr.end()));
    return merge(left, right);
}

int main() {
    vector<int> sorted = mergeSort({0,8,52,4,32,6,7,1,5,7,23,265,0,2,65,23,26,0});
    for (int i : sorted) cout << i << " ";
    return 0;
}
