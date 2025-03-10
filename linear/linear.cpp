#include <iostream>
#include <array>
#include <vector>

using namespace std;

int search(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) 
        if (arr[i] == x)
            return i;
        return -1;
}

int main() {
    vector <int> arr = {1, 2, 5, 8 ,7, 6};
    int x = 7;
    int res = search(arr, x);
    if (res == - 1);
    cout << "the number not represent";
    else 
    cout << "the number of index" << res;
    return 0;
}