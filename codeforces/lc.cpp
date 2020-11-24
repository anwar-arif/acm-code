#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int> &arr, int left, int right) {
    int i = left - 1, value = arr[right];
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < value) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = getPivot(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

void merge(vector<int> &arr, int left, int mid, int right) {
    int nl = mid - left + 1;
    int nr = right - mid;

    vector<int> x(nl), y(nr);
    for (int i = 0; i < nl; i++) x[i] = arr[left + i];
    for (int i = 0; i < nr; i++) y[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < nl && j < nr) arr[k++] = (x[i] <= y[j]) ? x[i++] : y[j++];
    while (i < nl) arr[k++] = x[i++];
    while (j < nr) arr[k++] = y[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {2, 1, 4, 3, 6, 5};
    mergeSort(arr, 0, (int) arr.size() - 1);

    for (int value: arr) {
        cout << value << " ";
    }
    cout << endl;

    set<pair<int, int>> s;
    s.insert({1, 2});
    for (auto p: s) {
        cout << p.first << " " << p.second << endl;
    }
    cout << (*s.begin()).first << " " << (*s.begin()).second << endl;
    return 0;
}
