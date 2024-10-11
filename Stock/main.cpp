#include <iostream>
#include "Stock.h"

int main() {

    Stock myStock("Kiet Phan", 21342, 233, 34.6);

    std::cout << "Owner: " << myStock.getOwnerName() << std::endl;
    std::cout << "Account Number: " << myStock.getAccountNumber() << std::endl;
    std::cout << "Number Of Shares: " << myStock.getNumberOfShares() << std::endl;
    std::cout << "Price Per Share: $" << myStock.getPricePerShare() << std::endl;
    std::cout << "Portfolio Value: $" << myStock.getValueOfPortfolio() << std::endl;

    myStock.buyShares(50);
    std::cout << "\nAfter buying 50 shares:" << std::endl;
    std::cout << "Number of Shares: " << myStock.getNumberOfShares() << std::endl;
    std::cout << "Portfolio Value: $" << myStock.getValueOfPortfolio() << std::endl;

    myStock.sellShares(150);

    return 0;
}