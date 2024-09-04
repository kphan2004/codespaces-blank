#include <iostream>

int main() {

    // for (int i = 1; i <= 5; ++i) {
    //    std::cin >> i;
    //    std::cout << i << std::endl;
    //    std:: cout << i << "" <<std::endl;
    // }


   // int number, total;
   // total = 0;
   // std::cout << "Enter number: ";
   // std::cin >> number;
   // for (int i = 0; i <= number; i++) {
   // total += i;
   // } 
   // std::cout << "total =  " << total << std::endl;

int num;
int numberArray[11];
for (int i = 1; i <= 10; ++i) {
    std::cin >> num;
    numberArray[i] = num;
}
for (int i = 1; i <= 10; i++) {
if (numberArray[i] > 5) {
    std::cout << numberArray[i];
}
    
}
    return 0;
} 