// #include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;

class MergeSort {
private:
    void merge(int left, int mid, int right, vector<int> &arr) {
        vector<int> temp (right - left + 1);

        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int index = left; index <= right; index++) {
            arr[index] = temp[index - left];
        }
    }

    void mergeSort(int left, int right, vector<int> &arr) {
        if (right > left) {
            int mid = (right + left) / 2;
            mergeSort(left, mid, arr);
            mergeSort(mid + 1, right, arr);
            merge(left, mid, right, arr);
        }
    }
public:
    vector<int> sort(vector<int> &nums) {
        vector<int> arr = nums;
        int len = (int) arr.size();
        mergeSort(0, len - 1, arr);
        return arr;
    }
};

void printArray(vector<int> &nums) {
    for (auto n: nums) {
        cout << n << " ";
    }
    cout << endl;
}

/**
 * Time compelxity O(NlogN) 
 * where N = number of elements in the array
*/

int main() {
    vector<int> nums {4, 2, 1, 3, 6, 4, 5};
    
    MergeSort mst;
    auto sorted = mst.sort(nums);

    printArray(sorted);

    return 0;
}