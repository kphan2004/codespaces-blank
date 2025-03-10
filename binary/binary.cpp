#include <iostream>
#include <array>

using namespace std;

int binarySearch(const int arr[], int first, int last, int key) {
    if (last >= first) {
        int mid = first + (last - first) / 2;
        if (arr[mid] == key)
        return mid;
        if (arr[mid] > x)
        return binarySearch (arr, first, mid - 1, x );
        return binarySearch (arr, mid + 1, last, x);
    }
    return -1;
}