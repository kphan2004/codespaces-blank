#include <iostream>
#include <list>
#include <vector>
#include <string>


using namespace std;

int main() {

    vector<int> list1 = {1, 2, 4, 6, 7, 9};

    for (int i = 0; i < list1.size(); i++) {
        cout << list1[i] << " ";
    }
    cout << endl;

    for (vector <int>::iterator itr =list1.begin(); itr != list1.end(); itr++) {
        cout << *itr << " ";

    }
        cout << endl;

    /*if (myList.empty()) {
        cout << "My list is empty " << endl;
    }
    else {
        cout << "My list is not empty" << endl;
    }
    */    
    
    
    list<int> myList;
    myList.push_back(45);
    myList.push_front(35);
    myList.push_front(25);
    myList.push_back(99);

    for (list <int>::iterator itr =myList.begin(); itr != myList.end(); itr++) {
        if (*itr == 10) {
            cout << "found 10" << endl;
        }
    }
    
    /*if (myList.empty()) {
        cout << "My list is empty " << endl;
    }
    else {
        cout << "My list is not empty" << endl;
    }
    */


    return 0;
}