#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
const Comparable & findMax (const vector<Comparable> & a) {
    int maxIndex = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[maxIndex] < a[i])
            maxIndex = i;

    }
    return a[maxIndex];

}

int main() {

    vector<int> list1 = {1, 5, 7, 17, 99, 85, 16};
    int max1 = findMax (a: list1);
    cout << "Max Value is " << max1 << endl;

    vector<float> list2 = {1.0, 5.55, 7.24, 17.49, 99.55, 85.99, 16.00};
    float max2 = findMax (a: list2);
    cout << "Max Value is " << max2 << endl;

    return 0;
}