/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

#include <algorithm>

using namespace std;

namespace {
void heapify(vector<int>& arr, int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
}

void cArray::sortAscending() {
    int n = static_cast<int>(data.size());

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(data, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}
