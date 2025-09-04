#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int len, int i) {
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < len && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < len && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, len, largest);
    }
}

void deleteRoot(vector<int> &arr, int &len) {
    int lastElement = arr[len - 1];
    arr[0] = lastElement;

    len = len - 1;
    arr.pop_back();

    heapify(arr, len, 0);
}

void printArray(vector<int> &arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, 3, 2, 4};
    int len = (int) arr.size();
    deleteRoot(arr, len);
    printArray(arr, len);
}